//
// Created by JYJ on 2023/8/8.
//

#ifndef SRCFOLDER_PARSERTREE_DELETESTATEMENT_H_
#define SRCFOLDER_PARSERTREE_DELETESTATEMENT_H_

#include <vector>

#include "SQLStatement/DMLStatement/DmlStatement.h"
#include "include/Condition.h"

class DeleteStatement : public DmlStatement {
 private:
  Condition *condition;

 public:
  Condition *GetCondition() const;
  void SetCondition(Condition *condition);
  void deleteDeleteStatement();
  Result execute() override;
};

#endif  // SRCFOLDER_PARSERTREE_DELETESTATEMENT_H_
