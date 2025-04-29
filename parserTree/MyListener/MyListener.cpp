//
// Created by JYJ on 2023/7/3.
//

#include "MyListener/MyListener.h"
#include "IntegrityChecker/IntegrityConstraint/include/TypeConstraint.h"
#include "log.h"
// TODO: JOIN
// TODO: Valgrind
// TODO3: Refactor ParserTreeNode to include a value field, for easier use and
// debugging

std::string MyListener::checkIfContainsFunction(std::string str) {
  std::string result = "";
  auto FUNCTION_LIST = Element::GetMySqlFunctionList();
  for (int i = 0; i < FUNCTION_LIST.size(); i++) {
    if (str.find(FUNCTION_LIST[i]) != std::string::npos) {
      result = FUNCTION_LIST[i];
      break;
    }
  }
  return result;
}
std::string trimColWithFunc(std::string func, std::string col) {
  std::string::size_type pos = col.find(func);
  std::string result = col.erase(pos, func.length());
  result = result.substr(1, result.length() - 2);
  return result;
}

ParserTreeNode *MyListener::getAlias(antlr4::tree::ParseTree *ctx,
                                     int possible_type = -1) {
  // If possible type is not -1, then we check if the child0 is the possible
  // type 1: table_ref, 2: col_ref
  if (ctx->children.size() > 1) {
    for (int i = 0; i < ctx->children.size(); i++) {
      std::cout << i << ": " << ctx->children[i]->getText() << std::endl;
    }
    Operator *alias = new Operator(OPERATOR_TYPE_ALIAS, "AS");
    if (possible_type == 1) {
      alias->addChildNode(
          new Element(NODE_TYPE_TABLE_REF, ctx->children[0]->getText()));
    } else {
      alias->addChildNode(
          new Element(NODE_TYPE_COL_REF, ctx->children[0]->getText()));
    }
    alias->addChildNode(
        new Element(NODE_TYPE_ALIAS, ctx->children[2]->getText()));
    return alias;
  }
  if (possible_type == 1) {
    return new Element(NODE_TYPE_TABLE_REF, ctx->getText());
  }
  auto result = new Element(NODE_TYPE_COL_REF, ctx->getText());
  return result;
}

void MyListener::SetStatement(const std::string &statement) {
  MyListener::statement = statement;
}

const std::string &MyListener::GetStatement() const { return statement; }

UpdateStatement *MyListener::parseUpdateStatement(
    antlr4::tree::ParseTree *ctx) {
  // UPDATE table1 SET column1 = value1, column2 = value2 WHERE column3 =
  // value3; UPDATE table1 SET column1 = column1, column2 = value2 WHERE column3
  // IN (SELECT column4 FROM table2 WHERE column5 = 'some_value'); table1 -
  // column1 - value1
  //        - column2 - value2
  //        - condition
  // TODO: write everything
  auto *update_statement = new UpdateStatement();
  update_statement->SetValue(ctx->getText());
  auto vectorList = ctx->children[0]->children;
  // Get table from child[0][1]
  update_statement->SetTableSource(parseTableSource(vectorList[1]).at(0));
  //
  std::vector<ParserTreeNode *> update_list = parseUpdateList(ctx->children[0]);
  update_statement->SetUpdateList(update_list);
  if (vectorList[vectorList.size() - 2]->getText() == "WHERE") {
    auto *predicate = new Condition();
    predicate->SetValue(vectorList[vectorList.size() - 1]->getText());
    auto temp = parseCondition(vectorList[vectorList.size() - 1]);
    predicate->addChildNode(temp);
    update_statement->SetCondition(predicate);
  }
  return update_statement;
}

DeleteStatement *MyListener::parseDeleteStatement(
    antlr4::tree::ParseTree *ctx) {
  // DELETE FROM table1 WHERE column1 = 10;
  // DELETE FROM students;
  // DELETE FROM products WHERE product_id NOT IN (SELECT product_id FROM
  // orders);
  DeleteStatement *delete_statement = new DeleteStatement();
  delete_statement->SetValue(ctx->getText());
  delete_statement->SetTableSource(
      parseTableSource(ctx->children[0]->children[2]).at(0));
  auto *predicate = new Condition();
  if (ctx->children[0]->children.size() >= 4) {
    predicate->SetValue(ctx->children[0]->children[4]->getText());
    auto temp = parseCondition(ctx->children[0]->children[4]);
    predicate->addChildNode(temp);
  }
  delete_statement->SetCondition(predicate);
  return delete_statement;
}

Join *testParseJoin(antlr4::tree::ParseTree *ctx) {
  auto *join = new Join();
  join->SetJoinType(0);
  // std::cout<< ctx->getText() << std::endl;
  return join;
}

Join *testParseJoin1() {
  auto *join = new Join();
  join->SetJoinType(0);
  // std::cout<< ctx->getText() << std::endl;
  return join;
}

