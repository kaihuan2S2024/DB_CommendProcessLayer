//
// Created by Ruixia Zhong on 11/7/24.
//

#include "SQLStatement/DDLStatement/include/UseDBStatement.h"

UseDBStatement::UseDBStatement() { this->db_name = ""; }

void UseDBStatement::SetDbName(const std::string &db_name) {
  this->db_name = db_name;
}

const std::string &UseDBStatement::GetDbName() const { return db_name; }
