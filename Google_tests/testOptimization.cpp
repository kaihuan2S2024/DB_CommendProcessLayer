//
// Created by Leo on 02/02/25.
//
#include <gtest/gtest.h>

#include <iostream>

#include "../metadataManager/MetadataManager.h"
#include "../parserTree/MyListener/MyListener.h"
#include "antlr4-runtime.h"

void setup(MyListener *listener, const std::string &statement) {
  ANTLRInputStream input(statement);
  MySqlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  MySqlParser parser(&tokens);
  tree::ParseTree *tree = parser.sqlStatement();
  tree::ParseTreeWalker::DEFAULT.walk(listener, tree);
}

std::vector<ColumnMetadata> createMockColumnMetadata() {
  ColumnMetadata ageColumn("age", SQL_TYPE::SQL_INTEGER);
  ageColumn.totalRows = 100;
  ageColumn.max = 60;
  ageColumn.min = 20;
  ageColumn.average = 35;
  ageColumn.sum = 3500;
  ageColumn.frequencyMap = {{20, 10}, {30, 15}, {40, 20}, {50, 30}, {60, 25}};

  ColumnMetadata departmentColumn("department", SQL_TYPE::SQL_TEXT);
  departmentColumn.totalRows = 100;
  departmentColumn.stringFrequencyMap = {
      {"Sales", 30}, {"Marketing", 10}, {"Engineering", 60}};

  // Numeric column for experience
  ColumnMetadata experienceColumn("experience", SQL_TYPE::SQL_TEXT);
  experienceColumn.totalRows = 100;
  experienceColumn.max = 15;
  experienceColumn.min = 1;
  experienceColumn.average = 7;
  experienceColumn.sum = 700;
  experienceColumn.frequencyMap = {{1, 10}, {5, 25}, {10, 35}, {15, 30}};

  return {ageColumn, departmentColumn, experienceColumn};
}

// =============================================================================
// ================== Laws for Boolean Algebra =================================
// =============================================================================

// Inverse Law
// before - SELECT * FROM Movie WHERE title = 'Avengers: End Game' AND title !=
// 'Avengers: End Game';
// after - SELECT * FROM Movie WHERE NULL;
TEST(testInverseLaw, inverseLawAndBasic) {
  const std::string statement =
      "SELECT * FROM Movie WHERE title = 'Avengers: End Game' AND title != "
      "'Avengers: End Game';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(
      selectStatement->GetCondition()->getChildrenNodes()[0]->getNodeType(),
      NODE_TYPE_NULL);
}

// before - SELECT * FROM Movie WHERE title = 'Avengers: End Game' OR title !=
// 'Avengers: End Game';
// after - SELECT * FROM Movie WHERE ALL (0 children);
TEST(testInverseLaw, inverseLawOrBasic) {
  const std::string statement =
      "SELECT * FROM USER WHERE name='name' OR name != 'name'";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  // WHERE ALL == no condition, so size = 0
  EXPECT_EQ(
      selectStatement->GetCondition()->getChildrenNodes()[0]->getNodeType(),
      NODE_TYPE_ALL);
}

// before - SELECT * FROM Movie WHERE (title = 'Avengers: End Game' OR tile !=
// 'Avengers: End Game') AND title = 'Spider-man: No Way Home';
// after - SELECT * FROM Movie WHERE title = 'Spider-man: No Way Home';
TEST(testInverseLaw, inverseLawAndInParenthesis) {
  const std::string statement =
      "SELECT * FROM Movie WHERE (title = 'Avengers: End Game' OR title != "
      "'Avengers: End Game') AND title = 'Spider-man: No Way Home';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "=");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "title");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "'Spider-man: No Way Home'");
}

// before - SELECT * FROM Movie WHERE (title = 'Avengers: End Game' AND tile !=
// 'Avengers: End Game') OR title = 'Spider-man: No Way Home'; after - SELECT *
// FROM Movie WHERE title = 'Spider-man: No Way Home';
TEST(testInverseLaw, inverseLawOrInParenthesis) {
  const std::string statement =
      "SELECT * FROM Movie WHERE (title = 'Avengers: End Game' AND title != "
      "'Avengers: End Game') OR title = 'Spider-man: No Way Home';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "=");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "title");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "'Spider-man: No Way Home'");
}

// before - SELECT * FROM Movie WHERE (title = 'Avengers: End Game' OR tile !=
// 'Avengers: End Game') OR title = 'Spider-man: No Way Home';
// after - SELECT * FROM Movie WHERE ALL (0 children);
TEST(testInverseLaw, inverseLawOrInParenthesis2) {
  const std::string statement =
      "SELECT * FROM Movie WHERE (title = 'Avengers: End Game' OR title != "
      "'Avengers: End Game') OR title = 'Spider-man: No Way Home';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  // WHERE ALL == no condition, so size = 0
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(
      selectStatement->GetCondition()->getChildrenNodes()[0]->getNodeType(),
      NODE_TYPE_ALL);
}

// before - SELECT * FROM Movie WHERE (title = 'Avengers: End Game' AND title !=
// 'Avengers: End Game') AND title = 'Spider-man: No Way Home';
// after - SELECT * FROM Movie WHERE NULL;
TEST(testInverseLaw, inverseLawAndInParenthesis2) {
  const std::string statement =
      "SELECT * FROM Movie WHERE (title = 'Avengers: End Game' AND title != "
      "'Avengers: End Game') AND title = 'Spider-man: No Way Home';";
  MyListener listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  // WHERE ALL == no condition, so size = 0
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(
      selectStatement->GetCondition()->getChildrenNodes()[0]->getNodeType(),
      NODE_TYPE_NULL);
}