SelectStatement *MyListener::parseSelectStatement(
    antlr4::tree::ParseTree *ctx) {
  // SELECT AVG(col1), col2, col3 FROM table1 WHERE (column1 = 'someSting') AND
  // (NOT column2 = 20 OR column3 = 30); SELECT col1, col2, col3 FROM table2;
  //         avg - col1
  // column1   10
  auto *select_statement = new SelectStatement();
  select_statement->SetValue(ctx->getText());
  // Get selected elements from child[0][1]
  std::vector<ParserTreeNode *> select_list =
      parseSelectList(ctx->children[0]->children[1]);
  select_statement->SetSelectList(select_list);
  // Parse inner join
  // Get table source from child[0][2][1]
  // SELECT orders.order_id, orders.order_date, customers.customer_name FROM
  // orders INNER JOIN customers ON orders.customer_id = customers.human_id
  // INNER JOIN humans ON humans.age = customers.id;
  if (ctx->children[0]->children[2]->children.size() >= 2) {
    auto temp = ctx->children[0]->children[2]->children[1];
    std::vector<ParserTreeNode *> table_source = parseTableSource(temp);
    select_statement->SetTableSource(table_source.at(0));
    //
    auto joins = parseJoin(temp);
    select_statement->SetJoin(joins);
  }
  // Get condition from child[0][2][3] if there is a predicate to begin with
  auto *predicate = new Condition();
  if (ctx->children[0]->children[2]->children.size() >= 4) {
    predicate->SetValue(ctx->children[0]->children[2]->children[3]->getText());
    auto predicateChild = ctx->children[0]->children[2]->children[3];
    auto temp = parseCondition(predicateChild);
    predicate->addChildNode(temp);
  }
  select_statement->SetCondition(predicate);
  // This is the function you use to compare tostring
  // select_statement->toString();
  return select_statement;
}

InsertStatement *MyListener::parseInsertStatement(
    antlr4::tree::ParseTree *ctx) {
  // TODO: write everything
  // INSERT INTO students (first_name, last_name, age) VALUES ('John', 'Doe',
  // 25); INSERT INTO students (first_name, last_name, age) VALUES ('Alice',
  // 'Smith', 20), ('Bob', 'Johnson', 23), ('Emily', 'Williams', 21); Get target
  // table from child[2]
  auto *insert_statement = new InsertStatement();
  insert_statement->SetValue(ctx->getText());
  insert_statement->SetTableSource(parseTableSource(ctx->children[2]).at(0));
  // Get insert fields from child[4]
  std::vector<ParserTreeNode *> insert_fields =
      parseInsertFields(ctx->children[4]);
  insert_statement->SetColumnList(insert_fields);
  // Get insert values from child[6]
  std::vector<ParserTreeNode *> insert_values =
      parseInsertValues(ctx->children[6]);
  insert_statement->SetValueList(insert_values);
  return insert_statement;
}

ParserTreeNode *MyListener::parseInsertSubSet(antlr4::tree::ParseTree *ctx) {
  auto *set = new Element(NODE_TYPE_SQL_VALUE, ctx->getText());
  for (int j = 0; j < ctx->children.size(); j++) {
    if (ctx->children[j]->getText() == "," ||
        ctx->children[j]->getText() == "(" ||
        ctx->children[j]->getText() == ")") {
      continue;
    }
    auto *value = new Element(NODE_TYPE_SQL_VALUE, ctx->children[j]->getText());
    set->addChildNode(value);
  }
  return set;
}

std::vector<ParserTreeNode *> MyListener::parseInsertValues(
    antlr4::tree::ParseTree *ctx) {
  std::vector<ParserTreeNode *> result;
  bool start = false;
  for (int i = 0; i < ctx->children.size(); i++) {
    if (toUpperCase(ctx->children[i]->getText()) == "VALUES") {
      start = true;
      continue;
    }
    // ignore the comma
    if (ctx->children[i]->getText() == "," ||
        ctx->children[i]->getText() == "(" ||
        ctx->children[i]->getText() == ")") {
      continue;
    }
    PRINT("enterInsertValue!!: " << ctx->children[i]->getText() << std::endl);
    if (start) {
      auto *set = parseInsertSubSet(ctx->children[i]);
      for (int j = 0; j < set->getChildrenNodes().size(); j++) {
        result.push_back(set->getChildrenNodes()[j]);
      }
    }
  }
  return result;
}

std::vector<ParserTreeNode *> MyListener::parseInsertFields(
    antlr4::tree::ParseTree *ctx) {
  std::vector<ParserTreeNode *> result;
  for (int i = 0; i < ctx->children.size(); i++) {
    // ignore the comma
    if (ctx->children[i]->getText() == "," ||
        ctx->children[i]->getText() == "(" ||
        ctx->children[i]->getText() == ")") {
      continue;
    }
    PRINT("enterInsertField!!: " << ctx->children[i]->getText() << std::endl);
    auto *field = new Element(NODE_TYPE_COL_REF, ctx->children[i]->getText());
    result.push_back(field);
  }
  return result;
}

