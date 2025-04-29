//
// Created by JYJ on 2023/9/28.
//

#ifndef SRCFOLDER_PARSERTREE_JOIN_H_
#define SRCFOLDER_PARSERTREE_JOIN_H_

#include "include/Condition.h"
#include "include/ParserTreeNode.h"

enum JOIN_TYPE {
  NO_JOIN = 0,
  INNER_JOIN = 1,
  OUTER_JOIN = 2,
  CROSS_JOIN = 3,
  NATURAL_JOIN = 4,
};

class Join : public ParserTreeNode {
 private:
  int join_type;
  ParserTreeNode *condition;
  ParserTreeNode *table;

 public:
  int GetJoinType() const;
  void SetJoinType(int join_type);
  ParserTreeNode *GetCondition() const;
  void SetCondition(ParserTreeNode *condition);
  ParserTreeNode *GetTable() const;
  void SetTable(ParserTreeNode *table);
  std::string toString(std::string leading_space = "");

 public:
  Join();
  ~Join();
};

#endif  // SRCFOLDER_PARSERTREE_JOIN_H_
