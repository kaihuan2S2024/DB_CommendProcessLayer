//
// Created by JYJ on 2023/9/29.
//

#include "SQLStatement/DDLStatement/include/CreateDbStatement.h"

CreateDbStatement::CreateDbStatement() {
  this->setNodeType(NODE_TYPE_CREATE_DB_STATEMENT);
}
const std::string &CreateDbStatement::GetDbName() const { return db_name; }
void CreateDbStatement::SetDbName(const std::string &db_name) {
  CreateDbStatement::db_name = db_name;
}
