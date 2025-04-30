#include <benchmark/benchmark.h>
#include <algorithm>
#include <regex>

#include "CapybaraMasterTable/capybara.h"
#include "CommandProcessor.h"
#include "MetadataManager/MetadataManager.h"
#include "log.h"

// Memory Allocation count
// #include <gperftools/malloc_hook.h>  // link tcmalloc

#include <random>

benchmark::IterationCount g_num_new = 0;
benchmark::IterationCount g_sum_size_new = 0;
benchmark::IterationCount g_max_size_new = 0;
benchmark::IterationCount g_min_size_new = -1;

auto new_hook = [](const void *, size_t size) {
  ++g_num_new;
  g_sum_size_new += size;
  g_max_size_new = std::max(g_max_size_new, (int64_t)size);
  g_min_size_new = std::min(g_min_size_new, (int64_t)size);
};

#define MEM_BEFORE_TEST                                        \
  benchmark::IterationCount num_new = g_num_new;           \
  benchmark::IterationCount sum_size_new = g_sum_size_new; \
  g_max_size_new = 0;                                      \
  g_min_size_new = -1;                                     \
  // MallocHook::AddNewHook(new_hook);

#define MEM_AFTER_TEST                                                         \
  auto iter_mem = state.iterations();                                          \
  state.counters["#new"] = (g_num_new - num_new) / iter_mem;                   \
  state.counters["sum_new_size"] = (g_sum_size_new - sum_size_new) / iter_mem; \
  state.counters["avg_new_size"] =                                         \
      (g_sum_size_new - sum_size_new) / (g_num_new - num_new);             \
  state.counters["max_new_size"] = g_max_size_new;                         \
  if (((benchmark::IterationCount) - 1) != g_min_size_new) {               \
    state.counters["min_new_size"] = g_min_size_new;                       \
  }
  // MallocHook::RemoveNewHook(new_hook);                                     \

// File IO ops
#include "fishhook.h"

benchmark::IterationCount g_num_read = 0;
benchmark::IterationCount g_sum_size_read = 0;
benchmark::IterationCount g_max_size_read = 0;
benchmark::IterationCount g_min_size_read = -1;
benchmark::IterationCount g_num_write = 0;
benchmark::IterationCount g_sum_size_write = 0;
benchmark::IterationCount g_max_size_write = 0;
benchmark::IterationCount g_min_size_write = -1;

static int (*orig_read)(int, void *, size_t);
static int (*orig_write)(int, const void *, size_t);

int read_hook(int fildes, void *buf, size_t nbyte) {
  ++g_num_read;
  g_sum_size_read += nbyte;
  g_max_size_read = std::max(g_max_size_read, (int64_t)nbyte);
  g_min_size_read = std::min(g_min_size_read, (int64_t)nbyte);
  return orig_read(fildes, buf, nbyte);
};

int write_hook(int fildes, const void *buf, size_t nbyte) {
  ++g_num_write;
  g_sum_size_write += nbyte;
  g_max_size_write = std::max(g_max_size_write, (int64_t)nbyte);
  g_min_size_write = std::min(g_min_size_write, (int64_t)nbyte);
  return orig_write(fildes, buf, nbyte);
};

#define IO_BEFORE_TEST                                                      \
  benchmark::IterationCount num_read = g_num_read;                          \
  benchmark::IterationCount sum_size_read = g_sum_size_read;                \
  g_max_size_read = 0;                                                      \
  g_min_size_read = -1;                                                     \
  benchmark::IterationCount num_write = g_num_write;                        \
  benchmark::IterationCount sum_size_write = g_sum_size_write;              \
  g_max_size_write = 0;                                                     \
  g_min_size_write = -1;                                                    \
  rebind_symbols(                                                           \
      (struct rebinding[2]){{"read", reinterpret_cast<void *>(read_hook),   \
                             reinterpret_cast<void **>(&orig_read)},        \
                            {"write", reinterpret_cast<void *>(write_hook), \
                             reinterpret_cast<void **>(&orig_write)}},      \
      2);

#define IO_AFTER_TEST                                                         \
  rebind_symbols(                                                             \
      (struct rebinding[2]){{"read", reinterpret_cast<void *>(orig_read),     \
                             reinterpret_cast<void **>(&orig_read)},          \
                            {"write", reinterpret_cast<void **>(orig_write),  \
                             reinterpret_cast<void **>(&orig_write)}},        \
      2);                                                                     \
  auto iter_io = state.iterations();                                             \
  state.counters["#read"] = (g_num_read - num_read) / iter_io;                   \
  state.counters["sum_read_size"] = (g_sum_size_read - sum_size_read) / iter_io; \
  state.counters["avg_read_size"] =                                           \
      (g_sum_size_read - sum_size_read) / (g_num_read - num_read);            \
  state.counters["max_read_size"] = g_max_size_read;                          \
  if (((benchmark::IterationCount) - 1) != g_min_size_read) {                 \
    state.counters["min_read_size"] = g_min_size_read;                        \
  }                                                                           \
  state.counters["#write"] = (g_num_write - num_write) / iter_io;                \
  state.counters["sum_write_size"] =                                          \
      (g_sum_size_write - sum_size_write) / iter_io;                             \
  state.counters["avg_write_size"] =                                          \
      (g_sum_size_write - sum_size_write) / (g_num_write - num_write);        \
  state.counters["max_write_size"] = g_max_size_write;                        \
  if (((benchmark::IterationCount) - 1) != g_min_size_write) {                \
    state.counters["min_write_size"] = g_min_size_write;                      \
  }