std::vector<ParserTreeNode *> MyListener::parseUpdateList(
    antlr4::tree::ParseTree *ctx) {
  std::vector<ParserTreeNode *> result;
  bool start = false;
  for (int i = 0; i < ctx->children.size(); i++) {
    // ignore the comma
    if (ctx->children[i]->getText() == ",") {
      continue;
    }
    if (ctx->children[i]->getText() == "SET") {
      start = true;
    }
    if (ctx->children[i]->getText() == "WHERE") {
      break;
    }
    PRINT("enterUpdateList!!: " << ctx->children[i]->getText() << std::endl);
    if (start && ctx->children[i]->getTreeType() !=
                     antlr4::tree::ParseTreeType::TERMINAL) {
      // We are at the updated elements
      ParserTreeNode *op = new Operator(OPERATOR_TYPE_ASSIGNMENT, "=");
      op->addChildNode(new Element(NODE_TYPE_COL_REF,
                                   ctx->children[i]->children[0]->getText()));
      op->addChildNode(new Element(NODE_TYPE_SQL_VALUE,
                                   ctx->children[i]->children[2]->getText()));
      result.push_back(op);
    }
  }
  return result;
}

std::vector<ParserTreeNode *> MyListener::parseSelectList(
    antlr4::tree::ParseTree *ctx) {
  std::vector<ParserTreeNode *> result;
  for (int i = 0; i < ctx->children.size(); i++) {
    // ignore the comma
    if (ctx->children[i]->getText() == ",") {
      continue;
    }
    PRINT("enterSelectElement!!: " << ctx->children[i]->getText() << std::endl);
    auto temp = ctx->children[i]->getText();
    std::string func = checkIfContainsFunction(ctx->children[i]->getText());
    if (!func.empty()) {
      auto *node = new Element(NODE_TYPE_FUNCTION, func);
      auto *node2 =
          new Element(NODE_TYPE_COL_REF,
                      trimColWithFunc(func, ctx->children[i]->getText()));
      node->addChildNode(node2);
      result.push_back(node);
      continue;
    }
    auto *node = getAlias(ctx->children[i], 0);
    result.push_back(node);
  }
  return result;
}

std::vector<Join *> MyListener::parseJoin(antlr4::tree::ParseTree *ctx) {
  int a = 1;
  auto tempP = ctx->children[0];
  std::vector<Join *> result;
  if (tempP->children.size() <= 1) {
    Join *join = new Join();
    join->SetJoinType(NO_JOIN);
    result.push_back(join);
    return result;
  } else {
    for (int i = 1; i < tempP->children.size(); i++) {
      auto temp = tempP->children[i];
      Join *join = new Join();
      join->SetValue(temp->getText());
      if (temp->children[0]->getText() == "JOIN") {
        join->SetJoinType(INNER_JOIN);
        join->SetTable(getAlias(temp->children[1], 1));
        Condition *condition = new Condition();
        if (temp->children.size() == 4) {
          condition->SetValue(temp->children[3]->getText());
          condition->addChildNode(parseCondition(temp->children[3]));
        }
        join->SetCondition(condition);
      } else {
        if (temp->children[0]->getText() == "INNER") {
          join->SetJoinType(INNER_JOIN);
        } else if (temp->children[0]->getText() == "OUTER") {
          join->SetJoinType(OUTER_JOIN);
        } else if (temp->children[0]->getText() == "CROSS") {
          join->SetJoinType(CROSS_JOIN);
        } else if (temp->children[0]->getText() == "NATURAL") {
          join->SetJoinType(NATURAL_JOIN);
        }
        join->SetTable(getAlias(temp->children[2], 1));
        Condition *condition = new Condition();
        if (temp->children.size() == 5) {
          condition->SetValue(temp->children[4]->getText());
          condition->addChildNode(parseCondition(temp->children[4]));
        }
        join->SetCondition(condition);
      };
      result.push_back(join);
    }
    return result;
  }
}

std::vector<ParserTreeNode *> MyListener::parseTableSource(
    antlr4::tree::ParseTree *ctx) {
  auto temp = ctx->children[0];
  std::vector<ParserTreeNode *> result;
  auto *table_source = getAlias(temp->children[0], 1);
  result.push_back(table_source);
  //  auto* join = parseJoin(ctx);
  //  result.push_back(join);
  return result;
}
// there are SEVEN types of operators in SQL
// 1. Comparison operator: =, >, <, >=, <=
// 2. Logical operator: AND, OR, NOT
// 3. Set operator: IN, NOT IN
// 4. Pattern matching operator: LIKE, NOT LIKE
// 5. Range operator: BETWEEN, NOT BETWEEN
// 6. Nullity operator: IS NULL, IS NOT NULL
// 7. Existence operator: EXISTS, NOT EXISTS
// EXTRA: the operand can be a subquery -> recursion happens here