// before - SELECT * FROM Movie WHERE (title = 'Avengers: End Game' OR tile !=
// 'Avengers: End Game') OR (title = 'Spider-man: No Way Home' AND title !=
// 'Spider-man: No Way Home' ;
// after - SELECT * FROM Movie WHERE ALL (0 children);
TEST(testInverseLaw, inverseLawOrInParenthesis3) {
  const std::string statement =
      "SELECT * FROM Movie WHERE (title = 'Avengers: End Game' OR title != "
      "'Avengers: End Game') OR (title = 'Spider-man: No Way Home' AND title "
      "!= 'Spider-man: No Way Home');";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  // WHERE ALL == no condition, so size = 0
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(
      selectStatement->GetCondition()->getChildrenNodes()[0]->getNodeType(),
      NODE_TYPE_ALL);
}

// before - SELECT * FROM Movie WHERE NOT (title = 'Avengers: End Game' AND
// title != 'Avengers: End Game');
// after - SELECT * FROM Movie WHERE ALL;
TEST(testInverseLaw, inverseLawNotInParenthesis) {
  const std::string statement =
      "SELECT * FROM Movie WHERE NOT (title = 'Avengers: End Game' AND title "
      "!= 'Avengers: End Game');";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  // WHERE ALL == no condition, so size = 0
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(
      selectStatement->GetCondition()->getChildrenNodes()[0]->getNodeType(),
      NODE_TYPE_ALL);
}

// before - SELECT * FROM Movie WHERE NOT (title = 'Avengers: End Game' OR title
// != 'Avengers: End Game');
// after - SELECT * FROM Movie WHERE NULL;
TEST(testInverseLaw, inverseLawNotInParenthesis2) {
  const std::string statement =
      "SELECT * FROM Movie WHERE NOT (title = 'Avengers: End Game' OR title != "
      "'Avengers: End Game');";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::inverseLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  // WHERE ALL == no condition, so size = 0
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(
      selectStatement->GetCondition()->getChildrenNodes()[0]->getNodeType(),
      NODE_TYPE_NULL);
}

// Absorption Law
// before - SELECT title FROM movie WHERE title = 'Avengers' AND (genre =
// 'Avengers' OR released = 2020); after - SELECT title FROM movie WHERE title =
// 'Avengers';
TEST(testAbsorptionLaw, TestRedundantAbsorptionOptimization) {
  const std::string statement =
      "SELECT title \n"
      "FROM movie \n"
      "WHERE title = 'Avengers' AND (title = 'Avengers' OR released = 2020);";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::absorptionLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "title");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers'");
}

// before - SELECT title FROM movie WHERE (title = 'Avengers' OR released =
// 2020) AND title = 'Avengers'; after - SELECT title FROM movie WHERE title =
// 'Avengers';
TEST(testAbsorptionLaw, TestAbsorptionOptimization3) {
  const std::string statement =
      "SELECT title \n"
      "FROM movie \n"
      "WHERE (title = 'Avengers' OR released = 2020) AND title = 'Avengers';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::absorptionLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "title");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers'");
}

// before - SELECT title FROM movie WHERE (title = 'Avengers' AND released =
// 2020) OR title = 'Avengers'; after - SELECT title FROM movie WHERE title =
// 'Avengers';
TEST(testAbsorptionLaw, TestRedundantAbsorptionOptimization2) {
  const std::string statement =
      "SELECT title \n"
      "FROM movie \n"
      "WHERE (title = 'Avengers' AND released = 2020) OR title = 'Avengers'";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::absorptionLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "title");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  const auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers'");
}

// before - SELECT title FROM movie WHERE (title = 'Avengers' AND released =
// 2020) OR title = 'Avengers'; after - SELECT title FROM movie WHERE title =
// 'Avengers';
TEST(testAbsorptionLaw, TestAbsorptionOptimization4) {
  const std::string statement =
      "SELECT title \n"
      "FROM movie \n"
      "WHERE title = 'Avengers' OR (title = 'Avengers' AND released = 2020)";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::absorptionLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "title");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers'");
}

// before - SELECT title FROM movie WHERE (title = 'Avengers' AND (title =
// 'Avengers' OR released = 2020)) OR (title = 'Avengers' AND released = 2020);
// after - SELECT title FROM movie WHERE title = 'Avengers';
TEST(testAbsorptionLaw, TestAbsorptionOptimization5) {
  const std::string statement =
      "SELECT title \n"
      "FROM movie \n"
      "WHERE (title = 'Avengers' AND (title = 'Avengers' OR released = 2020)) "
      "OR (title = 'Avengers' AND released = 2020)";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::absorptionLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "title");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers'");
}

// before - SELECT title FROM movie WHERE (title = 'Avengers' AND (genre =
// 'Action' OR released = 2020)) OR title = 'Avengers';
// after - SELECT title FROM movie WHERE title = 'Avengers';
TEST(testAbsorptionLaw, TestNestedAbsorptionOptimization) {
  const std::string statement =
      "SELECT title \n"
      "FROM movie \n"
      "WHERE (title = 'Avengers' AND (genre = 'Action' OR released = 2020)) OR "
      "title = 'Avengers';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::absorptionLawOptimizer(selectStatement);
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "title");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  const auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers'");
}

