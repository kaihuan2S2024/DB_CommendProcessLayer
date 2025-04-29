//
// Created by JYJ on 2023/9/29.
//

#include "SQLStatement/DDLStatement/include/DropDbStatement.h"

DropDbStatement::DropDbStatement() {
  this->setNodeType(NODE_TYPE_DROP_DB_STATEMENT);
}

const std::string &DropDbStatement::GetDbName() const { return db_name; }
void DropDbStatement::SetDbName(const std::string &db_name) {
  DropDbStatement::db_name = db_name;
}