bool checkComparisonOperator(std::string s) {
  std::vector operatorList = {"=", ">", "<", ">=", "<=", "!=", "<>"};
  auto pos = std::find(operatorList.begin(), operatorList.end(), s);
  if (pos != operatorList.end()) {
    return true;
  }
  return false;
}

bool checkLogicalOperator(std::string s) {
  std::vector<std::string> operatorList = {"AND", "OR", "NOT"};
  std::string upperS = MyListener::toUpperCase(s);
  auto pos = std::find(operatorList.begin(), operatorList.end(), upperS);
  return pos != operatorList.end();
}

bool checkSetOperator(std::string s) {
  std::vector operatorList = {"IN", "NOT IN"};
  auto pos = std::find(operatorList.begin(), operatorList.end(), s);
  if (pos != operatorList.end()) {
    return true;
  }
  return false;
}

bool checkPatternMatchingOperator(std::string s) {
  std::vector operatorList = {"LIKE", "NOT LIKE"};
  auto pos = std::find(operatorList.begin(), operatorList.end(), s);
  if (pos != operatorList.end()) {
    return true;
  }
  return false;
}

bool checkRangeOperator(std::string s) {
  std::vector operatorList = {"BETWEEN", "NOT BETWEEN"};
  auto pos = std::find(operatorList.begin(), operatorList.end(), s);
  if (pos != operatorList.end()) {
    return true;
  }
  return false;
}

bool checkNullityOperator(std::string s) {
  std::vector operatorList = {"NULL", "IS NOT NULL"};
  auto pos = std::find(operatorList.begin(), operatorList.end(), s);
  if (pos != operatorList.end()) {
    return true;
  }
  return false;
}

bool checkNestedSelect(antlr4::tree::ParseTree *ctx) {
  std::string s = ctx->getText();
  if (s.find("SELECT") != std::string::npos ||
      s.find("select") != std::string::npos) {
    return true;
  }
  return false;
}

int getChildCount(antlr4::tree::ParseTree *ctx) {
  int count = 0;
  for (int i = 0; i < ctx->children.size(); i++) {
    if (ctx->children[i]->getText() != "," &&
        ctx->children[i]->getText() != "(" &&
        ctx->children[i]->getText() != ")") {
      count++;
    }
  }
  return count;
}

std::vector<antlr4::tree::ParseTree *> identifyOperands(
    antlr4::tree::ParseTree *ctx) {
  std::vector<antlr4::tree::ParseTree *> result;
  for (int i = 0; i < ctx->children.size(); i++) {
    if (ctx->children[i]->getText() != "," &&
        ctx->children[i]->getText() != "(" &&
        ctx->children[i]->getText() != ")") {
      result.push_back(ctx->children[i]);
    }
  }
  return result;
}

std::string MyListener::toUpperCase(const std::string &input) {
  std::string result = input;
  std::transform(result.begin(), result.end(), result.begin(),
                 [](unsigned char c) { return std::toupper(c); });
  return result;
}

