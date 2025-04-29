//
// Created by JYJ on 2023/8/9.
//
#include <iostream>
//../runtime/src/antlr4-runtime.h
#include "MyListener/MyListener.h"
#include "antlr4-runtime.h"
#include "gtest/gtest.h"

void setUpTestCase(MyListener* listener, const std::string& statement) {
  ANTLRInputStream input(statement);
  MySqlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  MySqlParser parser(&tokens);
  tree::ParseTree* tree = parser.sqlStatement();
  tree::ParseTreeWalker::DEFAULT.walk(listener, tree);
}

TEST(SelectTest, normalSelect) {
  const std::string statement = "SELECT * FROM table1";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* selectStatement = static_cast<SelectStatement*>(newTree->getRootNode());
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "table1");
}

TEST(SelectTest, selectWithCondition) {
  const std::string statement = "SELECT * FROM table1 WHERE a = 1";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* selectStatement = static_cast<SelectStatement*>(newTree->getRootNode());
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "table1");
  EXPECT_EQ(selectStatement->GetCondition()->GetValue(), "a=1");
  Condition* cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "a");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "1");
}

TEST(SelectTest, testWithSubQuery) {
  std::string statement =
      "SELECT * FROM table1 WHERE a IN (SELECT * FROM table2)";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* selectStatement = static_cast<SelectStatement*>(newTree->getRootNode());
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "table1");
  EXPECT_EQ(selectStatement->GetCondition()->GetValue(),
            "aIN(SELECT*FROMtable2)");
  Condition* cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "IN");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "a");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "SELECT*FROMtable2");
}

TEST(UpdateTest, normalUpdate) {
  std::string statement = "UPDATE table1 SET a = 1";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* updateStatement = static_cast<UpdateStatement*>(newTree->getRootNode());
  EXPECT_EQ(updateStatement->GetUpdateList().size(), 1);
  EXPECT_EQ(updateStatement->GetUpdateList()[0]->GetValue(), "=");
  EXPECT_EQ(updateStatement->GetUpdateList()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(
      updateStatement->GetUpdateList()[0]->getChildrenNodes()[0]->GetValue(),
      "a");
  EXPECT_EQ(
      updateStatement->GetUpdateList()[0]->getChildrenNodes()[1]->GetValue(),
      "1");
  EXPECT_EQ(updateStatement->GetTableSource()->GetValue(), "table1");
}

TEST(UpdateTest, multipleUpdate) {
  const std::string statement = "UPDATE table1 SET a = 1, b = 2";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* updateStatement = static_cast<UpdateStatement*>(newTree->getRootNode());
  EXPECT_EQ(updateStatement->GetUpdateList().size(), 2);
  EXPECT_EQ(updateStatement->GetUpdateList()[0]->GetValue(), "=");
  EXPECT_EQ(updateStatement->GetUpdateList()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(
      updateStatement->GetUpdateList()[0]->getChildrenNodes()[0]->GetValue(),
      "a");
  EXPECT_EQ(
      updateStatement->GetUpdateList()[0]->getChildrenNodes()[1]->GetValue(),
      "1");
  EXPECT_EQ(updateStatement->GetUpdateList()[1]->GetValue(), "=");
  EXPECT_EQ(updateStatement->GetUpdateList()[1]->getChildrenNodes().size(), 2);
  EXPECT_EQ(
      updateStatement->GetUpdateList()[1]->getChildrenNodes()[0]->GetValue(),
      "b");
  EXPECT_EQ(
      updateStatement->GetUpdateList()[1]->getChildrenNodes()[1]->GetValue(),
      "2");
  EXPECT_EQ(updateStatement->GetTableSource()->GetValue(), "table1");
}

TEST(UpdateTest, updateWithSubquery) {
  std::string statement =
      "UPDATE table1 SET column1 = value1, column2 = value2 WHERE column3 IN "
      "(SELECT column4 FROM table2 WHERE column5 = 'some_value');";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* updateStatement = static_cast<UpdateStatement*>(newTree->getRootNode());
  EXPECT_EQ(updateStatement->GetUpdateList().size(), 2);
  EXPECT_EQ(updateStatement->GetCondition()->GetValue(),
            "column3IN(SELECTcolumn4FROMtable2WHEREcolumn5='some_value')");
  EXPECT_EQ(updateStatement->GetUpdateList()[0]->GetValue(), "=");
  EXPECT_EQ(updateStatement->GetUpdateList()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(
      updateStatement->GetUpdateList()[0]->getChildrenNodes()[0]->GetValue(),
      "column1");
  EXPECT_EQ(
      updateStatement->GetUpdateList()[0]->getChildrenNodes()[1]->GetValue(),
      "value1");
  EXPECT_EQ(updateStatement->GetUpdateList()[1]->GetValue(), "=");
  EXPECT_EQ(updateStatement->GetUpdateList()[1]->getChildrenNodes().size(), 2);
  EXPECT_EQ(
      updateStatement->GetUpdateList()[1]->getChildrenNodes()[0]->GetValue(),
      "column2");
  EXPECT_EQ(
      updateStatement->GetUpdateList()[1]->getChildrenNodes()[1]->GetValue(),
      "value2");
  EXPECT_EQ(updateStatement->GetTableSource()->GetValue(), "table1");
  Condition* cond = updateStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "IN");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "column3");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "SELECTcolumn4FROMtable2WHEREcolumn5='some_value'");
}

