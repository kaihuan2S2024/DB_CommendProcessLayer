//
// Created by Yang Liu on 4/28/25.
//

#include <algorithm>
#include <random>
#include <regex>

#include "CapybaraMasterTable/capybara.h"
#include "CommandProcessor.h"
#include "MetadataManager/MetadataManager.h"
#include "log.h"

#define DATASET_SIZE 50

const std::string SELECT_WHERE_SMALLER = "select * from benchmark WHERE id < " + std::to_string(DATASET_SIZE/10) + ";";
const std::string SELECT_WHERE_RANGE = "select * from benchmark WHERE id > " + std::to_string(DATASET_SIZE/4) + " AND id < " + std::to_string(DATASET_SIZE*3/4) +";";
const std::string SELECT_WHERE_BETWEEN = "select * from benchmark WHERE id BETWEEN " + std::to_string(DATASET_SIZE/4) + " AND " + std::to_string(DATASET_SIZE*3/4) +";";

int main() {
  capybara::enablePrint = false;
  std::filesystem::remove_all("db");
  std::filesystem::remove_all("metadata");

  Capybara::initialize();
  MetadataManager &manager = MetadataManager::getInstance();
  manager.addDatabase("default");
  manager.switchDatabase("default");

  // 1. Get Index disk usage
  std::cout << "Database initialized. Initializing Tables" << std::endl;
  // executeSql("CREATE TABLE benchmark (id INT primary key, name VARCHAR(8));");
  executeSql("CREATE TABLE benchmark (id INT);");
  for (int i = 0; i < DATASET_SIZE; i++) {
    std::stringstream ss;
    // ss << "INSERT INTO benchmark (id, name) VALUES (" << i << ", \"" << std::to_string(i) << "\");";
    ss << "INSERT INTO benchmark (id) VALUES (" << i << ");";
    std::string formatted_string = ss.str();
    executeSql(formatted_string);
    // std::cout << i << std::endl;
  }

  executeSql("select * from benchmark;");

  auto table_size_before = std::filesystem::file_size("db/default.db");
  std::cout << "CREATE TABLE db/default.db file size is " << table_size_before << "B" << std::endl;

  std::cout << "Creating Indexes." << std::endl;
  executeSql("CREATE INDEX idx_id ON benchmark (id);");
  auto table_size_after_id = std::filesystem::file_size("db/default.db");
  std::cout << "CREATE INDEX db/default.db file size is " << table_size_after_id << "B" << std::endl;
  std::cout << "INDEX idx_id disk usage is " << table_size_after_id - table_size_before << "B" << std::endl;

  executeSql("CREATE INDEX idx_name ON benchmark (name);");
  auto table_size_after_name = std::filesystem::file_size("db/default.db");
  std::cout << "CREATE INDEX db/default.db file size is " << table_size_after_name << "B" << std::endl;
  std::cout << "INDEX idx_name disk usage is " << table_size_after_name - table_size_after_id << "B" << std::endl;

  executeSql("select * from benchmark;");
  for (int i = 0; i < DATASET_SIZE; i++) {
    executeSql("select * from benchmark WHERE id = " + std::to_string(i) + ";");
  }
  executeSql(SELECT_WHERE_SMALLER);
  executeSql(SELECT_WHERE_RANGE);
  executeSql(SELECT_WHERE_BETWEEN);
}