// Because the () is count as a terminal node even when it's not the beginning
// of children
// ... WHERE column3 IN (SELECT column4 FROM table2 WHERE column5 =
// 'some_value'); -> would have five children where [2] and [4] are terminal ()
// Need a new way to identify both positions!!! -> return only a useful vector
// of ctx children
ParserTreeNode *MyListener::parseCondition(antlr4::tree::ParseTree *ctx) {
  if (ctx->getTreeType() == antlr4::tree::ParseTreeType::TERMINAL) {
    return new Element(NODE_TYPE_SQL_VALUE, ctx->getText());
  }
  auto *tempNode = ctx;
  ParserTreeNode *myNode = nullptr;

  while (tempNode->getTreeType() != antlr4::tree::ParseTreeType::TERMINAL) {
    int childCount = getChildCount(tempNode);
    std::vector<antlr4::tree::ParseTree *> operands =
        identifyOperands(tempNode);

    if (childCount == 1) {
      tempNode = operands[0];
      continue;
    } else if (childCount == 2 &&
               checkLogicalOperator(toUpperCase(operands[0]->getText()))) {
      tempNode = operands[1];
      myNode = new Operator(OPERATOR_TYPE_LOGICAL,
                            toUpperCase(operands[0]->getText()));
      myNode->addChildNode(parseCondition(tempNode));
      return myNode;
    } else if (childCount == 3 &&
               checkLogicalOperator(toUpperCase(operands[1]->getText()))) {
      auto tempNode1 = operands[0];
      auto tempNode2 = operands[2];
      myNode = new Operator(OPERATOR_TYPE_LOGICAL,
                            toUpperCase(operands[1]->getText()));
      myNode->addChildNode(parseCondition(tempNode1));
      myNode->addChildNode(parseCondition(tempNode2));
      return myNode;
    } else if (childCount == 3 &&
               checkComparisonOperator(operands[1]->getText())) {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      ParserTreeNode *sqlValue;
      if (checkNestedSelect(operands[2])) {
        sqlValue = parseSelectStatement(operands[2]);
      } else {
        sqlValue = new Element(NODE_TYPE_SQL_VALUE, operands[2]->getText());
      }
      myNode = new Operator(OPERATOR_TYPE_COMPARISON, operands[1]->getText());
      myNode->addChildNode(colRef);
      myNode->addChildNode(sqlValue);
      return myNode;
    } else if (childCount == 3 &&
               checkSetOperator(toUpperCase(operands[1]->getText()))) {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      myNode =
          new Operator(OPERATOR_TYPE_SET, toUpperCase(operands[1]->getText()));
      ParserTreeNode *sqlValue;
      if (checkNestedSelect(operands[2])) {
        sqlValue = parseSelectStatement(operands[2]);
      } else {
        sqlValue = parseInsertSubSet(operands[2]);
      }
      myNode->addChildNode(colRef);
      myNode->addChildNode(sqlValue);
      return myNode;
    } else if (childCount == 4 && toUpperCase(operands[2]->getText()) == "IN") {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      myNode = new Operator(OPERATOR_TYPE_SET, "NOT IN");
      myNode->addChildNode(colRef);
      ParserTreeNode *sqlValue;
      if (checkNestedSelect(operands[3])) {
        sqlValue = parseSelectStatement(operands[3]);
      } else {
        sqlValue = parseInsertSubSet(operands[3]);
      }
      myNode->addChildNode(sqlValue);
      return myNode;
    } else if (childCount == 3 && checkPatternMatchingOperator(
                                      toUpperCase(operands[1]->getText()))) {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      myNode = new Operator(OPERATOR_TYPE_PATTERN_MATCHING,
                            toUpperCase(operands[1]->getText()));
      myNode->addChildNode(colRef);
      myNode->addChildNode(
          new Element(NODE_TYPE_SQL_VALUE, operands[2]->getText()));
      return myNode;
    } else if (childCount == 4 &&
               toUpperCase(operands[2]->getText()) == "LIKE") {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      myNode = new Operator(OPERATOR_TYPE_PATTERN_MATCHING, "NOT LIKE");
      myNode->addChildNode(colRef);
      myNode->addChildNode(
          new Element(NODE_TYPE_SQL_VALUE, operands[3]->getText()));
      return myNode;
    } else if (childCount == 5 &&
               checkRangeOperator(toUpperCase(operands[1]->getText()))) {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      myNode = new Operator(OPERATOR_TYPE_RANGE,
                            toUpperCase(operands[1]->getText()));
      myNode->addChildNode(colRef);
      myNode->addChildNode(
          new Element(NODE_TYPE_SQL_VALUE, operands[2]->getText()));
      myNode->addChildNode(
          new Element(NODE_TYPE_SQL_VALUE, operands[4]->getText()));
      return myNode;
    } else if (childCount == 6 && operands[1]->getText() == "NOT" &&
               checkRangeOperator(toUpperCase(operands[2]->getText()))) {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      myNode = new Operator(OPERATOR_TYPE_RANGE, "NOT BETWEEN");
      myNode->addChildNode(colRef);
      myNode->addChildNode(
          new Element(NODE_TYPE_SQL_VALUE, operands[3]->getText()));
      myNode->addChildNode(
          new Element(NODE_TYPE_SQL_VALUE, operands[5]->getText()));
      return myNode;
    } else if (childCount == 3 && operands[1]->getText() == "IS" &&
               checkNullityOperator(toUpperCase(operands[2]->getText()))) {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      auto *isNode = new Operator(OPERATOR_TYPE_NULLITY, "IS");
      auto *nullNode = new Element(NODE_TYPE_SQL_VALUE,
                                   operands[2]->getText());  // NULL node
      isNode->addChildNode(nullNode);  // Add NULL as child to IS node
      myNode = new Operator(
          OPERATOR_TYPE_NULLITY,
          operands[1]->getText() + " " + operands[2]->getText());  // IS NULL
      myNode->addChildNode(colRef);
      myNode->addChildNode(isNode);  // Add IS node as child
      return myNode;
    } else if (childCount == 3 && operands[1]->getText() == "IS" &&
               toUpperCase(operands[2]->getText()) == "NOTNULL") {
      auto *colRef = new Element(NODE_TYPE_COL_REF, operands[0]->getText());
      auto *isNode = new Operator(OPERATOR_TYPE_NULLITY, "IS");
      auto *notNode = new Operator(OPERATOR_TYPE_LOGICAL, "NOT");  // NOT node
      auto *nullNode = new Element(NODE_TYPE_SQL_VALUE, "NULL");   // NULL node
      isNode->addChildNode(notNode);   // Add NULL as child to NOT node
      isNode->addChildNode(nullNode);  // Add NOT node as child to IS node
      myNode =
          new Operator(OPERATOR_TYPE_NULLITY, "IS NOT NULL");  // IS NOT NULL
      myNode->addChildNode(colRef);
      myNode->addChildNode(isNode);  // Add IS node as child
      return myNode;
    } else if (childCount == 2 &&
                   toUpperCase(operands[0]->getText()) == "EXISTS" ||
               toUpperCase(operands[0]->getText()) == "EXIST") {
      myNode = new Operator(OPERATOR_TYPE_EXISTENCE, "EXISTS");
      myNode->addChildNode(parseSelectStatement(operands[1]));
      return myNode;
    }
  }
  return new Element(NODE_TYPE_SQL_VALUE, tempNode->getText());
}

