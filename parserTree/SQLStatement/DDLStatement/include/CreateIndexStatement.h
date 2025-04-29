//
// Created by Kai Huang on 4/29/25.
//

#ifndef CREATE_INDEX_STATEMENT_H
#define CREATE_INDEX_STATEMENT_H

#include "SQLStatement/DDLStatement/DdlStatement.h"

class CreateIndexStatement : public DdlStatement {
private:
  std::string indexName;
  std::string tableName;
  std::string columnName;

public:
  CreateIndexStatement();
  ~CreateIndexStatement() = default;

  const std::string &GetIndexName() const;
  void SetIndexName(const std::string &index_name);

  const std::string &GetTableName() const;
  void SetTableName(const std::string &table_name);

  const std::string &GetColumnName() const;
  void SetColumnName(const std::string &column_name);

  Result execute() override;
};

#endif // CREATE_INDEX_STATEMENT_H
