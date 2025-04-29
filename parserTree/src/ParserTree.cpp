//
// Created by JYJ on 2023/6/22.
//

#include "include/ParserTree.h"
ParserTreeNode *ParserTree::getRootNode() {
  return this->root_node_;
}
ParserTree::ParserTree() {
  auto *root_node = new ParserTreeNode();
  this->root_node_ = root_node;
}
void ParserTree::setRootNode(ParserTreeNode *root_node) {
  this->root_node_ = root_node;
}
void ParserTree::parse(antlr4::tree::ParseTree *t) {
    std::cout<<"ParserTree::parse()"<<std::endl;

}
void ParserTree::printTree() {
  std::cout<<"ParserTree::printTree()"<<std::endl;
}
ParserTree::~ParserTree() {
  if(this->root_node_ != nullptr){
    delete this->root_node_;
  }
}
