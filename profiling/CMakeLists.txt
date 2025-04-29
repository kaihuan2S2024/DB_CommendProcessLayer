cmake_minimum_required(VERSION 3.26)
project(profiling)

# Google Benchmark
find_library(BENCHMARK_LIB benchmark)

# Google gperftools
find_library(TCMALLOC_LIB tcmalloc)
find_library(TCMALLOC_DEBUG_LIB tcmalloc_debug)

add_executable(GroupProjectBenchmark GroupProjectBenchmark.cpp)
target_link_libraries(GroupProjectBenchmark CommandProcessorLib ${BENCHMARK_LIB})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(GroupProjectBenchmark ${TCMALLOC_DEBUG_LIB})
else()
    target_link_libraries(GroupProjectBenchmark ${TCMALLOC_LIB})
endif()
