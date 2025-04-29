#include <algorithm>
#include <regex>

#include "CommandProcessor.h"
#include "CapybaraMasterTable/capybara.h"
#include "MetadataManager/MetadataManager.h"
#include "log.h"

#include <benchmark/benchmark.h>

// Memory Allocation count
#include <gperftools/malloc_hook.h>  // link tcmalloc

benchmark::IterationCount g_num_new = 0;
benchmark::IterationCount g_sum_size_new = 0;
benchmark::IterationCount g_max_size_new = 0;
benchmark::IterationCount g_min_size_new = -1;

auto new_hook = [](const void *, size_t size) {
  ++g_num_new;
  g_sum_size_new += size;
  g_max_size_new = std::max(g_max_size_new, (int64_t) size);
  g_min_size_new = std::min(g_min_size_new, (int64_t) size);
};

#define BEFORE_TEST                                        \
  benchmark::IterationCount num_new = g_num_new;           \
  benchmark::IterationCount sum_size_new = g_sum_size_new; \
  g_max_size_new = 0;                                      \
  g_min_size_new = -1;                                     \
  MallocHook::AddNewHook(new_hook);

#define AFTER_TEST                                                      \
  MallocHook::RemoveNewHook(new_hook);                                  \
  auto iter = state.iterations();                                       \
  state.counters["#new"] = (g_num_new - num_new) / iter;                \
  state.counters["sum_new_size"] = (g_sum_size_new - sum_size_new) / iter; \
  state.counters["avg_new_size"] =                                         \
      (g_sum_size_new - sum_size_new) / (g_num_new - num_new);          \
  state.counters["max_new_size"] = g_max_size_new;                         \
  if (((benchmark::IterationCount) - 1) != g_min_size_new) {            \
    state.counters["min_new_size"] = g_min_size_new;                       \
  }

#define DATASET_SIZE 10000

static void cleanTables() {
  executeSql("DROP TABLE IF EXISTS PERSON;");
}

static void initTables() {
  cleanTables();
  executeSql("CREATE TABLE PERSON (person_id INT);");
  for (int i = 0; i < DATASET_SIZE; i++) {
    std::stringstream ss;
    ss << "INSERT INTO PERSON (person_id) VALUES (" << i << ");";
    std::string formatted_string = ss.str();
    executeSql(formatted_string);
  }
}

static void GlobalSetup() {
  capybara::enablePrint = false;
  std::filesystem::remove_all("db");

  Capybara::initialize();
  MetadataManager &manager = MetadataManager::getInstance();
  manager.addDatabase("default");
  manager.switchDatabase("default");

  std::cout << "Database initialized. Initializing Tables" << std::endl;
  initTables();
  std::cout << "Tables Initialized" << std::endl;
}

static void GlobalTeardown() {
  cleanTables();
  std::filesystem::remove_all("db");
}

static void InitTable(benchmark::State &state) {
  BEFORE_TEST
  for (auto _ : state) {
    executeSql("select * from PERSON WHERE person_id > 5000;");
  }
  AFTER_TEST
}

static void CreateIndex(benchmark::State &state) {
  BEFORE_TEST
  for (auto _ : state) {
    executeSql("select * from PERSON;");
  }
  AFTER_TEST
}

static void SelectAll(benchmark::State &state) {
  for (auto _ : state) {
    executeSql("select * from PERSON;");
  }
}

static void SelectWhereEquals(benchmark::State &state) {
  for (auto _ : state) {
    executeSql("select * from PERSON WHERE person_id = 5000;");
  }
}

static void SelectWhereGreaterThan(benchmark::State &state) {
  for (auto _ : state) {
    executeSql("select * from PERSON WHERE person_id > 5000;");
  }
}

static void SelectWhereRange(benchmark::State &state) {
  for (auto _ : state) {
    executeSql("select * from PERSON WHERE person_id > 2500 AND person_id < 7500;");
  }
}

static void SelectWhereBetween(benchmark::State &state) {
  for (auto _ : state) {
    executeSql("select * from PERSON WHERE person_id BETWEEN 2500 AND 7500;");
  }
}

BENCHMARK(InitTable)->Unit(benchmark::kMillisecond);
BENCHMARK(CreateIndex)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectAll)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectWhereEquals)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectWhereGreaterThan)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectWhereRange)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectWhereBetween)->Unit(benchmark::kMillisecond);

int main(int argc, char** argv) {
  char arg0_default[] = "benchmark";
  char* args_default = arg0_default;
  if (!argv) {
    argc = 1;
    argv = &args_default;
  }
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
  GlobalSetup();
  ::benchmark::RunSpecifiedBenchmarks();
  ::benchmark::Shutdown();
  GlobalTeardown();
  return 0;
}
