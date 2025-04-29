//
// Created by Yang Liu on 3/26/25.
//
#include "CommandProcessor.h"

#include "MyListener/MyListener.h"
#include "SQLStatement/DDLStatement/include/ShowDatabases.h"
#include "SQLStatement/DDLStatement/include/ShowTables.h"
#include "log.h"

void executeSql(const std::string &statement) {
  try {
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
    if (listener.IsSyntaxError()) {
      // TODO: Do something about the syntax error
      std::cout << "We are doing something about syntax error!" << std::endl;
      listener.SetSyntaxError(false);
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