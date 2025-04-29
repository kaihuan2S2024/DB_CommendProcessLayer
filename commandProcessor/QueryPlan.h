//
// Created by Kai Huang on 4/29/25.
//

#ifndef QUERYPLAN_H
#define QUERYPLAN_H

#include <string>
#include <iostream>

class QueryPlan {
public:
  std::string operation;
  std::string indexUsed;
  int estimatedCost; // in milliseconds
  int rowsScanned;

  QueryPlan() : operation(""), indexUsed(""), estimatedCost(0), rowsScanned(0) {}

  void print() {
    std::cout << "Query Plan:" << std::endl;
    std::cout << "- Operation: " << operation << std::endl;
    std::cout << "- Index Used: " << (indexUsed.empty() ? "None" : indexUsed) << std::endl;
    std::cout << "- Estimated Cost: " << estimatedCost << "ms" << std::endl;
    std::cout << "- Rows Scanned: " << rowsScanned << std::endl;
  }
};

// Function to analyze a query and generate an execution plan
QueryPlan analyzeQuery(const std::string& statement);

#endif // QUERYPLAN_H