// BFS is used to traverse the tree and help us understand the structure of the
// tree.
void MyListener::testStructure(antlr4::tree::ParseTree *ctx) {
  std::queue<antlr4::tree::ParseTree *> myQueue;
  myQueue.push(ctx);
  int level = 0;
  while (!myQueue.empty()) {
    level++;
    int size = myQueue.size();
    for (int i = 0; i < size; i++) {
      antlr4::tree::ParseTree *temp = myQueue.front();
      std::string parentName = "";
      if (temp->parent != nullptr) {
        parentName = temp->parent->getText();
      }
      std::string terminal = "";
      if (temp->getTreeType() == antlr4::tree::ParseTreeType::TERMINAL) {
        terminal = "(TERMINAL)";
      }
      std::string indenting;
      for (int j = 0; j < level; j++) {
        indenting += "  ";
      }
      PRINT(indenting << "Level " << level << ": " << temp->getText()
                << terminal << "----------"
                << "parentName: " << parentName << std::endl);
      myQueue.pop();
      for (int j = 0; j < temp->children.size(); j++) {
        myQueue.push(temp->children[j]);
      }
    }
  }
}

void MyListener::enterUpdateStatement(
    MySqlParser::UpdateStatementContext *ctx) {
  if (!FIRST_STATEMENT_ENCOUNTER) {
    return;
  }
  FIRST_STATEMENT_ENCOUNTER = false;
  parserTree->setRootNode(parseUpdateStatement(ctx));
}

void MyListener::enterDeleteStatement(
    MySqlParser::DeleteStatementContext *ctx) {
  if (!FIRST_STATEMENT_ENCOUNTER) {
    return;
  }
  FIRST_STATEMENT_ENCOUNTER = false;
  testStructure(ctx);
  parserTree->setRootNode(parseDeleteStatement(ctx));
}

void MyListener::enterInsertStatement(
    MySqlParser::InsertStatementContext *ctx) {
  if (!FIRST_STATEMENT_ENCOUNTER) {
    return;
  }
  FIRST_STATEMENT_ENCOUNTER = false;
  parserTree->setRootNode(parseInsertStatement(ctx));
}

void MyListener::enterSimpleSelect(MySqlParser::SimpleSelectContext *ctx) {
  // Do something when entering the key rule.
  // If this is not the first encounter, it means that this is a nested select
  // statement in a condition
  // TODO: 1. Dynamic Casting/type id to check the type of node to deduce if
  // recursion selected elements, from clause -> condition, terminal condition
  // -> name = "John"; col3 IN (Select statement)
  // TODO: 2. Use predetermined child position. child[0][1] -> select elements,
  // child[0][2] -> from clause
  // TODO: child[0][2][1] -> table sources
  // TODO: child[0][2][3][0] -> predicate
  // TODO: child[0][2][3][0]: [0],[1],[2],[4] are all terminal nodes, [3] is a
  // non-terminal node with a new simple select context
  // ^^^TODO: [0] column3; [1] Operator(IN); [2],[4] = ( )
  // SELECT c.customer_name, o.order_id FROM customers AS c INNER JOIN orders AS
  // o ON c.customer_id = o.customer_id WHERE c.customer_name = 'John Doe';
  // SELECT c.customer_name, o.order_id FROM customers AS c WHERE
  // c.customer_name = 'John Doe';
  if (!FIRST_STATEMENT_ENCOUNTER) {
    return;
  }
  FIRST_STATEMENT_ENCOUNTER = false;
  testStructure(ctx);
  SelectStatement *myStatement = parseSelectStatement(ctx);
  // std::cout << myStatement->toString() << std::endl;
  // updating my statement after optimization
  myStatement = Optimizer::optimizer(myStatement);
  PRINT(myStatement->toString() << std::endl);
  parserTree->setRootNode(myStatement);
  //  TODO:
  //
  // TESTING1: SELECT * FROM table1 WHERE column1 = 'value1' AND column2 =
  // 'value2'; TESTING2: SELECT * FROM table1 WHERE column1 = 10; TESTING3:
  // SELECT column1, column2 FROM table1 WHERE column3 IN (SELECT column4 FROM
  // table2 WHERE column5 = 'some_value'); TESTING4: SELECT * FROM table1 WHERE
  // NOT (column1 = 'value1'); TESTING5: SELECT column1, column2 FROM table1
  // WHERE column3 = 'value1' AND NOT column4 = 'value2'; TESTING6: SELECT *
  // FROM table1 WHERE column1 BETWEEN 100 AND 200; TESTING7: SELECT column1,
  // column2 FROM table1 WHERE NOT (column3 = 'value1' AND NOT column4 =
  // 'value2'); TESTING8-1: SELECT column1, column2 AS doubled_value FROM table1
  // WHERE doubled_value > 10; TESTING8-2: SELECT column1, column2 FROM table1
  // AS alias1; TESTING8-3: SELECT column1 AS alias1, column2 AS alias2 FROM
  // table1; X TESTING9: SELECT * FROM table1 WHERE column1 NOT IN ('value1',
  // 'value2', 'value3'); TESTING10: SELECT AVG(score) AS average_score FROM
  // scores; TESTING11: SELECT column1 FROM table1 WHERE column2 > (SELECT
  // AVG(column3) FROM table2); conclusion: 1. Logical Operators such as AND,
  // OR, NOT are one hierarchy level above most other operators
  //             2. There can sub logical operators, which will push down the
  //             hierarchy level of the operators
  //  antlr4::tree::ParseTree *temp =
  //  ctx->children[0]->children[2]->children[3]->children[0]; for(int i = 0; i
  //  < temp->children.size() ; i++){
  //    std::cout << i <<": " << temp->children[i]->getText() << std::endl;
  //  }
  // std::cout << "[0]: " <<
  // ctx->children[0]->children[2]->children[3]->children[0]->children[0]->getText()
  // << std::endl; std::cout << "4thChild: " <<
  // ctx->children[0]->children[0]->children[0]->children[0]->getText() <<
  // std::endl;
}