#define DATASET_SIZE 50

const std::string SELECT_WHERE_EQUALS = "select * from benchmark WHERE id = " + std::to_string(DATASET_SIZE/2) + ";";
const std::string SELECT_WHERE_SMALLER = "select * from benchmark WHERE id < " + std::to_string(DATASET_SIZE/10) + ";";
const std::string SELECT_WHERE_RANGE = "select * from benchmark WHERE id > " + std::to_string(DATASET_SIZE/4) + " AND id < " + std::to_string(DATASET_SIZE*3/4) +";";
const std::string SELECT_WHERE_BETWEEN = "select * from benchmark WHERE id BETWEEN " + std::to_string(DATASET_SIZE/4) + " AND " + std::to_string(DATASET_SIZE*3/4) +";";

// These keys will be deleted and inserted again
auto KeyWillVanish(size_t key) -> bool { return key % 7 == 0; }

// These keys will be overwritten to a new value
auto KeyWillChange(size_t key) -> bool { return key % 5 == 0; }

static void cleanTables() { executeSql("DROP TABLE IF EXISTS benchmark;"); }

static void cleanIndex() {
  executeSql("DROP INDEX idx_id ON benchmark;");
}

static void initDB() {
  std::filesystem::remove_all("db");
  std::filesystem::remove_all("metadata");

  Capybara::initialize();
  MetadataManager &manager = MetadataManager::getInstance();
  manager.addDatabase("default");
  manager.switchDatabase("default");
}

static void initTables(bool shouldCleanTable = true) {
  if (shouldCleanTable) {
    initDB();
  }
  executeSql("CREATE TABLE benchmark (id INT primary key);");
  for (int i = 0; i < DATASET_SIZE; i++) {
    std::stringstream ss;
    ss << "INSERT INTO benchmark (id) VALUES (" << i << ");";
    std::string formatted_string = ss.str();
    executeSql(formatted_string);
    // std::cout << i << std::endl;
  }
}

static void initIndex(bool shouldCleanIndex = true) {
  if (shouldCleanIndex) {
      cleanIndex();
  }
  executeSql("CREATE INDEX idx_id ON benchmark (id);");
}

static void GlobalSetup() {
  capybara::enablePrint = false;

  // 1. Get table disk usage
  std::cout << "Initializing Tables" << std::endl;
  initTables();
  auto table_size_before = std::filesystem::file_size("db/default.db");
  std::cout << "CREATE TABLE db/default.db file size is " << table_size_before << "B" << std::endl;

  // 2. Get Index disk usage
  std::cout << "Creating Indexes." << std::endl;
  initIndex();
  auto table_size_after = std::filesystem::file_size("db/default.db");
  std::cout << "CREATE INDEX db/default.db file size is " << table_size_after << "B" << std::endl;
  std::cout << "INDEX disk usage is " << table_size_after - table_size_before << "B" << std::endl;
}

static void GlobalTeardown() {
  cleanTables();
  std::filesystem::remove_all("db");
  std::filesystem::remove_all("metadata");
}

static void InitTable(benchmark::State &state) {
  MEM_BEFORE_TEST
  IO_BEFORE_TEST
  for (auto _ : state) {
    initTables();
  }
  IO_AFTER_TEST
  MEM_AFTER_TEST
}

static void CreateIndex(benchmark::State &state) {
  initTables();
  MEM_BEFORE_TEST
  IO_BEFORE_TEST
  for (auto _ : state) {
    initIndex();
  }
  IO_AFTER_TEST
  MEM_AFTER_TEST
}

static void SelectAll(benchmark::State &state) {
  initTables();
  initIndex();
  MEM_BEFORE_TEST
  IO_BEFORE_TEST                                                      \
  for (auto _ : state) {
    executeSql("select * from benchmark;");
  }
  IO_AFTER_TEST                                                      \
  MEM_AFTER_TEST
}

static void SelectWhereEquals(benchmark::State &state) {
  initTables();
  initIndex();
  MEM_BEFORE_TEST
  IO_BEFORE_TEST                                                      \
  for (auto _ : state) {
    for (int i = 0; i < DATASET_SIZE; i++) {
      executeSql("select * from benchmark WHERE id = " + std::to_string(i) + ";");
    }
  }
  IO_AFTER_TEST                                                      \
  MEM_AFTER_TEST
}