// Idempotent Law Tests: Same Table Same Column
// before - SELECT * FROM person AS p INNER JOIN person as p2 ON p.id = p2.id;
// after - SELECT name FROM person AS p;
TEST(testIdempotentLaw, TestInnerJoinOptimization) {
  const std::string statement =
      "SELECT name FROM person AS p INNER JOIN person as p2 ON p.id = p2.id;";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::idempotentLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "name");
  EXPECT_EQ(
      selectStatement->GetTableSource()->getChildrenNodes()[0]->GetValue(),
      "person");
  EXPECT_EQ(selectStatement->GetJoins().size(), 1);
  EXPECT_EQ(selectStatement->GetFirstJoin()->GetJoinType(), 0);
}

// Idempotent Law Tests: Same Table Different Column
// before - SELECT * FROM person AS p INNER JOIN person as p2 ON p.employeeId =
// p2.managerId; after -  SELECT * FROM person AS p INNER JOIN person as p2 ON
// p.employeeId = p2.managerId;
TEST(testIdempotentLaw, TestInnerJoinOptimization2) {
  const std::string statement =
      "SELECT name FROM person AS p INNER JOIN person as p2 ON p.employeeId = "
      "p2.managerId;";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::idempotentLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "name");
  EXPECT_EQ(
      selectStatement->GetTableSource()->getChildrenNodes()[0]->GetValue(),
      "person");
  EXPECT_EQ(selectStatement->GetJoins().size(), 1);
  EXPECT_EQ(selectStatement->GetFirstJoin()->GetJoinType(), 1);
  auto joinCondition = selectStatement->GetFirstJoin()->GetCondition();
  EXPECT_EQ(joinCondition->GetValue(), "p.employeeId=p2.managerId");
  EXPECT_EQ(joinCondition->getChildrenNodes().size(), 1);
  EXPECT_EQ(joinCondition->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      joinCondition->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "p.employeeId");
  EXPECT_EQ(
      joinCondition->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "p2.managerId");
  auto joinTable = selectStatement->GetFirstJoin()->GetTable();
  EXPECT_EQ(joinTable->GetValue(), "AS");
  EXPECT_EQ(joinTable->getChildrenNodes().size(), 2);
  EXPECT_EQ(joinTable->getChildrenNodes()[0]->GetValue(), "person");
  EXPECT_EQ(joinTable->getChildrenNodes()[1]->GetValue(), "p2");
}

// before - SELECT * FROM movie WHERE title = 'Avengers: End Game' AND title =
// 'Avengers: End Game';
// after - SELECT * FROM movie WHERE title = 'Avengers: End Game';
TEST(testIdempotentLaw, TestRedundantAndOptimization) {
  const std::string statement =
      "SELECT * FROM movie WHERE title = 'Avengers: End Game' AND title = "
      "'Avengers: End Game';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::idempotentLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  const auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers: End Game'");
}

// before - SELECT * FROM movie WHERE title = 'Avengers: End Game' OR title =
// 'Avengers: End Game';
// after - SELECT * FROM movie WHERE title = 'Avengers: End Game';
TEST(testIdempotentLaw, TestRedundantOrOptimization) {
  const std::string statement =
      "SELECT * FROM movie WHERE title = 'Avengers: End Game' OR title = "
      "'Avengers: End Game';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::idempotentLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers: End Game'");
}

// before - SELECT * FROM movie WHERE title = 'Avengers: End Game' OR title =
// 'Avengers: End Game' OR title = 'Avengers: End Game';
// after - SELECT * FROM movie WHERE title = 'Avengers: End Game';
TEST(testIdempotentLaw, TestRedundantOrOptimization2) {
  const std::string statement =
      "SELECT * FROM movie WHERE title = 'Avengers: End Game' OR (title = "
      "'Avengers: End Game' OR title = 'Avengers: End Game');";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::idempotentLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  const auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers: End Game'");
}

// before - SELECT * FROM movie WHERE title = 'Avengers: End Game' AND title =
// 'Avengers: End Game' AND title = 'Avengers: End Game';
// after - SELECT * FROM movie WHERE title = 'Avengers: End Game';
TEST(testIdempotentLaw, TestRedundantAndOptimization2) {
  const std::string statement =
      "SELECT * FROM movie WHERE title = 'Avengers: End Game' AND (title = "
      "'Avengers: End Game' AND (title = 'Avengers: End Game' AND title = "
      "'Avengers: End Game')));";
  MyListener listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::idempotentLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers: End Game'");
}

// before - SELECT * FROM movie WHERE (title = 'Avengers: End Game' AND (title =
// 'Avengers: End Game' OR (title = 'Avengers: End Game' AND title = 'Avengers:
// End Game')));
// after - SELECT * FROM movie WHERE title = 'Avengers: End Game';
TEST(testIdempotentLaw, TestRedundantAndOrOptimization3) {
  const std::string statement =
      "SELECT * FROM movie WHERE (title = 'Avengers: End Game' AND (title = "
      "'Avengers: End Game' OR (title = 'Avengers: End Game' AND title = "
      "'Avengers: End Game')));";
  MyListener listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::idempotentLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers: End Game'");
}

