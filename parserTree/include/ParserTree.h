//
// Created by JYJ on 2023/6/22.
//

#ifndef PARSER_C_SRCFOLDER_PARSERTREE_PARSERTREE_H_
#define PARSER_C_SRCFOLDER_PARSERTREE_PARSERTREE_H_

#include "ParseTree.h"
#include "ParserTreeNode.h"
#include "SQLStatement/DMLStatement/include/SelectStatement.h"

class ParserTree {
 public:
  ParserTree();
  ~ParserTree();
  ParserTreeNode *getRootNode();
  void setRootNode(ParserTreeNode *root_node);
  void parse(antlr4::tree::ParseTree *t);
  void printTree();

 private:
  ParserTreeNode *root_node_;
};

#endif  // PARSER_C_SRCFOLDER_PARSERTREE_PARSERTREE_H_
