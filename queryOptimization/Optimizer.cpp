#include "Optimizer.h"

#include <map>
#include <queue>

#include "MetadataManager/MetadataManager.h"

std::unordered_map<std::string, std::string> Optimizer::aliasesTable =
    std::unordered_map<std::string, std::string>();

std::unordered_map<std::string, std::string> Optimizer::oppositeOperators = {
    {"=", "!="}, {"!=", "="}, {">", "<="},
    {"<=", ">"}, {"<", ">="}, {">=", "<"}};

std::vector<std::string> splitString(const std::string &str,
                                     const char splitter) {
  std::vector<std::string> result;
  std::string current;
  for (const char i : str) {
    if (i == splitter) {
      if (!current.empty()) {
        result.push_back(current);
        current = "";
      }
      continue;
    }
    current += i;
  }
  if (!current.empty()) result.push_back(current);
  return result;
}

// Function prototype (declaration)
ParserTreeNode *bubbleNullUp(ParserTreeNode *node);

/**
 * This function restructures a given ParserTreeNode by modifying its hierarchy
 * based on its type and value. It ensures that specific operators (AND, OR,
 * NOT) are handled correctly by either deleting or modifying nodes and
 * propagating changes upwards.
 * @param node The root node from which bubbling starts.
 * @return The updated root node (ParserTreeNode*), which may be a
 * modified version of the input node. It returns nullptr if the input node is
 * nullptr.
 */
ParserTreeNode *bubbleAllUp(ParserTreeNode *node) {
  if (node == nullptr) {
    return nullptr;
  }
  auto current = node;
  if (current->getNodeType() == NODE_TYPE_OPERATOR) {
    if (current->GetValue() == "AND") {
      current = current->deleteThisNode();
      return current;
    }
    if (current->GetValue() == "OR") {
      current = current->deleteNode();
      return bubbleAllUp(current);
    }
    if (current->GetValue() == "NOT") {
      current = current->deleteNode();
      return bubbleNullUp(current);
    }
  } else if (current->getNodeType() == NODE_TYPE_CONDITION) {
    const auto allNode = ParserTreeNode::createAllNode();
    current->addChildNode(allNode);
  }
  return current;
}

/**
 * This function restructures a given ParserTreeNode by modifying its hierarchy,
 * specifically handling nodes based on operator types. Unlike bubbleAllUp, this
 * function aims to propagate null-equivalent values up the tree.
 * @param node The root node from which bubbling starts.
 * @return The updated root node (ParserTreeNode*), which may be a modified
 * version of the input node. It returns nullptr if the input node is nullptr.
 */
ParserTreeNode *bubbleNullUp(ParserTreeNode *node) {
  if (node == nullptr) {
    return nullptr;
  }
  auto current = node;
  if (current->getNodeType() == NODE_TYPE_OPERATOR) {
    if (current->GetValue() == "AND") {
      current = current->deleteNode();
      return bubbleNullUp(current);
    }
    if (current->GetValue() == "OR") {
      current = current->deleteThisNode();
      return current;
    }
    if (current->GetValue() == "NOT") {
      current = current->deleteNode();
      return bubbleAllUp(current);
    }
  } else if (current->getNodeType() == NODE_TYPE_CONDITION) {
    const auto nullNode = ParserTreeNode::createNullNode();
    current->addChildNode(nullNode);
  }
  return current;
}

SelectStatement *Optimizer::inverseLawOptimizer(SelectStatement *statement) {
  // TODO: implement it in the Lab

  return statement;
}

SelectStatement *Optimizer::absorptionLawOptimizer(SelectStatement *statement) {
  // TODO: implement it in A1

  return statement;
}

SelectStatement *Optimizer::idempotentLawOptimizer(SelectStatement *statement) {
  // TODO: implement it in A1

  return statement;
}

SelectStatement *Optimizer::distributiveOptimizer(SelectStatement *statement) {
  // TODO: implement it in A1

  return statement;
}

SelectStatement *Optimizer::deMorganLawOptimizer(SelectStatement *statement) {
  // TODO: implement it in A1

  return statement;
}

SelectStatement *Optimizer::eliminateRedundantJoinConditions(
    SelectStatement *statement) {
  // TODO: implement it in A1

  return statement;
}

// =============================================================================
// ================== Cost-based Optimization ==================================
// =============================================================================
SelectStatement *Optimizer::costBasedDeMorgansLawOptimizer(
    SelectStatement *statement,
    const std::vector<ColumnMetadata> &columnMetadata) {
  // TODO: implement it in A1
  return statement;
}

std::string Optimizer::getOppositeOperators(std::string &op) {
  return oppositeOperators[op];
};