// before - SELECT * FROM movie WHERE (title = 'Avengers: End Game' AND title =
// 'Avengers: End Game') OR (title = 'Avengers: End Game' AND title = 'Avengers:
// End Game'); after - SELECT * FROM movie WHERE title = 'Avengers: End Game';
TEST(testIdempotentLaw, TestRedundantAndOrOptimization4) {
  const std::string statement =
      "SELECT * FROM movie WHERE (title = 'Avengers: End Game' AND title = "
      "'Avengers: End Game') OR (title = 'Avengers: End Game' AND title = "
      "'Avengers: End Game') OR (title = 'Avengers: End Game' AND title = "
      "'Avengers: End Game');";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::idempotentLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetTableSource()->GetValue(), "movie");
  auto cond = selectStatement->GetCondition();
  EXPECT_EQ(cond->getChildrenNodes().size(), 1);
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers: End Game'");
}

// Distributive Law
// A (B + C) => AB + AC
// before - SELECT price FROM movie WHERE title = 'Avengers' AND (price = 100 OR
// year = 1990);
// after - SELECT price FROM movie WHERE title = 'Avengers' AND price = 100 OR
// title = 'Avengers' AND year = 1990;
TEST(testDistributiveLaw, AND) {
  const std::string statement =
      "SELECT price FROM movie WHERE title = 'Avengers' AND (price = 100 OR "
      "year = 1990)";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::distributiveOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  const auto leftChildCond = cond->getChildrenNodes()[0];
  const auto rightChildCond = cond->getChildrenNodes()[1];
  EXPECT_EQ(cond->GetValue(), "OR");
  EXPECT_EQ(cond->getNodeType(), 20);
  EXPECT_EQ(leftChildCond->GetValue(), "AND");
  EXPECT_EQ(leftChildCond->getNodeType(), 20);
  EXPECT_EQ(rightChildCond->GetValue(), "AND");
  EXPECT_EQ(rightChildCond->getNodeType(), 20);
  // test left child
  EXPECT_EQ(leftChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
  EXPECT_EQ(leftChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "price");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "100");
  // test right child
  EXPECT_EQ(rightChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
  EXPECT_EQ(rightChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "year");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "1990");
}

// (B + C) A => BA + CA
// before - SELECT price FROM movie WHERE (price = 100 OR year = 1990)
// AND title = 'Avengers' ;
// after - SELECT price FROM movie WHERE price = 100 AND title = 'Avengers' OR
// year = 1990 AND title = 'Avengers';
TEST(testDistributiveLaw, AND2) {
  const std::string statement =
      "SELECT price FROM movie WHERE (price = 100 OR year = 1990) "
      "AND title = 'Avengers'";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::distributiveOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  const auto leftChildCond = cond->getChildrenNodes()[0];
  const auto rightChildCond = cond->getChildrenNodes()[1];
  EXPECT_EQ(cond->GetValue(), "OR");
  EXPECT_EQ(cond->getNodeType(), 20);
  EXPECT_EQ(leftChildCond->GetValue(), "AND");
  EXPECT_EQ(leftChildCond->getNodeType(), 20);
  EXPECT_EQ(rightChildCond->GetValue(), "AND");
  EXPECT_EQ(rightChildCond->getNodeType(), 20);
  // test left child
  EXPECT_EQ(leftChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "price");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "100");
  EXPECT_EQ(leftChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
  // test right child
  EXPECT_EQ(rightChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "year");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "1990");
  EXPECT_EQ(rightChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
}

// negative test
// before - SELECT price FROM movie WHERE title = 'Avengers' AND price = 100 AND
// year = 1990;
// after - SELECT price FROM movie WHERE title = 'Avengers' AND price = 100 AND
// year = 1990;
TEST(testDistributiveLaw, AND3) {
  const std::string statement =
      "SELECT price FROM movie WHERE title = 'Avengers' AND price = 100 AND "
      "year = 1990";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::distributiveOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  const auto leftChildCond = cond->getChildrenNodes()[0];
  const auto rightChildCond = cond->getChildrenNodes()[1];
  EXPECT_EQ(cond->GetValue(), "AND");
  EXPECT_EQ(cond->getNodeType(), 20);
  EXPECT_EQ(leftChildCond->GetValue(), "AND");
  EXPECT_EQ(leftChildCond->getNodeType(), 20);
  EXPECT_EQ(rightChildCond->GetValue(), "=");
  EXPECT_EQ(rightChildCond->getNodeType(), 20);
  // test left child
  EXPECT_EQ(leftChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
  EXPECT_EQ(leftChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "price");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "100");
  // test right child
  EXPECT_EQ(rightChildCond->getChildrenNodes().size(), 2);
  EXPECT_EQ(rightChildCond->getChildrenNodes()[0]->GetValue(), "year");
  EXPECT_EQ(rightChildCond->getChildrenNodes()[1]->GetValue(), "1990");
}

// A + BC => AB + AC
// before - SELECT price FROM movie WHERE title = 'Avengers' OR (price = 100 AND
// year = 1990);
// after - SELECT price FROM movie WHERE title = 'Avengers' OR price = 100 AND
// title = 'Avengers' OR year = 1990;
TEST(testDistributiveLaw, OR) {
  const std::string statement =
      "SELECT price FROM movie WHERE title = 'Avengers' OR (price = 100 AND "
      "year = 1990)";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::distributiveOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  const auto leftChildCond = cond->getChildrenNodes()[0];
  const auto rightChildCond = cond->getChildrenNodes()[1];
  EXPECT_EQ(cond->GetValue(), "AND");
  EXPECT_EQ(cond->getNodeType(), 20);
  EXPECT_EQ(leftChildCond->GetValue(), "OR");
  EXPECT_EQ(leftChildCond->getNodeType(), 20);
  EXPECT_EQ(rightChildCond->GetValue(), "OR");
  EXPECT_EQ(rightChildCond->getNodeType(), 20);
  // test left child
  EXPECT_EQ(leftChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
  EXPECT_EQ(leftChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "price");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "100");
  // test right child
  EXPECT_EQ(rightChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
  EXPECT_EQ(rightChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "year");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "1990");
}

