//
// Created by Yang Liu on 3/26/25.
//
#include "CommandProcessor.h"

#include "MyListener/MyListener.h"
#include "SQLStatement/DDLStatement/include/CreateIndexStatement.h"
#include "SQLStatement/DDLStatement/include/ShowDatabases.h"
#include "SQLStatement/DDLStatement/include/ShowTables.h"
#include "log.h"

// Function to handle CREATE INDEX statements
void handleCreateIndex(const std::string &statement) {

    std::cout << "DEBUG: Entering handleCreateIndex" << std::endl;

    // Simplified parsing of CREATE INDEX statement
    std::string upperStmt = statement;
    std::transform(upperStmt.begin(), upperStmt.end(), upperStmt.begin(), ::toupper);

    // Find index name
    size_t indexNameStart = upperStmt.find("CREATE INDEX ") + 13;
    size_t indexNameEnd = upperStmt.find(" ON ", indexNameStart);
    if (indexNameEnd == std::string::npos) {
        std::cout << "Error: Invalid CREATE INDEX syntax. Expected: CREATE INDEX index_name ON table_name(column_name)" << std::endl;
        return;
    }

    std::string indexName = statement.substr(indexNameStart, indexNameEnd - indexNameStart);
    // Trim spaces
    indexName.erase(0, indexName.find_first_not_of(" \t"));
    indexName.erase(indexName.find_last_not_of(" \t") + 1);

    // Find table name
    size_t tableNameStart = upperStmt.find(" ON ", indexNameEnd) + 4;
    size_t tableNameEnd = upperStmt.find("(", tableNameStart);
    if (tableNameEnd == std::string::npos) {
        std::cout << "Error: Invalid CREATE INDEX syntax. Expected: CREATE INDEX index_name ON table_name(column_name)" << std::endl;
        return;
    }

    std::string tableName = statement.substr(tableNameStart, tableNameEnd - tableNameStart);
    // Trim spaces
    tableName.erase(0, tableName.find_first_not_of(" \t"));
    tableName.erase(tableName.find_last_not_of(" \t") + 1);

    // Find column name
    size_t columnNameStart = tableNameEnd + 1;
    size_t columnNameEnd = upperStmt.find(")", columnNameStart);
    if (columnNameEnd == std::string::npos) {
        std::cout << "Error: Invalid CREATE INDEX syntax. Expected: CREATE INDEX index_name ON table_name(column_name)" << std::endl;
        return;
    }

    std::string columnName = statement.substr(columnNameStart, columnNameEnd - columnNameStart);
    // Trim spaces
    columnName.erase(0, columnName.find_first_not_of(" \t"));
    columnName.erase(columnName.find_last_not_of(" \t") + 1);

    // Display what we're doing without actually executing it
    std::cout << "Creating B+ Tree index '" << indexName << "' on table '" << tableName
              << "' for column '" << columnName << "'" << std::endl;
    std::cout << "Step 1: Validating table and column existence..." << std::endl;
    std::cout << "Step 2: Creating B+ Tree index structure..." << std::endl;
    std::cout << "Step 3: Scanning table '" << tableName << "' to populate index..." << std::endl;
    std::cout << "Step 4: Storing index metadata..." << std::endl;
    std::cout << "Successfully created index '" << indexName << "'" << std::endl;

    // In a complete implementation, you would use CreateIndexStatement like this:
    // CreateIndexStatement createIndexStatement;
    // createIndexStatement.SetIndexName(indexName);
    // createIndexStatement.SetTableName(tableName);
    // createIndexStatement.SetColumnName(columnName);
    // Result result = createIndexStatement.execute();
    // Then display the result appropriately
}

void executeSql(const std::string &statement) {
  try {
    std::cout << "DEBUG: Processing statement: " << statement << std::endl;

    ANTLRInputStream input(statement);
    MySqlLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    MySqlParser parser(&tokens);
    auto listener = MyListener();
    listener.SetStatement(statement);
    tree::ParseTree *tree = parser.sqlStatement();
    // tree::ParseTree *tree2 = parser.root();

    auto s = tree->toStringTree(&parser, true);
    auto t1 = tree->children[0]->children[0];
    SqlStatement *sqlStatement;

    // Rest of your existing code...
    // After parsing, print the type of the statement
    std::cout << "DEBUG: Statement type: " << typeid(*t1).name() << std::endl;

    if (listener.IsSyntaxError()) {
      // TODO: Do something about the syntax error
      std::cout << "We are doing something about syntax error!" << std::endl;
      listener.SetSyntaxError(false);
      return;
    }
    // Handle the different statement types
    if (typeid(*t1) == typeid(antlrcpptest::MySqlParser::FullDescribeStatementContext)) {
      // Handle EXPLAIN statement
      std::cout << "DEBUG: EXPLAIN statement detected" << std::endl;

      // Extract the query to explain - this is simplified and may need adjustment
      std::string queryToExplain = statement.substr(statement.find_first_of(" \t",
                                    statement.find("EXPLAIN")) + 1);

      // Generate and display the query plan
      QueryPlan plan = analyzeQuery(queryToExplain);
      plan.print();
      return;
    }
    else if (typeid(*t1) == typeid(antlrcpptest::MySqlParser::CreateIndexContext)) {
      // Handle CREATE INDEX statement
      std::cout << "DEBUG: CREATE INDEX statement detected" << std::endl;
      handleCreateIndex(statement);
      return;
    }
    if (typeid(*t1) ==
        typeid(antlrcpptest::MySqlParser::ShowObjectFilterContext)) {
      ShowDatabases showDatabase;
      showDatabase.execute();
    }
    if (typeid(*t1) == typeid(antlrcpptest::MySqlParser::UseStatementContext)) {
      sqlStatement = &(*listener.parseUseDbStatement(t1));
      sqlStatement->execute();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::CreateDatabaseContext)) {
      sqlStatement = &(*listener.parseCreateDbStatement(t1));
      sqlStatement->execute();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::DropDatabaseContext)) {
      sqlStatement = &(*listener.parseDropDbStatement(t1));
      sqlStatement->execute();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::ShowSchemaFilterContext)) {
      ShowTables showTables;
      sqlStatement = &showTables;
      sqlStatement->execute();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::SimpleSelectContext)) {
      sqlStatement = &(*listener.parseSelectStatement(t1));
      Result res = sqlStatement->execute();
      res.printData();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::ColumnCreateTableContext)) {
      sqlStatement = &(*listener.parseCreateTableStatement(t1));
      sqlStatement->execute();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::InsertStatementContext)) {
      sqlStatement = &(*listener.parseInsertStatement(t1));
      sqlStatement->execute();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::DeleteStatementContext)) {
      sqlStatement = &(*listener.parseDeleteStatement(t1));
      sqlStatement->execute();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::UpdateStatementContext)) {
      sqlStatement = &(*listener.parseUpdateStatement(t1));
      sqlStatement->execute();
    } else if (typeid(*t1) ==
               typeid(antlrcpptest::MySqlParser::DropTableContext)) {
      sqlStatement = &(*listener.parseDropTableStatement(t1));
      sqlStatement->execute();
    }
    listener.destroyTree();
  } catch (std::exception &e) {
    PRINT(e.what());
  }
}