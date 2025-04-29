//
// Created by JYJ on 2023/9/29.
//

#ifndef SRCFOLDER_PARSERTREE_DROPTABLESTATEMENT_H_
#define SRCFOLDER_PARSERTREE_DROPTABLESTATEMENT_H_

#include "SQLStatement/DDLStatement/DdlStatement.h"

class DropTableStatement : public DdlStatement {
 public:
  DropTableStatement();
  ~DropTableStatement() = default;
  const std::string &GetTableName() const;
  void SetTableName(const std::string &table_name);
  Result execute() override;

 private:
  std::string table_name;
};

#endif  // SRCFOLDER_PARSERTREE_DROPTABLESTATEMENT_H_