// AB + C =>  AB + AC
// before - SELECT price FROM movie WHERE title = 'Avengers' OR (price = 100 AND
// year = 1990);
// after - SELECT price FROM movie WHERE title = 'Avengers' OR price = 100 AND
// title = 'Avengers' OR year = 1990;
TEST(testDistributiveLaw, OR2) {
  const std::string statement =
      "SELECT price FROM movie WHERE (price = 100 AND year = 1990)"
      "OR title = 'Avengers'";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::distributiveOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  const auto leftChildCond = cond->getChildrenNodes()[0];
  const auto rightChildCond = cond->getChildrenNodes()[1];
  EXPECT_EQ(cond->GetValue(), "AND");
  EXPECT_EQ(cond->getNodeType(), 20);
  EXPECT_EQ(leftChildCond->GetValue(), "OR");
  EXPECT_EQ(leftChildCond->getNodeType(), 20);
  EXPECT_EQ(rightChildCond->GetValue(), "OR");
  EXPECT_EQ(rightChildCond->getNodeType(), 20);
  // test left child
  EXPECT_EQ(leftChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "price");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "100");
  EXPECT_EQ(leftChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
  // test right child
  EXPECT_EQ(rightChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "year");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "1990");
  EXPECT_EQ(rightChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      rightChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
}

// negative test
// before - SELECT price FROM movie WHERE title = 'Avengers' OR price = 100 OR
// year = 1990;
// after - SELECT price FROM movie WHERE title = 'Avengers' OR price = 100 OR
// year = 1990;
TEST(testDistributiveLaw, OR3) {
  const std::string statement =
      "SELECT price FROM movie WHERE title = 'Avengers' OR price = 100 OR year "
      "= 1990";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::distributiveOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  const auto leftChildCond = cond->getChildrenNodes()[0];
  const auto rightChildCond = cond->getChildrenNodes()[1];
  EXPECT_EQ(cond->GetValue(), "OR");
  EXPECT_EQ(cond->getNodeType(), 20);
  EXPECT_EQ(leftChildCond->GetValue(), "OR");
  EXPECT_EQ(leftChildCond->getNodeType(), 20);
  EXPECT_EQ(rightChildCond->GetValue(), "=");
  EXPECT_EQ(rightChildCond->getNodeType(), 20);
  // test left child
  EXPECT_EQ(leftChildCond->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "title");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "'Avengers'");
  EXPECT_EQ(leftChildCond->getChildrenNodes()[1]->GetValue(), "=");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[0]->GetValue(),
      "price");
  EXPECT_EQ(
      leftChildCond->getChildrenNodes()[1]->getChildrenNodes()[1]->GetValue(),
      "100");
  // test right child
  EXPECT_EQ(rightChildCond->getChildrenNodes().size(), 2);
  EXPECT_EQ(rightChildCond->getChildrenNodes()[0]->GetValue(), "year");
  EXPECT_EQ(rightChildCond->getChildrenNodes()[1]->GetValue(), "1990");
}

// before - SELECT price FROM movie WHERE NOT (title = 'Avengers' AND year =
// 1990);
// after - SELECT price FROM movie WHERE NOT title = 'Avengers' OR NOT year =
// 1990;
TEST(testDeMorganLaw, BasicNotAndConversion) {
  const std::string statement =
      "SELECT price FROM movie WHERE NOT (title = 'Avengers' AND year = 1990)";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::deMorganLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->GetValue(), "OR");
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "NOT");
  EXPECT_EQ(cond->getChildrenNodes()[1]->GetValue(), "NOT");
  // test left child notes
  const auto leftCond = cond->getChildrenNodes()[0]->getChildrenNodes()[0];
  EXPECT_EQ(leftCond->GetValue(), "=");
  EXPECT_EQ(leftCond->getChildrenNodes()[0]->GetValue(), "title");
  EXPECT_EQ(leftCond->getChildrenNodes()[1]->GetValue(), "'Avengers'");
  // test right child notes
  const auto rightCond = cond->getChildrenNodes()[1]->getChildrenNodes()[0];
  EXPECT_EQ(rightCond->GetValue(), "=");
  EXPECT_EQ(rightCond->getChildrenNodes()[0]->GetValue(), "year");
  EXPECT_EQ(rightCond->getChildrenNodes()[1]->GetValue(), "1990");
}

