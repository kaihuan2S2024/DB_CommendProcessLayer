//
// Created by JYJ on 2023/9/29.
//

#include "SQLStatement/DDLStatement/include/CreateTableStatement.h"

CreateTableStatement::CreateTableStatement() {
  this->setNodeType(NODE_TYPE_CREATE_TABLE_STATEMENT);
}

void CreateTableStatement::SetStatement(const std::string &statement) {
  CreateTableStatement::statement = statement;
}

const std::string CreateTableStatement::GetStatement() const {
  return statement;
}

const std::string &CreateTableStatement::GetTableName() const {
  return table_name;
}
void CreateTableStatement::SetTableName(const std::string &table_name) {
  CreateTableStatement::table_name = table_name;
}
const std::vector<DdlConstraints> &CreateTableStatement::GetColumnList() const {
  return column_list;
}
void CreateTableStatement::SetColumnList(
    const std::vector<DdlConstraints> &column_list) {
  CreateTableStatement::column_list = column_list;
}
void CreateTableStatement::AddColumn(DdlConstraints &column) {
  column_list.push_back(column);
}
