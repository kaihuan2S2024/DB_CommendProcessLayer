//
// Created by JYJ on 2023/6/27.
//

#ifndef PARSER_C_SRCFOLDER_PARSERTREE_DMLSTATEMENT_H_
#define PARSER_C_SRCFOLDER_PARSERTREE_DMLSTATEMENT_H_

#include "SQLStatement/SqlStatement.h"

class DmlStatement : public SqlStatement {
 protected:
  ParserTreeNode *tableSource;

 public:
  ParserTreeNode *const GetTableSource() const;
  void SetTableSource(ParserTreeNode *table_source);
};

#endif  // PARSER_C_SRCFOLDER_PARSERTREE_DMLSTATEMENT_H_
