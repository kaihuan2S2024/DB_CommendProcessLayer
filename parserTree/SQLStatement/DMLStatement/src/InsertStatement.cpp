//
// Created by JYJ on 2023/8/8.
//

#include "SQLStatement/DMLStatement/include/InsertStatement.h"

#include <utility>
void InsertStatement::SetValueList(std::vector<ParserTreeNode *> value_list) {
  this->valueList = std::move(value_list);
}
std::vector<ParserTreeNode *> InsertStatement::GetValueList() const {
  return this->valueList;
}
void InsertStatement::SetColumnList(std::vector<ParserTreeNode *> column_list) {
  this->columnList = std::move(column_list);
}
std::vector<ParserTreeNode *> InsertStatement::GetColumnList() const {
  return this->columnList;
}
void InsertStatement::addColumn(ParserTreeNode *column) {
  this->columnList.push_back(column);
}
void InsertStatement::addValue(ParserTreeNode *value) {
  this->valueList.push_back(value);
}
void InsertStatement::deleteInsertStatement() {
  for (auto &i : this->columnList) {
    delete i;
  }
  for (auto &i : this->valueList) {
    delete i;
  }
  //    for (auto & i : this->typeList) {
  //        delete i;
  //    }
  this->columnList.clear();
  this->valueList.clear();
  // this->typeList.clear();
  delete this->tableSource;
}

std::unordered_map<std::string, std::string>
InsertStatement::getColumnValueMap() {
  std::unordered_map<std::string, std::string> columnMapValue;
  for (int i = 0; i < this->columnList.size(); i++) {
    std::string columnName = this->columnList[i]->GetValue();
    std::string value = this->valueList[i]->GetValue();
    columnMapValue[columnName] = value;
  }
  return columnMapValue;
}
