//
// Created by JYJ on 2023/8/8.
//

#include "SQLStatement/DMLStatement/include/DeleteStatement.h"
Condition *DeleteStatement::GetCondition() const { return condition; }
void DeleteStatement::SetCondition(Condition *condition) {
  DeleteStatement::condition = condition;
}
void DeleteStatement::deleteDeleteStatement() {
  delete this->condition;
  delete this->tableSource;
}
