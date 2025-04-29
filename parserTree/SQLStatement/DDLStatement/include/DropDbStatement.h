//
// Created by JYJ on 2023/9/29.
//

#ifndef SRCFOLDER_PARSERTREE_DROPDBSTATEMENT_H_
#define SRCFOLDER_PARSERTREE_DROPDBSTATEMENT_H_

#include "SQLStatement/DDLStatement/DdlStatement.h"

class DropDbStatement : public DdlStatement {
 private:
  std::string db_name;

 public:
  const std::string &GetDbName() const;
  void SetDbName(const std::string &db_name);
  Result execute() override;

 public:
  DropDbStatement();
  ~DropDbStatement() = default;
};

#endif  // SRCFOLDER_PARSERTREE_DROPDBSTATEMENT_H_
