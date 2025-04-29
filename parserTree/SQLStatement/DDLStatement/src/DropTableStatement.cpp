//
// Created by JYJ on 2023/9/29.
//

#include "SQLStatement/DDLStatement/include/DropTableStatement.h"

#include "include/ParserTreeNode.h"
DropTableStatement::DropTableStatement() {
  this->setNodeType(NODE_TYPE_DROP_TABLE_STATEMENT);
}

const std::string &DropTableStatement::GetTableName() const {
  return table_name;
}
void DropTableStatement::SetTableName(const std::string &table_name) {
  DropTableStatement::table_name = table_name;
}
