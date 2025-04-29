//
// Created by JYJ on 2023/6/22.
//

#ifndef PARSER_C_SRCFOLDER_PARSERTREE_PARSERTREENODE_H_
#define PARSER_C_SRCFOLDER_PARSERTREE_PARSERTREENODE_H_

#include <string>
#include <vector>

enum NODE_TYPE {
  NODE_TYPE_SELECT_STATEMENT = 0,
  NODE_TYPE_INSERT_STATEMENT = 1,
  NODE_TYPE_UPDATE_STATEMENT = 2,
  NODE_TYPE_DELETE_STATEMENT = 3,
  NODE_TYPE_CREATE_DB_STATEMENT = 10,
  NODE_TYPE_DROP_DB_STATEMENT = 11,
  NODE_TYPE_CREATE_TABLE_STATEMENT = 12,
  NODE_TYPE_DROP_TABLE_STATEMENT = 13,
  NODE_TYPE_ALTER_TABLE_STATEMENT = 14,
  NODE_TYPE_CREATE_INDEX_STATEMENT = 15,  // Added for B+ Tree indexing
  NODE_TYPE_DROP_INDEX_STATEMENT = 16,    // Added for B+ Tree indexing
  NODE_TYPE_EXPLAIN_STATEMENT = 17,       // Added for EXPLAIN feature
  NODE_TYPE_OPERATOR = 20,
  NODE_TYPE_COL_REF = 21,
  NODE_TYPE_TABLE_REF = 22,
  NODE_TYPE_CONSTRAINT = 23,
  NODE_TYPE_SQL_VALUE = 24,
  NODE_TYPE_SQL_TYPE_KEYWORD = 25,
  NODE_TYPE_FUNCTION = 26,
  NODE_TYPE_ALIAS = 27,
  NODE_TYPE_ASSIGNMENT = 40,
  NODE_TYPE_CONDITION = 41,
  NODE_TYPE_CONDITION_GROUP = 42,
  NODE_TYPE_JOIN = 50,
  // null = 0, all = 1
  NODE_TYPE_NULL = 100,
  NODE_TYPE_ALL = 101,
};

class ParserTreeNode {
 protected:
  std::string value;

 public:
  ParserTreeNode();
  ~ParserTreeNode();
  int getNodeType();
  ParserTreeNode* getParentNode();
  std::vector<ParserTreeNode*> getChildrenNodes();
  void setNodeType(int node_type);
  void setParentNode(ParserTreeNode* parent_node);
  void addChildNode(ParserTreeNode* child_node);
  void deleteChildNode(ParserTreeNode* child_node);
  ParserTreeNode* deleteNode();
  ParserTreeNode* deleteThisNode();
  ParserTreeNode* moveNode(ParserTreeNode* new_parent_node);
  const std::string& GetValue() const;
  void SetValue(const std::string& value);
  std::string toString(std::string leading_space = "");
  static ParserTreeNode* createNullNode();
  static ParserTreeNode* createAllNode();

 private:
  int node_type_;
  ParserTreeNode* parent_node_;
  // std::string node_value_;
  std::vector<ParserTreeNode*> children_nodes_;
};

#endif  // PARSER_C_SRCFOLDER_PARSERTREE_PARSERTREENODE_H_
