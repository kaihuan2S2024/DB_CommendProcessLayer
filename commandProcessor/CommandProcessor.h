//
// Created by Yang Liu on 3/26/25.
//

#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <string>
#include "QueryPlan.h"

void executeSql(const std::string &statement);

// Function to handle CREATE INDEX statements
void handleCreateIndex(const std::string &statement);

#endif //COMMANDPROCESSOR_H
