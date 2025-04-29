//
// Created by JYJ on 2023/6/27.
//

#ifndef PARSER_C_SRCFOLDER_PARSERTREE_CONDITION_H_
#define PARSER_C_SRCFOLDER_PARSERTREE_CONDITION_H_

#include <string>

#include "Operator.h"
#include "include/Element.h"
#include "include/ParserTreeNode.h"

class Condition : public ParserTreeNode {
 public:
  explicit Condition();
  ~Condition() = default;
};

#endif  // PARSER_C_SRCFOLDER_PARSERTREE_CONDITION_H_
