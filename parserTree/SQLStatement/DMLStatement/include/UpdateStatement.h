//
// Created by JYJ on 2023/8/7.
//

#ifndef SRCFOLDER_PARSERTREE_UPDATESTATEMENT_H_
#define SRCFOLDER_PARSERTREE_UPDATESTATEMENT_H_

#include <vector>

#include "SQLStatement/DMLStatement/DmlStatement.h"
#include "include/Condition.h"
class UpdateStatement : public DmlStatement {
 public:
  UpdateStatement();
  void deleteUpdateStatement();
  const std::vector<ParserTreeNode *> &GetUpdateList() const;
  void SetUpdateList(const std::vector<ParserTreeNode *> &update_list);
  Condition *GetCondition() const;
  void SetCondition(Condition *condition);
  Result execute() override;

 private:
  std::vector<ParserTreeNode *> update_list_;
  Condition *condition;
};

#endif  // SRCFOLDER_PARSERTREE_UPDATESTATEMENT_H_
