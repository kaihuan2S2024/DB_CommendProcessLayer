//
// Created by 钟瑞夏 on 10/9/24.
//

#ifndef COMMANDPROCESSOR_SHOWTABLES_H
#define COMMANDPROCESSOR_SHOWTABLES_H

#include "SQLStatement/SqlStatement.h"

class ShowTables : public SqlStatement {
 public:
  ShowTables() = default;
  Result execute() override;
};

#endif  // COMMANDPROCESSOR_SHOWTABLES_H