// before - SELECT price FROM movie WHERE NOT (title = 'Avengers' AND (price = 100
// AND year = 1990));
// after - SELECT price FROM movie WHERE NOT title = 'Avengers' OR NOT price =
// 100 OR NOT year = 1990;
TEST(testDeMorganLaw, NestedNotAndConversion) {
  const std::string statement =
      "SELECT price FROM movie WHERE NOT (title = 'Avengers' AND (price = 100 "
      "AND year = 1990))";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::deMorganLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->GetValue(), "OR");
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "NOT");
  EXPECT_EQ(cond->getChildrenNodes()[0]->getNodeType(), 20);
  EXPECT_EQ(cond->getChildrenNodes()[1]->GetValue(), "OR");
  // test left child notes
  const auto leftCond = cond->getChildrenNodes()[0]->getChildrenNodes()[0];
  EXPECT_EQ(leftCond->GetValue(), "=");
  EXPECT_EQ(leftCond->getChildrenNodes()[0]->GetValue(), "title");
  EXPECT_EQ(leftCond->getChildrenNodes()[1]->GetValue(), "'Avengers'");
  // test right child notes
  const auto rightCond1 = cond->getChildrenNodes()[1]->getChildrenNodes()[0];
  EXPECT_EQ(rightCond1->GetValue(), "NOT");
  EXPECT_EQ(rightCond1->getNodeType(), 20);
  EXPECT_EQ(rightCond1->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      rightCond1->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "price");
  EXPECT_EQ(
      rightCond1->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "100");
  const auto rightCond2 = cond->getChildrenNodes()[1]->getChildrenNodes()[1];
  EXPECT_EQ(rightCond2->GetValue(), "NOT");
  EXPECT_EQ(rightCond2->getNodeType(), 20);
  EXPECT_EQ(rightCond2->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      rightCond2->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "year");
  EXPECT_EQ(
      rightCond2->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "1990");
}

// before - SELECT price FROM movie WHERE NOT (title = 'Avengers' OR year =
// 1990);
// after - SELECT price FROM movie WHERE NOT title = 'Avengers' AND NOT year =
// 1990;
TEST(testDeMorganLaw, BasicNotOrConversion) {
  const std::string statement =
      "SELECT price FROM movie WHERE NOT (title = 'Avengers' OR year = 1990)";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::deMorganLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->GetValue(), "AND");
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "NOT");
  EXPECT_EQ(cond->getChildrenNodes()[1]->GetValue(), "NOT");
  // test left child notes
  const auto leftCond = cond->getChildrenNodes()[0]->getChildrenNodes()[0];
  EXPECT_EQ(leftCond->GetValue(), "=");
  EXPECT_EQ(leftCond->getChildrenNodes()[0]->GetValue(), "title");
  EXPECT_EQ(leftCond->getChildrenNodes()[1]->GetValue(), "'Avengers'");
  // test right child notes
  const auto rightCond = cond->getChildrenNodes()[1]->getChildrenNodes()[0];
  EXPECT_EQ(rightCond->GetValue(), "=");
  EXPECT_EQ(rightCond->getChildrenNodes()[0]->GetValue(), "year");
  EXPECT_EQ(rightCond->getChildrenNodes()[1]->GetValue(), "1990");
}

