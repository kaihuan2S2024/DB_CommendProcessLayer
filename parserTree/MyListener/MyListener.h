//
// Created by JYJ on 2023/7/3.
//

#ifndef SRCFOLDER_PARSERTREE_MYLISTENER_H_
#define SRCFOLDER_PARSERTREE_MYLISTENER_H_

#include <iostream>
#include <queue>
#include <vector>

#include "MySqlLexer.h"
#include "MySqlParser.h"
#include "MySqlParserBaseListener.h"
#include "MySqlParserBaseVisitor.h"
#include "SQLStatement/DDLStatement/include/CreateDbStatement.h"
#include "SQLStatement/DDLStatement/include/CreateTableStatement.h"
#include "SQLStatement/DDLStatement/include/DropDbStatement.h"
#include "SQLStatement/DDLStatement/include/DropTableStatement.h"
#include "SQLStatement/DDLStatement/include/UseDBStatement.h"
#include "SQLStatement/DMLStatement/include/DeleteStatement.h"
#include "SQLStatement/DMLStatement/include/InsertStatement.h"
#include "SQLStatement/DMLStatement/include/Join.h"
#include "SQLStatement/DMLStatement/include/SelectStatement.h"
#include "SQLStatement/DMLStatement/include/UpdateStatement.h"
#include "SQLStatement/SqlStatement.h"
#include "antlr4-runtime.h"
#include "include/ParserTree.h"
// include query optimization class
#include "Optimizer.h"

using namespace antlrcpptest;
using namespace antlr4;

/***
 * SQL_TYPE:
 * 0: SELECT
 * 1: INSERT
 * 2: UPDATE
 * 3: DELETE
 * 4: CREATE DB
 * 5: DROP DB
 * 6: CREATE TABLE
 * 7: DROP TABLE
 * 8: ALTER TABLE
 * */

class MyListener : public MySqlParserBaseListener {
 private:
  // select statement
  bool SYNTAX_ERROR = false;
  bool FIRST_STATEMENT_ENCOUNTER = true;
  ParserTree *parserTree = new ParserTree();
  std::string checkIfContainsFunction(std::string str);
  std::string statement;

 public:
  ParserTree *GetParserTree() const;
  void SetParserTree(ParserTree *parser_tree);
  MyListener() = default;
  ~MyListener();
  void destroyTree();
  void SetStatement(const std::string &statement);
  const std::string &GetStatement() const;
  void visitErrorNode(antlr4::tree::ErrorNode *node) override;
  void enterSqlStatement(MySqlParser::SqlStatementContext *ctx) override;
  void enterSimpleSelect(MySqlParser::SimpleSelectContext *ctx) override;
  void enterSelectElements(MySqlParser::SelectElementsContext *ctx) override;
  void enterCreateDatabase(MySqlParser::CreateDatabaseContext *ctx) override;
  bool IsSyntaxError() const;
  void SetSyntaxError(bool syntax_error);
  void enterPredicateExpression(
      MySqlParser::PredicateExpressionContext *ctx) override;
  SelectStatement *parseSelectStatement(antlr4::tree::ParseTree *ctx);
  std::vector<ParserTreeNode *> parseSelectList(antlr4::tree::ParseTree *ctx);
  std::vector<ParserTreeNode *> parseTableSource(tree::ParseTree *ctx);
  ParserTreeNode *parseCondition(antlr4::tree::ParseTree *ctx);
  ParserTreeNode *getAlias(tree::ParseTree *ctx, int possible_type);
  UpdateStatement *parseUpdateStatement(tree::ParseTree *ctx);
  std::vector<ParserTreeNode *> parseUpdateList(tree::ParseTree *ctx);
  void enterUpdateStatement(MySqlParser::UpdateStatementContext *ctx) override;
  CreateDbStatement *parseCreateDbStatement(tree::ParseTree *ctx);
  void enterDropDatabase(MySqlParser::DropDatabaseContext *ctx) override;
  DropDbStatement *parseDropDbStatement(tree::ParseTree *ctx);
  void enterDropTable(MySqlParser::DropTableContext *ctx) override;
  DropTableStatement *parseDropTableStatement(tree::ParseTree *ctx);
  void enterColumnCreateTable(
      MySqlParser::ColumnCreateTableContext * /*ctx*/) override;
  CreateTableStatement *parseCreateTableStatement(tree::ParseTree *ctx);
  void testStructure(tree::ParseTree *ctx);
  InsertStatement *parseInsertStatement(tree::ParseTree *ctx);
  void enterInsertStatement(MySqlParser::InsertStatementContext *ctx) override;
  std::vector<ParserTreeNode *> parseInsertFields(tree::ParseTree *ctx);
  std::vector<ParserTreeNode *> parseInsertValues(antlr4::tree::ParseTree *ctx);
  ParserTreeNode *parseInsertSubSet(tree::ParseTree *ctx);
  void enterDeleteStatement(MySqlParser::DeleteStatementContext *) override;
  DeleteStatement *parseDeleteStatement(tree::ParseTree *ctx);
  UseDBStatement *parseUseDbStatement(tree::ParseTree *ctx);
  std::vector<Join *> parseJoin(tree::ParseTree *ctx);
  static std::string toUpperCase(const std::string &input);
};

#endif  // SRCFOLDER_PARSERTREE_MYLISTENER_H_