static void SelectWhereLessThan(benchmark::State &state) {
  initTables();
  initIndex();
  MEM_BEFORE_TEST
  IO_BEFORE_TEST                                                      \
  for (auto _ : state) {
    executeSql(SELECT_WHERE_SMALLER);
  }
  IO_AFTER_TEST                                                      \
  MEM_AFTER_TEST
}

static void SelectWhereRange(benchmark::State &state) {
  initTables();
  initIndex();
  MEM_BEFORE_TEST
  IO_BEFORE_TEST                                                      \
  for (auto _ : state) {
    executeSql(
        SELECT_WHERE_RANGE);
  }
  IO_AFTER_TEST                                                      \
  MEM_AFTER_TEST
}

static void SelectWhereBetween(benchmark::State &state) {
  initTables();
  initIndex();
  MEM_BEFORE_TEST
  IO_BEFORE_TEST                                                      \
  for (auto _ : state) {
    executeSql(SELECT_WHERE_BETWEEN);
  }
  IO_AFTER_TEST                                                      \
  MEM_AFTER_TEST
}

static void UpdateSingle(benchmark::State &state) {
  initTables();
  initIndex();

  int i = 0;
  unsigned seed = 17;
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> dist(1, DATASET_SIZE);
  MEM_BEFORE_TEST
  IO_BEFORE_TEST                                                      \
  for (auto _ : state) {
    std::stringstream ss;
    ss << "UPDATE benchmark SET id = " << dist(generator) << " WHERE id = " << i << ";";
    std::string formatted_string = ss.str();
    // std::cout << formatted_string << std::endl;
    executeSql(formatted_string);
    i++;
  }
  IO_AFTER_TEST                                                      \
  MEM_AFTER_TEST
}

static void RemoveSingle(benchmark::State &state) {
  initTables();
  initIndex();
  int i = 0;
  MEM_BEFORE_TEST
  IO_BEFORE_TEST                                                      \
  for (auto _ : state) {
    std::stringstream ss;
    ss << "DELETE FROM benchmark WHERE id = " << i << ";";
    std::string formatted_string = ss.str();
    // std::cout << formatted_string << std::endl;
    executeSql(formatted_string);
    i++;
  }
  IO_AFTER_TEST                                                      \
  MEM_AFTER_TEST
}

static void RandomWrites(benchmark::State &state) {
  initTables();
  initIndex();

  unsigned seed = 42;
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> dist(1, DATASET_SIZE);
  bool do_insert = false;
  MEM_BEFORE_TEST
  IO_BEFORE_TEST                                                      \
  for (auto _ : state) {
    auto key = dist(generator);

    if (KeyWillVanish(key)) {
      if (do_insert) {
        std::stringstream ss;
        ss << "INSERT INTO benchmark (id) VALUES (" << key << ");";
        std::string formatted_string = ss.str();
        // std::cout << formatted_string << std::endl;
        executeSql(formatted_string);
      } else {
        std::stringstream ss;
        ss << "DELETE FROM benchmark WHERE id = " << key << ";";
        std::string formatted_string = ss.str();
        // std::cout << formatted_string << std::endl;
        executeSql(formatted_string);
      }
    } else if (KeyWillChange(key)) {
        std::stringstream ss;
        ss << "UPDATE benchmark SET id = " << dist(generator) << " WHERE id = " << key << ");";
        std::string formatted_string = ss.str();
        // std::cout << formatted_string << std::endl;
        executeSql(formatted_string);
    }
    do_insert = !do_insert;
  }
  IO_AFTER_TEST                                                      \
  MEM_AFTER_TEST
}

// TODO: Uncomment
BENCHMARK(InitTable)->Unit(benchmark::kMillisecond);
BENCHMARK(CreateIndex)->Unit(benchmark::kMillisecond)->Iterations(1);
BENCHMARK(SelectAll)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectWhereEquals)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectWhereLessThan)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectWhereRange)->Unit(benchmark::kMillisecond);
BENCHMARK(SelectWhereBetween)->Unit(benchmark::kMillisecond);
BENCHMARK(UpdateSingle)->Unit(benchmark::kMillisecond);
BENCHMARK(RemoveSingle)->Unit(benchmark::kMillisecond);
//BENCHMARK(RandomWrites)->Unit(benchmark::kMillisecond);

int main(int argc, char **argv) {
  char arg0_default[] = "--benchmark_counters_tabular=true";
  char *args_default = arg0_default;
  if (!argv) {
    argc = 1;
    argv = &args_default;
  } else {
    argv[argc++]= args_default;
  }
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
  GlobalSetup();
  ::benchmark::RunSpecifiedBenchmarks();
  ::benchmark::Shutdown();
  GlobalTeardown();
  return 0;
}
