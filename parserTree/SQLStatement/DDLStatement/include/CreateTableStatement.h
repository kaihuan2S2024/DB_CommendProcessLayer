//
// Created by JYJ on 2023/9/29.
//

#ifndef SRCFOLDER_PARSERTREE_CREATETABLESTATEMENT_H_
#define SRCFOLDER_PARSERTREE_CREATETABLESTATEMENT_H_

#include "IntegrityChecker/DdlConstraints.h"
#include "SQLStatement/DDLStatement/DdlStatement.h"

class CreateTableStatement : public DdlStatement {
 private:
  std::string table_name;
  std::vector<DdlConstraints> column_list;
  std::string statement;

 public:
  CreateTableStatement();
  ~CreateTableStatement() = default;
  void SetStatement(const std::string &statement);
  const std::string &GetTableName() const;
  const std::string GetStatement() const;
  void SetTableName(const std::string &table_name);
  const std::vector<DdlConstraints> &GetColumnList() const;
  void SetColumnList(const std::vector<DdlConstraints> &column_list);
  void AddColumn(DdlConstraints &column);
  SQL_TYPE determineSqlType(const std::string &columnType);
  Result execute();
};

#endif  // SRCFOLDER_PARSERTREE_CREATETABLESTATEMENT_H_
