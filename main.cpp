//
//  main.cpp
//  parser_c
//

#include <iostream>
#include <regex>

#include "CapybaraMasterTable/capybara.h"
#include "CommandProcessor.h"
#include "MyListener/MyListener.h"
#include "SQLStatement/DDLStatement/include/ShowDatabases.h"
#include "SQLStatement/DDLStatement/include/ShowTables.h"
#include "antlr4-runtime.h"
#include "generated/MySqlLexer.h"
#include "generated/MySqlParser.h"
#include "MetadataManager/MetadataManager.h"

#pragma execution_character_set("utf-8")

using namespace antlrcpptest;
using namespace antlr4;

// TODO: Functions is a big thing to do!!!! e.g. select element can be AVG(),
// COUNT(), etc. for now, we only support some simple aggregate functions such
// as AVG(), COUNT(), SUM(), MAX(), MIN()
void ParseStatement() {
  std::regex exitPattern("\n*exit\n*");
  while (true) {
    std::cout << "Capybara > ";
    std::string statement;
    std::getline(std::cin, statement, ';');
    if (std::regex_match(statement, exitPattern)) {
      break;
    }

    executeSql(statement);
    // auto s2 = tree2->toStringTree(&parser);
    //        std::cout << "sqlStatement(): " << std::endl;
    //        std::cout << "Parse Tree: " << s << std::endl;
    //        tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
  }
}

void dataBaseInitialize() {
  std::cout << "Database initializing..." << std::endl;
  Capybara::initialize();
  MetadataManager &manager = MetadataManager::getInstance();
  manager.addDatabase("default");
  manager.switchDatabase("default");
  std::cout << "Database initialized!" << std::endl;
}

int main(int argc, const char *argv[]) {
  try {
    dataBaseInitialize();
    ParseStatement();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