// before - SELECT price FROM movie WHERE NOT ((price = 100 AND title =
// 'Avengers') OR year = 1990); after - SELECT price FROM movie WHERE NOT price
// = 100 OR NOT title = 'Avengers' AND NOT year = 1990;
TEST(testDeMorganLaw, NestedNotOrConversion) {
  const std::string statement =
      "SELECT price FROM movie WHERE NOT ((price = 100 AND title = 'Avengers') "
      "OR year = 1990)";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement = Optimizer::deMorganLawOptimizer(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  const auto cond = selectStatement->GetCondition()->getChildrenNodes()[0];
  EXPECT_EQ(cond->getChildrenNodes().size(), 2);
  EXPECT_EQ(cond->GetValue(), "AND");
  EXPECT_EQ(cond->getChildrenNodes()[0]->GetValue(), "OR");
  EXPECT_EQ(cond->getChildrenNodes()[1]->GetValue(), "NOT");
  // test left child notes
  const auto leftCond1 = cond->getChildrenNodes()[0]->getChildrenNodes()[0];
  const auto leftCond2 = cond->getChildrenNodes()[0]->getChildrenNodes()[1];
  EXPECT_EQ(leftCond1->GetValue(), "NOT");
  EXPECT_EQ(leftCond1->getNodeType(), 20);
  EXPECT_EQ(leftCond1->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(leftCond1->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "price");
  EXPECT_EQ(leftCond1->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "100");
  EXPECT_EQ(leftCond2->GetValue(), "NOT");
  EXPECT_EQ(leftCond2->getNodeType(), 20);
  EXPECT_EQ(leftCond2->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(leftCond2->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
            "title");
  EXPECT_EQ(leftCond2->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
            "'Avengers'");
  // test right child notes
  const auto rightCond = cond->getChildrenNodes()[1]->getChildrenNodes()[0];
  EXPECT_EQ(rightCond->GetValue(), "=");
  EXPECT_EQ(rightCond->getChildrenNodes()[0]->GetValue(), "year");
  EXPECT_EQ(rightCond->getChildrenNodes()[1]->GetValue(), "1990");
}

// =============================================================================
// ================== Tests Join and Where Simplifications =====================
// =============================================================================

// before - SELECT r.rating FROM REVIEWED AS r JOIN movie AS m ON r.person_id =
// m.person_id WHERE r.person_id = m.person_id AND m.released = 2019;
// after - SELECT r.rating FROM REVIEWED AS r JOIN movie AS m ON r.person_id =
// m.person_id WHERE m.released = 2019;
TEST(testEliminateRedundantJoinConditions, TestRedundantConditionOptimization) {
  std::string statement =
      "SELECT r.rating \n"
      "FROM REVIEWED AS r\n"
      "JOIN movie AS m ON r.person_id = m.person_id\n"
      "WHERE r.person_id = m.person_id AND m.released = 2019;";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement =
      Optimizer::eliminateRedundantJoinConditions(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "r.rating");
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(selectStatement->GetJoins().size(), 1);
  auto whereCondition = selectStatement->GetCondition();
  EXPECT_EQ(whereCondition->getNodeType(), NODE_TYPE_CONDITION);
  EXPECT_EQ(whereCondition->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      whereCondition->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "m.released");
  EXPECT_EQ(
      whereCondition->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "2019");
  auto joinCondition = selectStatement->GetJoins()[0]->GetCondition();
  EXPECT_EQ(joinCondition->getNodeType(), NODE_TYPE_CONDITION);
  EXPECT_EQ(joinCondition->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      joinCondition->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "r.person_id");
  EXPECT_EQ(
      joinCondition->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "m.person_id");
}

// before - SELECT r.rating FROM REVIEWED AS r JOIN movie AS m ON r.person_id =
// m.person_id WHERE m.person_id = r.person_id;
// after - SELECT r.rating FROM REVIEWED AS r JOIN movie AS m ON r.person_id =
// m.person_id WHERE ALL;
TEST(testEliminateRedundantJoinConditions,
     TestRedundantConditionOptimization2) {
  const std::string statement =
      "SELECT r.rating \n"
      "FROM REVIEWED AS r\n"
      "JOIN movie AS m ON r.person_id = m.person_id\n"
      "WHERE r.person_id = m.person_id;";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement =
      Optimizer::eliminateRedundantJoinConditions(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "r.rating");
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(selectStatement->GetJoins().size(), 1);
  const auto whereCondition = selectStatement->GetCondition();
  EXPECT_EQ(whereCondition->getNodeType(), NODE_TYPE_CONDITION);
  EXPECT_EQ(whereCondition->getChildrenNodes()[0]->getNodeType(),
            NODE_TYPE_ALL);
  const auto joinCondition = selectStatement->GetJoins()[0]->GetCondition();
  EXPECT_EQ(joinCondition->getNodeType(), NODE_TYPE_CONDITION);
  EXPECT_EQ(joinCondition->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      joinCondition->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "r.person_id");
  EXPECT_EQ(
      joinCondition->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "m.person_id");
}

// before - SELECT r.rating FROM REVIEWED AS r JOIN movie AS m ON r.person_id =
// m.person_id WHERE NOT m.person_id = r.person_id;
// after - SELECT r.rating FROM REVIEWED AS r WHERE NULL;
TEST(testEliminateRedundantJoinConditions,
     TestRedundantConditionOptimization3) {
  const std::string statement =
      "SELECT r.rating \n"
      "FROM REVIEWED AS r\n"
      "JOIN movie AS m ON r.person_id = m.person_id\n"
      "WHERE NOT r.person_id = m.person_id;";
  MyListener listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement =
      Optimizer::eliminateRedundantJoinConditions(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "r.rating");
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  EXPECT_EQ(selectStatement->GetJoins().size(), 1);
  auto whereCondition = selectStatement->GetCondition();
  EXPECT_EQ(whereCondition->getNodeType(), NODE_TYPE_CONDITION);
  EXPECT_EQ(whereCondition->getChildrenNodes()[0]->getNodeType(),
            NODE_TYPE_NULL);

  EXPECT_EQ(selectStatement->GetJoins()[0]->GetJoinType(), NO_JOIN);
}

// Multiple Join Clauses
// before -
// SELECT * FROM A
// JOIN B ON A.id = B.a_id
// JOIN C ON B.id = C.b_id
// WHERE B.a_id = A.id AND C.b_id = B.id AND A.name = 'test';
// after -
// SELECT * FROM A
// JOIN B ON A.id = B.a_id
// JOIN C ON B.id = C.b_id
// WHERE A.name = 'test';
TEST(testEliminateRedundantJoinConditions,
     TestRedundantConditionOptimization4) {
  const std::string statement =
      "SELECT * \n"
      "FROM A\n"
      "JOIN B ON A.id = B.a_id\n"
      "JOIN C ON B.id = C.b_id\n"
      "WHERE A.id = B.a_id AND B.id = C.b_id AND A.name = 'test';";
  MyListener listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  selectStatement =
      Optimizer::eliminateRedundantJoinConditions(selectStatement);
  std::cout << selectStatement->toString() << std::endl;
  EXPECT_EQ(selectStatement->GetSelectList().size(), 1);
  EXPECT_EQ(selectStatement->GetSelectList()[0]->GetValue(), "*");
  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes().size(), 1);
  auto *whereCondition = selectStatement->GetCondition();
  EXPECT_EQ(whereCondition->getNodeType(), NODE_TYPE_CONDITION);
  EXPECT_EQ(whereCondition->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      whereCondition->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "A.name");
  EXPECT_EQ(
      whereCondition->getChildrenNodes()[0]->getChildrenNodes()[1]->GetValue(),
      "'test'");
  EXPECT_EQ(selectStatement->GetJoins().size(), 2);
  auto joinCondition1 = selectStatement->GetJoins()[0]->GetCondition();
  auto joinCondition2 = selectStatement->GetJoins()[1]->GetCondition();
  EXPECT_EQ(joinCondition1->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      joinCondition1->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "A.id");
  EXPECT_EQ(joinCondition2->getChildrenNodes()[0]->GetValue(), "=");
  EXPECT_EQ(
      joinCondition2->getChildrenNodes()[0]->getChildrenNodes()[0]->GetValue(),
      "B.id");
}

// =============================================================================
// ================== Tests for Cost-based Optimization ========================
// =============================================================================




// DeMorgan Law
// before - SELECT * FROM employees WHERE NOT (age >= 30 AND department !=
// 'Marketing');
// after - SELECT * FROM employees WHERE age < 30 OR department =
// 'Marketing';
TEST(testCostBasedDeMorgan, costBasedDeMorganBasic) {
  const std::string statement =
      "SELECT * \n"
      "FROM employees \n"
      "WHERE NOT (age >= 30 AND department != 'Marketing');";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  const std::vector<ColumnMetadata> columns = createMockColumnMetadata();
  selectStatement =
      Optimizer::costBasedDeMorgansLawOptimizer(selectStatement, columns);

  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "OR");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "<");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "=");
}

