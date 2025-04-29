//
// Created by JYJ on 2023/7/17.
//

#ifndef SRCFOLDER_PARSERTREE_OPERATOR_H_
#define SRCFOLDER_PARSERTREE_OPERATOR_H_

#include "include/Element.h"

// TODO: 1. Comparison operator: =, >, <, >=, <=
// TODO: 2. Logical operator: AND, OR, NOT
// TODO: 3. Set operator: IN, NOT IN
// TODO: 4. Pattern matching operator: LIKE, NOT LIKE
// TODO: 5. Range operator: BETWEEN, NOT BETWEEN
// TODO: 6. Nullity operator: IS NULL, IS NOT NULL
// TODO: 7. Existence operator: EXISTS, NOT EXISTS

enum OPERATOR_TYPE {
  OPERATOR_TYPE_LOGICAL = 0,
  OPERATOR_TYPE_COMPARISON = 1,
  OPERATOR_TYPE_SET = 2,
  OPERATOR_TYPE_PATTERN_MATCHING = 3,
  OPERATOR_TYPE_RANGE = 4,
  OPERATOR_TYPE_NULLITY = 5,
  OPERATOR_TYPE_EXISTENCE = 6,
  OPERATOR_TYPE_ASSIGNMENT = 7,
  OPERATOR_TYPE_ALIAS = 8,
};

class Operator : public Element {
 private:
  int operatorType;

 public:
  int GetOperatorType() const;
  void SetOperatorType(int operator_type);
  Operator(int type, std::string value);
};

#endif  // SRCFOLDER_PARSERTREE_OPERATOR_H_
