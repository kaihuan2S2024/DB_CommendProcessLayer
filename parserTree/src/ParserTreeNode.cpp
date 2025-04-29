//
// Created by JYJ on 2023/6/22.
//

#include "include/ParserTreeNode.h"

#include <iostream>

#include "SQLStatement/DMLStatement/include/DeleteStatement.h"
#include "SQLStatement/DMLStatement/include/InsertStatement.h"
#include "SQLStatement/DMLStatement/include/SelectStatement.h"
#include "SQLStatement/DMLStatement/include/UpdateStatement.h"
#include "include/Element.h"
ParserTreeNode::ParserTreeNode() {
  this->parent_node_ = nullptr;
  this->children_nodes_ = std::vector<ParserTreeNode *>();
  this->node_type_ = -1;
  this->value = "";
}
int ParserTreeNode::getNodeType() { return this->node_type_; }
ParserTreeNode *ParserTreeNode::getParentNode() { return this->parent_node_; }
std::vector<ParserTreeNode *> ParserTreeNode::getChildrenNodes() {
  return this->children_nodes_;
}
void ParserTreeNode::setNodeType(int node_type) {
  this->node_type_ = node_type;
}
void ParserTreeNode::setParentNode(ParserTreeNode *parent_node) {
  // Does not add to child Node!!!
  this->parent_node_ = parent_node;
  // parent_node->addChildNode(this);
}
void ParserTreeNode::addChildNode(ParserTreeNode *child_node) {
  this->children_nodes_.push_back(child_node);
  child_node->setParentNode(this);
}
void ParserTreeNode::deleteChildNode(ParserTreeNode *child_node) {
  for (int i = 0; i < this->children_nodes_.size(); i++) {
    if (this->children_nodes_[i] == child_node) {
      this->children_nodes_.erase(this->children_nodes_.begin() + i);
      break;
    }
  }
}
ParserTreeNode *ParserTreeNode::deleteNode() {
  ParserTreeNode *parent = this->getParentNode();
  if (parent != nullptr) {
    parent->deleteChildNode(this);
  }
  // delete this;
  return parent;
}

ParserTreeNode *ParserTreeNode::deleteThisNode() {
  ParserTreeNode *parent = this->getParentNode();
  if (parent != nullptr) {
    std::vector<ParserTreeNode *> children = this->getChildrenNodes();
    parent->deleteChildNode(this);
    for (ParserTreeNode *p : children) {
      parent->addChildNode(p);
    }
  }
  return parent;
}

ParserTreeNode *ParserTreeNode::moveNode(ParserTreeNode *new_parent_node) {
  ParserTreeNode *parent = this->getParentNode();
  if (parent != nullptr) {
    parent->deleteChildNode(this);
  }
  new_parent_node->addChildNode(this);
  return this;
}
ParserTreeNode::~ParserTreeNode() {
  if (this->node_type_ == NODE_TYPE_SELECT_STATEMENT) {
    // TODO: FIX THIS DESTRUCTOR FOR CUSTOM NODES SUCH AS SELECT STATEMENT
    // We can use virtual destructor to solve this problem
    // SELECT * FROM table1 WHERE table1.a = 1;
    auto *select_statement = (SelectStatement *)this;
    select_statement->deleteSelectStatement();
    return;
  } else if (this->node_type_ == NODE_TYPE_INSERT_STATEMENT) {
    auto insertStatement = (InsertStatement *)this;
    insertStatement->deleteInsertStatement();
    return;
  } else if (this->node_type_ == NODE_TYPE_DELETE_STATEMENT) {
    auto deleteStatement = (DeleteStatement *)this;
    deleteStatement->deleteDeleteStatement();
    return;
  } else if (this->node_type_ == NODE_TYPE_UPDATE_STATEMENT) {
    auto updateStatement = (UpdateStatement *)this;
    updateStatement->deleteUpdateStatement();
    return;
  } else {
    if (this->getChildrenNodes().empty()) {
      return;
    }
    for (ParserTreeNode *p : this->getChildrenNodes()) {
      delete p;
    }
    this->getChildrenNodes().clear();
  }
}

const std::string &ParserTreeNode::GetValue() const { return value; }
void ParserTreeNode::SetValue(const std::string &value) {
  ParserTreeNode::value = value;
}

std::string ParserTreeNode::toString(std::string leading_space) {
  std::string result;
  result += leading_space +
            "[Node Type: " + std::to_string(this->getNodeType()) +
            " || Node Value: " + this->GetValue() + "]\n";
  for (int i = 0; i < this->getChildrenNodes().size(); i++) {
    result += getChildrenNodes()[i]->toString(leading_space + "|--->");
  }
  return result;
}
ParserTreeNode *ParserTreeNode::createNullNode() {
  ParserTreeNode *node = new ParserTreeNode();
  node->setNodeType(NODE_TYPE_NULL);
  node->SetValue("NULL");
  return node;
}
ParserTreeNode *ParserTreeNode::createAllNode() {
  ParserTreeNode *node = new ParserTreeNode();
  node->setNodeType(NODE_TYPE_ALL);
  node->SetValue("ALL");
  return node;
}
