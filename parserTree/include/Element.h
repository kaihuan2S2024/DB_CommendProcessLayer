//
// Created by JYJ on 2023/7/3.
//

#ifndef SRCFOLDER_PARSERTREE_ELEMENT_H_
#define SRCFOLDER_PARSERTREE_ELEMENT_H_

#include <string>

#include "include/ParserTreeNode.h"

class Element : public ParserTreeNode {
 public:
  Element() = default;
  Element(int type, std::string value);
  ~Element() = default;
  static std::vector<std::string> GetMySqlFunctionList();
};

#endif  // SRCFOLDER_PARSERTREE_ELEMENT_H_
