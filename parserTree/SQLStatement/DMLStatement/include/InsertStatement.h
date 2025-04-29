//
// Created by JYJ on 2023/8/8.
//

#ifndef SRCFOLDER_PARSERTREE_INSERTSTATEMENT_H_
#define SRCFOLDER_PARSERTREE_INSERTSTATEMENT_H_
#include <unordered_map>
#include <vector>

#include "SQLStatement/DMLStatement/DmlStatement.h"
class InsertStatement : public DmlStatement {
 private:
  std::vector<ParserTreeNode *> columnList;
  std::vector<ParserTreeNode *> valueList;

 public:
  std::vector<ParserTreeNode *> GetColumnList() const;
  void SetColumnList(std::vector<ParserTreeNode *> column_list);
  std::vector<ParserTreeNode *> GetValueList() const;
  void SetValueList(std::vector<ParserTreeNode *> value_list);
  void addColumn(ParserTreeNode *column);
  void addValue(ParserTreeNode *value);
  void deleteInsertStatement();
  std::unordered_map<std::string, std::string> getColumnValueMap();

  Result execute() override;
};

#endif  // SRCFOLDER_PARSERTREE_INSERTSTATEMENT_H_
