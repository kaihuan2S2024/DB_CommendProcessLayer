//
// Created by JYJ on 2023/9/28.
//
#include "SQLStatement/DMLStatement/include/Join.h"

#include <iostream>

Join::Join() { this->setNodeType(NODE_TYPE_JOIN); }

int Join::GetJoinType() const { return join_type; }
void Join::SetJoinType(int join_type) { Join::join_type = join_type; }
ParserTreeNode *Join::GetCondition() const { return condition; }
void Join::SetCondition(ParserTreeNode *condition) {
  Join::condition = condition;
}
ParserTreeNode *Join::GetTable() const { return table; }
void Join::SetTable(ParserTreeNode *table) { Join::table = table; }
std::string Join::toString(std::string leading_space) {
  std::string result;
  result += ParserTreeNode::toString(leading_space);
  result += leading_space + "|--->" +
            "Join Type: " + std::to_string(this->join_type) + "\n";
  if (this->join_type == 0) {
    return result;
  }
  result += leading_space + "|--->" + "Condition: \n";
  result += this->condition->toString(leading_space + "|--->|--->");
  result += leading_space + "|--->" + "Table: \n";
  result += this->table->toString(leading_space + "|--->|--->");
  return result;
}

Join::~Join() {
  if (join_type == 0) {
    return;
  }
  delete this->condition;
  delete this->table;
}
