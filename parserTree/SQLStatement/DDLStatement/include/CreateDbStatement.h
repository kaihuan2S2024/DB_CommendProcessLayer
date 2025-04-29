//
// Created by JYJ on 2023/9/29.
//

#ifndef SRCFOLDER_PARSERTREE_CREATEDBSTATEMENT_H_
#define SRCFOLDER_PARSERTREE_CREATEDBSTATEMENT_H_

#include "SQLStatement/DDLStatement/DdlStatement.h"
#include "include/ParserTreeNode.h"

class CreateDbStatement : public DdlStatement {
 private:
  std::string db_name;

 public:
  CreateDbStatement();
  const std::string &GetDbName() const;
  void SetDbName(const std::string &db_name);
  ~CreateDbStatement() = default;
  Result execute() override;
};

#endif  // SRCFOLDER_PARSERTREE_CREATEDBSTATEMENT_H_