TEST(DeleteTest, normalDelete) {
  const std::string statement = "DELETE FROM table1";
  MyListener listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* deleteStatement = static_cast<DeleteStatement*>(newTree->getRootNode());
  EXPECT_EQ(deleteStatement->GetTableSource()->GetValue(), "table1");
}

TEST(DeleteTest, deleteWithCondition) {
  const std::string statement = "DELETE FROM table1 WHERE a = 1";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* deleteStatement = static_cast<DeleteStatement*>(newTree->getRootNode());
  EXPECT_EQ(deleteStatement->GetTableSource()->GetValue(), "table1");
  EXPECT_EQ(deleteStatement->GetCondition()->GetValue(), "a=1");
  Condition* cond = deleteStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "a");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "1");
}

TEST(InsertTest, normalInsert) {
  const std::string statement =
      "INSERT INTO students (first_name) VALUES ('John');";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  const auto* insertStatement =
      static_cast<InsertStatement*>(newTree->getRootNode());
  EXPECT_EQ(insertStatement->GetTableSource()->GetValue(), "students");
  EXPECT_EQ(insertStatement->GetColumnList().size(), 1);
  EXPECT_EQ(insertStatement->GetColumnList()[0]->GetValue(), "first_name");
  EXPECT_EQ(insertStatement->GetValueList().size(), 1);
  EXPECT_EQ(insertStatement->GetValueList()[0]->GetValue(), "'John'");
}

TEST(InsertTest, insertWithMultipleValues) {
  const std::string statement =
      "INSERT INTO students (first_name, last_name, age) VALUES ('John', "
      "'Doe', 25);";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* insertStatement = static_cast<InsertStatement*>(newTree->getRootNode());
  EXPECT_EQ(insertStatement->GetTableSource()->GetValue(), "students");
  EXPECT_EQ(insertStatement->GetColumnList().size(), 3);
  EXPECT_EQ(insertStatement->GetColumnList()[0]->GetValue(), "first_name");
  EXPECT_EQ(insertStatement->GetColumnList()[1]->GetValue(), "last_name");
  EXPECT_EQ(insertStatement->GetColumnList()[2]->GetValue(), "age");
  EXPECT_EQ(insertStatement->GetValueList().size(), 3);
  EXPECT_EQ(insertStatement->GetValueList()[0]->GetValue(), "'John'");
  EXPECT_EQ(insertStatement->GetValueList()[1]->GetValue(), "'Doe'");
  EXPECT_EQ(insertStatement->GetValueList()[2]->GetValue(), "25");
}

// Parse Condition Test Case for Assignment 1
// Basic select, happy path.
TEST(SelectTest, happyPathSelect) {
  const std::string statement = "SELECT * FROM MOVIE";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* selectStatement = static_cast<SelectStatement*>(newTree->getRootNode());
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "MOVIE");
}

// Test select with condition.
TEST(SelectTest, happyPathWithCondition) {
  const std::string statement = "SELECT * FROM MOVIE WHERE movie_id = 1;";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* selectStatement = static_cast<SelectStatement*>(newTree->getRootNode());
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "MOVIE");
  EXPECT_EQ(selectStatement->GetCondition()->GetValue(), "movie_id=1");
  Condition* cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "movie_id");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "1");
}

// Test logical operators such as `AND`, `OR`, and `NOT` within the conditions.
TEST(SelectTest, selecttWithLogicalOperators) {
  std::string statement =
      "SELECT * FROM PERSON WHERE person_id = 1 AND born = 1922;";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* selectStatement = static_cast<SelectStatement*>(newTree->getRootNode());
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "PERSON");
  EXPECT_EQ(selectStatement->GetCondition()->GetValue(),
            "person_id=1ANDborn=1922");
  Condition* cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "AND");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "person_id");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "1");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "born");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "1922");
}

// Test select with `NOT` condition.
TEST(SelectTest, selectWithNotCondition) {
  const std::string statement = "SELECT * FROM PERSON WHERE NOT person_id = 1;";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* selectStatement = static_cast<SelectStatement*>(newTree->getRootNode());
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "PERSON");
  EXPECT_EQ(selectStatement->GetCondition()->GetValue(), "NOTperson_id=1");
  Condition* cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "NOT");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "person_id");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "1");
}

// Test select with `OR` condition.
TEST(SelectTest, selectWithOrCondition) {
  std::string statement =
      "SELECT * FROM PERSON WHERE person_id = 1 OR born = 1922;";
  auto listener = MyListener();
  setUpTestCase(&listener, statement);
  auto* newTree = listener.GetParserTree();
  auto* selectStatement = static_cast<SelectStatement*>(newTree->getRootNode());
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "PERSON");
  EXPECT_EQ(selectStatement->GetCondition()->GetValue(),
            "person_id=1ORborn=1922");
  Condition* cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "OR");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "person_id");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "1");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "born");
  EXPECT_EQ(cond->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "1922");
}
