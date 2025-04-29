//
// Created by Ruixia Zhong on 11/7/24.
//

#ifndef COMMANDPROCESSOR_USEDBSTATEMENT_H
#define COMMANDPROCESSOR_USEDBSTATEMENT_H

#include "SQLStatement/DDLStatement/DdlStatement.h"
class UseDBStatement : public DdlStatement {
 private:
  std::string db_name;

 public:
  UseDBStatement();
  ~UseDBStatement() = default;
  void SetDbName(const std::string &db_name);
  const std::string &GetDbName() const;
  Result execute();
};
#endif  // COMMANDPROCESSOR_USEDBSTATEMENT_H