CreateDbStatement *MyListener::parseCreateDbStatement(tree::ParseTree *ctx) {
  auto *create_db_statement = new CreateDbStatement();
  create_db_statement->SetValue(ctx->getText());
  PRINT("create_db_statement: " << ctx->getText() << std::endl);
  create_db_statement->SetDbName(ctx->children[2]->getText());
  return create_db_statement;
}

DropDbStatement *MyListener::parseDropDbStatement(tree::ParseTree *ctx) {
  auto *drop_db_statement = new DropDbStatement();
  drop_db_statement->SetValue(ctx->getText());
  drop_db_statement->SetDbName(ctx->children[2]->getText());
  return drop_db_statement;
}

void MyListener::enterDropDatabase(MySqlParser::DropDatabaseContext *ctx) {
  if (!FIRST_STATEMENT_ENCOUNTER) {
    return;
  }
  FIRST_STATEMENT_ENCOUNTER = false;
  parserTree->setRootNode(parseDropDbStatement(ctx));
  return;
}

DropTableStatement *MyListener::parseDropTableStatement(tree::ParseTree *ctx) {
  auto *drop_table_statement = new DropTableStatement();
  drop_table_statement->SetValue(ctx->getText());
  drop_table_statement->SetTableName(ctx->children[2]->getText());
  return drop_table_statement;
}

void MyListener::enterDropTable(MySqlParser::DropTableContext *ctx) {
  if (!FIRST_STATEMENT_ENCOUNTER) {
    return;
  }
  FIRST_STATEMENT_ENCOUNTER = false;
  parserTree->setRootNode(parseDropTableStatement(ctx));
  return;
}

void MyListener::enterCreateDatabase(MySqlParser::CreateDatabaseContext *ctx) {
  // CREATE DATABASE mydatabase;
  if (!FIRST_STATEMENT_ENCOUNTER) {
    return;
  }
  FIRST_STATEMENT_ENCOUNTER = false;
  testStructure(ctx);
  auto *create_db_statement = parseCreateDbStatement(ctx);
  parserTree->setRootNode(create_db_statement);
  return;
}

void MyListener::enterSqlStatement(MySqlParser::SqlStatementContext *ctx) {
  // Do something when entering the key rule.
  PRINT("enterSqlStatement: " << ctx->getText() << std::endl);
}

