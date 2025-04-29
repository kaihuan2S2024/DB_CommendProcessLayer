//
// Created by JYJ on 2023/7/3.
//

#ifndef SRCFOLDER_PARSERTREE_SELECTSTATEMENT_H_
#define SRCFOLDER_PARSERTREE_SELECTSTATEMENT_H_

#include "Join.h"
#include "SQLStatement/DMLStatement/DmlStatement.h"
#include "SQLStatement/SqlStatement.h"
#include "include/Condition.h"
#include "include/Element.h"

class SelectStatement : public DmlStatement {
 public:
  SelectStatement();
  void deleteSelectStatement();
  Result execute() override;

 private:
  std::vector<ParserTreeNode*> selectList;  // column refs
  Condition* condition;
  std::vector<Join*> joins;

 public:
  std::vector<ParserTreeNode*>& GetSelectList();
  void addToSelectList(ParserTreeNode* element);
  /*
   * */
  Condition* GetCondition();
  Join* GetFirstJoin();
  std::vector<Join*> GetJoins();
  void SetJoin(std::vector<Join*> join);
  void SetCondition(Condition* condition);
  void SetSelectList(std::vector<ParserTreeNode*> vector_1);
  std::string toString(std::string leading_space = "");
  std::string traverseConditionTree(ParserTreeNode* parserTreeNode,
                                    std::string leading_space);
  void AddJoin(Join* join);
};

#endif  // SRCFOLDER_PARSERTREE_SELECTSTATEMENT_H_
