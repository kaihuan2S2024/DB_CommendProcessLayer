project(profiling)

#add_compile_options(-fsanitize=address -fno-omit-frame-pointer -g)
#add_link_options(-fsanitize=address)

# Google Benchmark
find_library(BENCHMARK_LIB benchmark)

# Google gperftools
find_library(TCMALLOC_LIB tcmalloc)
find_library(TCMALLOC_DEBUG_LIB tcmalloc_debug)

add_executable(GroupProjectBenchmark
    GroupProjectBenchmark.cpp
    fishhook.c
)
target_link_libraries(GroupProjectBenchmark CommandProcessorLib ${BENCHMARK_LIB})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#    target_link_libraries(GroupProjectBenchmark ${TCMALLOC_DEBUG_LIB})
else()
#    target_link_libraries(GroupProjectBenchmark ${TCMALLOC_LIB})
endif()

add_executable(GroupProjectTest
    GroupProjectTest.cpp
)
target_link_libraries(GroupProjectTest CommandProcessorLib)
