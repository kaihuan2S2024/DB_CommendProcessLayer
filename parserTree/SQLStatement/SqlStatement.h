//
// Created by JYJ on 2023/6/22.
//

#ifndef PARSER_C_SRCFOLDER_PARSERTREE_SQLSTATEMENT_H_
#define PARSER_C_SRCFOLDER_PARSERTREE_SQLSTATEMENT_H_

#include <iostream>

#include "include/Element.h"
#include "include/ParserTreeNode.h"
#include "result.h"

enum STATEMENT_TYPE {
  STATEMENT_TYPE_SELECT = 0,
  STATEMENT_TYPE_INSERT = 1,
  STATEMENT_TYPE_UPDATE = 2,
  STATEMENT_TYPE_DELETE = 3,
  STATEMENT_TYPE_CREATE_DB = 10,
  STATEMENT_TYPE_DROP_DB = 11,
  STATEMENT_TYPE_CREATE_TABLE = 12,
  STATEMENT_TYPE_DROP_TABLE = 13,
  STATEMENT_TYPE_ALTER_TABLE = 14
};

class SqlStatement : public ParserTreeNode {
 public:
  SqlStatement() = default;
  ~SqlStatement() = default;
  virtual Result execute() {
    std::cout << "SqlStatement execute" << std::endl;
    return Result();
  };

 private:
  Element targetTable;  // table_ref
};

#endif  // PARSER_C_SRCFOLDER_PARSERTREE_SQLSTATEMENT_H_
