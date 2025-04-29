//
// Created by JYJ on 2023/7/17.
//

#include "include/Operator.h"

#include "include/ParserTreeNode.h"
int Operator::GetOperatorType() const { return operatorType; }
void Operator::SetOperatorType(int operator_type) {
  operatorType = operator_type;
}
Operator::Operator(int type, std::string value) {
  this->setNodeType(NODE_TYPE_OPERATOR);
  this->SetValue(value);
  this->operatorType = type;
}
