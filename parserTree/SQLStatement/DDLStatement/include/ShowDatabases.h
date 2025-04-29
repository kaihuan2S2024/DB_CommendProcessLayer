//
// Created by 钟瑞夏 on 11/7/24.
//

#ifndef COMMANDPROCESSOR_SHOWDATABASES_H
#define COMMANDPROCESSOR_SHOWDATABASES_H

#include "SQLStatement/SqlStatement.h"

class ShowDatabases : public SqlStatement {
 public:
  ShowDatabases() = default;
  Result execute() override;
};
#endif  // COMMANDPROCESSOR_SHOWDATABASES_H