CreateTableStatement *MyListener::parseCreateTableStatement(
    tree::ParseTree *ctx) {
  auto *create_table_statement = new CreateTableStatement();
  create_table_statement->SetStatement(this->statement);
  // std::cout<<"create_table_statement:
  // "<<create_table_statement->GetStatement()<<std::endl;
  create_table_statement->SetValue(ctx->getText());
  create_table_statement->SetTableName(ctx->children[2]->getText());
  tree::ParseTree *temp = ctx->children[3];
  tree::ParseTree *constraintDeclaration =
      temp->children[temp->children.size() - 2];
  if (typeid(*constraintDeclaration) ==
      typeid(MySqlParser::ConstraintDeclarationContext)) {
    for (int i = 0; i < constraintDeclaration->children.size(); i++) {
      auto constraint = constraintDeclaration->children[i];
      //        parseForeignKeyTableConstraint(constraint);
    }
  }

  std::vector<DdlConstraints> ddlConstraintsList = {};
  for (int i = 0; i < temp->children.size(); i++) {
    std::string s = temp->children[i]->getText();
    if (s == "," || s == "(" || s == ")") {
      continue;
    }
    DdlConstraints ddlConstraints = DdlConstraints();
    tree::ParseTree *ColumnDefinition = temp->children[i]->children[1];
    std::string columnName = temp->children[i]->children[0]->getText();
    std::string columnType = ColumnDefinition->children[0]->getText();
    ddlConstraints.SetColumnName(columnName);
    ddlConstraints.SetColumnType(columnType);
    std::vector<std::string> constraintList = {};
    for (int j = 1; j < ColumnDefinition->children.size(); j++) {
      auto constraintContext = ColumnDefinition->children[j];
      // check constraint type
      auto [integrityConstraintType, constraint] =
          IntegrityConstraint::FromSqlContext(constraintContext, columnName);

      std::shared_ptr<TypeConstraint> typeConstraint (new TypeConstraint());
      ddlConstraints.addColumnConstraint(IntegrityConstraintType::TYPE, typeConstraint);

      if (integrityConstraintType != IntegrityConstraintType::NONE) {
        ddlConstraints.addColumnConstraint(integrityConstraintType, constraint);
      }
      std::string tempString = ColumnDefinition->children[j]->getText();
      constraintList.push_back(ColumnDefinition->children[j]->getText());
    }
    ddlConstraints.SetColumnConstraintList(constraintList);
    ddlConstraintsList.push_back(ddlConstraints);
  }
  create_table_statement->SetColumnList(ddlConstraintsList);
  return create_table_statement;
}

UseDBStatement *MyListener::parseUseDbStatement(tree::ParseTree *ctx) {
  auto *use_db_statement = new UseDBStatement();
  use_db_statement->SetDbName(ctx->children[1]->getText());
  return use_db_statement;
}

void MyListener::enterColumnCreateTable(
    MySqlParser::ColumnCreateTableContext *ctx) {
  // CREATE TABLE table1 (column1 VARCHAR(255), column2 INT);
  // CREATE TABLE employees ( employee_id INT PRIMARY KEY NOT NULL UNIQUE,
  // first_name VARCHAR(50), last_name VARCHAR(50), hire_date DATE);
  if (!FIRST_STATEMENT_ENCOUNTER) {
    return;
  }

  FIRST_STATEMENT_ENCOUNTER = false;
  testStructure(ctx);
  CreateTableStatement *create_table_statement = parseCreateTableStatement(ctx);
  parserTree->setRootNode(create_table_statement);
  return;
}

void MyListener::enterPredicateExpression(
    MySqlParser::PredicateExpressionContext *ctx) {
  //  Condition cond = Condition();
  //  Element newCond = Element(NODE_TYPE_CONDITION, ctx->getText());
  //  cond.addChildNode(&newCond);
  //    SelectStatement* pChild = (SelectStatement*)parserTree->getRootNode();
  //    pChild->SetCondition(cond);
  //    std::cout << "enterPredicateExpression: " << ctx->getText() <<
  //    std::endl;
  //  parserTree->setRootNode(pChild);
}
void MyListener::enterSelectElements(MySqlParser::SelectElementsContext *ctx) {
  //  std::cout << "enterSelectElements:size: " << ctx->children.size() <<
  //  std::endl; for(int i = 0; i < ctx->children.size(); i++) {
  //    // ignore the comma
  //    if (ctx->children[i]->getText() == ",") {
  //      continue;
  //    }
  //    std::cout << "enterSelectElement!!: " << ctx->children[i]->getText() <<
  //    std::endl; auto temp = ctx->children[i]->getText(); std::string func =
  //    checkIfContainsFunction(ctx->children[i]->getText()); if( func != ""){
  //        auto *node = new Element(NODE_TYPE_FUNCTION, func);
  //        auto *node2 = new Element(NODE_TYPE_COL_REF, trimColWithFunc(func,
  //        ctx->children[i]->getText())); node->addChildNode(node2);
  //        SelectStatement* pChild =
  //        (SelectStatement*)parserTree->getRootNode();
  //        pChild->addToSelectList(*node);
  //        parserTree->setRootNode(pChild);
  //        continue;
  //    }
  //    auto *node = new Element(NODE_TYPE_COL_REF,
  //    ctx->children[i]->toString()); SelectStatement* pChild =
  //    (SelectStatement*)parserTree->getRootNode();
  //    pChild->addToSelectList(*node);
  //    parserTree->setRootNode(pChild);
  //  }
}
void MyListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
  // Do something when entering the key rule.
  PRINT("visitErrorNode: " << node->getText() << std::endl);
  SYNTAX_ERROR = true;
}
bool MyListener::IsSyntaxError() const { return SYNTAX_ERROR; }
void MyListener::SetSyntaxError(bool syntax_error) {
  SYNTAX_ERROR = syntax_error;
}
ParserTree *MyListener::GetParserTree() const { return parserTree; }
void MyListener::SetParserTree(ParserTree *parser_tree) {
  parserTree = parser_tree;
}
void MyListener::destroyTree() {
  if (parserTree != nullptr) {
    delete parserTree;
  }
}
MyListener::~MyListener() {
  // destroyTree();
}