// before - SELECT * FROM employees WHERE NOT (age >= 30 AND department =
// 'Marketing');
// after - SELECT * FROM employees WHERE age < 30 OR department != 'Marketing';
TEST(testCostBasedDeMorgan, costBasedDeMorganBasic2) {
  const std::string statement =
      "SELECT * \n"
      "FROM employees \n"
      "WHERE NOT (age >= 30 AND department = 'Marketing');";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  const std::vector<ColumnMetadata> columns = createMockColumnMetadata();
  selectStatement =
      Optimizer::costBasedDeMorgansLawOptimizer(selectStatement, columns);

  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "OR");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "<");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "!=");
}

// before - SELECT * FROM employees WHERE NOT (age < 30 OR department !=
// 'Marketing'); after - SELECT * FROM employees WHERE age >= 30 AND department
// != 'Marketing';
TEST(testCostBasedDeMorgan, costBasedDeMorganBasic3) {
  const std::string statement =
      "SELECT * \n"
      "FROM employees \n"
      "WHERE NOT (age < 30 OR department != 'Marketing');";
  MyListener listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  const std::vector<ColumnMetadata> columns = createMockColumnMetadata();
  selectStatement =
      Optimizer::costBasedDeMorgansLawOptimizer(selectStatement, columns);

  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "AND");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            ">=");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "=");
}

// before - SELECT * FROM employees WHERE NOT (age < 30 OR department !=
// "Engineering");
// after - SELECT * FROM employees WHERE NOT (age < 30 OR department !=
// "Engineering");
TEST(testCostBasedDeMorgan, costBasedDeMorganNoOptimization) {
  const std::string statement =
      "SELECT * \n"
      "FROM employees \n"
      "WHERE NOT (age < 30 OR department != 'Engineering');";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  const std::vector<ColumnMetadata> columns = createMockColumnMetadata();
  selectStatement =
      Optimizer::costBasedDeMorgansLawOptimizer(selectStatement, columns);

  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "NOT");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "OR");
}

// Inverse DeMorgan Law
// before - SELECT * FROM employees WHERE age >= 30 OR department !=
// 'Marketing'; after - SELECT * FROM employees WHERE NOT (age < 30 AND
// department = 'Marketing');
TEST(testCostBasedDeMorgan, costBasedInverseDeMorganBasic) {
  const std::string statement =
      "SELECT * \n"
      "FROM employees \n"
      "WHERE age >= 30 OR department != 'Marketing';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  const std::vector<ColumnMetadata> columns = createMockColumnMetadata();
  selectStatement =
      Optimizer::costBasedDeMorgansLawOptimizer(selectStatement, columns);

  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "NOT");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "AND");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "<");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "=");
}

// before - SELECT * FROM employees WHERE age >= 30 OR department = 'Marketing';
// after - SELECT * FROM employees WHERE NOT (age < 30 AND department !=
// 'Marketing');
TEST(testCostBasedDeMorgan, costBasedInverseDeMorganBasic2) {
  const std::string statement =
      "SELECT * \n"
      "FROM employees \n"
      "WHERE age >= 30 OR department = 'Marketing';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  const std::vector<ColumnMetadata> columns = createMockColumnMetadata();
  selectStatement =
      Optimizer::costBasedDeMorgansLawOptimizer(selectStatement, columns);

  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "NOT");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "AND");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "<");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "!=");
}
// before - SELECT * FROM employees WHERE age < 30 OR department != 'Marketing';
// after - SELECT * FROM employees WHERE NOT (age >= 30 AND department =
// 'Marketing');
TEST(testCostBasedDeMorgan, costBasedInverseDeMorganBasic3) {
  const std::string statement =
      "SELECT * \n"
      "FROM employees \n"
      "WHERE age < 30 OR department != 'Marketing';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  const std::vector<ColumnMetadata> columns = createMockColumnMetadata();
  selectStatement =
      Optimizer::costBasedDeMorgansLawOptimizer(selectStatement, columns);

  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "NOT");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            "AND");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->GetValue(),
            ">=");
  EXPECT_EQ(selectStatement->GetCondition()
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[0]
                ->getChildrenNodes()[1]
                ->GetValue(),
            "=");
}

// before - SELECT * FROM employees WHERE age < 30 OR department = 'Marketing';
// after - SELECT * FROM employees WHERE age < 30 OR department = 'Marketing';
TEST(testCostBasedDeMorgan, costBasedInverseDeMorganNoOptimization) {
  const std::string statement =
      "SELECT * \n"
      "FROM employees \n"
      "WHERE age < 30 OR department = 'Marketing';";
  auto listener = MyListener();
  setup(&listener, statement);
  auto *newTree = listener.GetParserTree();
  auto *selectStatement =
      static_cast<SelectStatement *>(newTree->getRootNode());
  const std::vector<ColumnMetadata> columns = createMockColumnMetadata();
  selectStatement =
      Optimizer::costBasedDeMorgansLawOptimizer(selectStatement, columns);

  EXPECT_EQ(selectStatement->GetCondition()->getChildrenNodes()[0]->GetValue(),
            "OR");
}