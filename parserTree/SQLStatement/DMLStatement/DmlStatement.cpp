//
// Created by JYJ on 2023/6/27.
//

#include "SQLStatement/DMLStatement/DmlStatement.h"
ParserTreeNode *const DmlStatement::GetTableSource() const {
  return this->tableSource;
}

void DmlStatement::SetTableSource(ParserTreeNode *table_source) {
  this->tableSource = table_source;
}
