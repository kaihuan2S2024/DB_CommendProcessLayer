//
// Created by JYJ on 2023/8/7.
//

#include "SQLStatement/DMLStatement/include/UpdateStatement.h"
UpdateStatement::UpdateStatement() {
  this->setNodeType(STATEMENT_TYPE_UPDATE);
  this->update_list_ = std::vector<ParserTreeNode *>();
}
void UpdateStatement::deleteUpdateStatement() {
  for (int i = 0; i < this->update_list_.size(); i++) {
    delete this->update_list_[i];
  }
  this->update_list_.clear();
  delete this->tableSource;
  delete this->condition;
}
const std::vector<ParserTreeNode *> &UpdateStatement::GetUpdateList() const {
  return update_list_;
}
void UpdateStatement::SetUpdateList(
    const std::vector<ParserTreeNode *> &update_list) {
  update_list_ = update_list;
}
Condition *UpdateStatement::GetCondition() const { return condition; }
void UpdateStatement::SetCondition(Condition *condition) {
  UpdateStatement::condition = condition;
}
