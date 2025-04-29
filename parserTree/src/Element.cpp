//
// Created by JYJ on 2023/7/3.
//

#include "include/Element.h"

#include "include/ParserTreeNode.h"
Element::Element(int type, std::string value) {
  this->setNodeType(type);
  this->value = value;
}
std::vector<std::string> Element::GetMySqlFunctionList() {
  const std::vector<std::string> MY_SQL_FUNCTION_LIST = {"SUM", "AVG", "COUNT",
                                                         "MAX", "MIN"};
  return MY_SQL_FUNCTION_LIST;
}
