//
// Created by JYJ on 2023/7/3.
//
#include "SQLStatement/DMLStatement/include/SelectStatement.h"

#include <iostream>
SelectStatement::SelectStatement() {
  this->setNodeType(STATEMENT_TYPE_SELECT);
  this->selectList = std::vector<ParserTreeNode*>();
}
std::vector<ParserTreeNode*>& SelectStatement::GetSelectList() {
  return selectList;
}
Condition* SelectStatement::GetCondition() { return condition; }
void SelectStatement::SetCondition(Condition* condition) {
  SelectStatement::condition = condition;
}
void SelectStatement::addToSelectList(ParserTreeNode* element) {
  this->selectList.push_back(element);
}
// void SelectStatement::removeFromSelectList(const Element &element) {
//   for (auto it = this->selectList.begin(); it != this->selectList.end();
//   it++) {
//     if (it->GetValue() == element.GetValue()) {
//       this->selectList.erase(it);
//       break;
//     }
//   }
// }
void SelectStatement::deleteSelectStatement() {
  for (auto& i : this->selectList) {
    delete i;
  }
  this->selectList.clear();
  delete this->tableSource;
  delete this->condition;
  for (int i = 0; i < joins.size(); i++) {
    delete joins.at(i);
  }
  joins.clear();
}
void SelectStatement::SetSelectList(std::vector<ParserTreeNode*> vector_1) {
  this->selectList = vector_1;
}
Join* SelectStatement::GetFirstJoin() { return joins.at(0); }
void SelectStatement::SetJoin(std::vector<Join*> join) {
  SelectStatement::joins = join;
}

void SelectStatement::AddJoin(Join* join) { joins.push_back(join); }

std::string SelectStatement::toString(std::string leading_space) {
  std::string result;
  result += ParserTreeNode::toString(leading_space);
  result += leading_space + "|--->" + "Select List:\n";

  for (int i = 0; i < this->selectList.size(); i++) {
    result += this->selectList[i]->toString(leading_space + "|--->|--->");
  }
  result += leading_space + "|--->" + "Table Source: \n";
  result += this->tableSource->toString(leading_space + +"|--->|--->");

  if (condition != nullptr) {
    result += leading_space + "|--->" + "Condition: \n";
    result += this->condition->toString(leading_space + "|--->");
    result += traverseConditionTree(condition, leading_space + "|--->|--->");
  }

  result += leading_space + "|--->" + "Join: \n";
  for (int i = 0; i < joins.size(); i++) {
    result += this->joins.at(i)->toString(leading_space + "|--->|--->");
  }

  return result;
}
std::vector<Join*> SelectStatement::GetJoins() { return this->joins; }

std::string SelectStatement::traverseConditionTree(
    ParserTreeNode* parserTreeNode, std::string leading_space) {
  std::string result;

  if (parserTreeNode == nullptr) {
    // Handle null pointer if necessary
    return result;
  }

  std::string deeper_space = leading_space + "|--->";

  // Check if the condition node is a nested select statement
  if (parserTreeNode->getNodeType() == STATEMENT_TYPE_SELECT) {
    SelectStatement* nestedSelect = (SelectStatement*)parserTreeNode;
    result += leading_space + "Subquery: \n";
    if (nestedSelect != nullptr) {
      result += nestedSelect->toString(leading_space);
    }
  } else {
    // Process regular condition nodes
    for (auto& child : parserTreeNode->getChildrenNodes()) {
      result += traverseConditionTree(child, deeper_space);
    }
  }

  return result;
}
