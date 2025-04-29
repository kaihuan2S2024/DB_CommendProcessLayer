cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 17)

# 'Google_test' is the subproject name
project(Google_tests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")

include_directories(../parserTree)
include_directories(../queryOptimization)
include_directories(../runtime)
include_directories(../generated)
include_directories(../metadataManager)
include_directories(../runtime/antlrcpp-ios)
include_directories(../runtime/src)
include_directories(../runtime/src/atn)
include_directories(../runtime/src/dfa)
include_directories(../runtime/src/internal)
include_directories(../runtime/src/misc)
include_directories(../runtime/src/support)
include_directories(../runtime/src/tree)
include_directories(../runtime/src/tree/pattern)
include_directories(../runtime/src/tree/xpath)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCES
        ../parserTree/src/ParserTree.cpp
        ../parserTree/src/ParserTreeNode.cpp
        ../parserTree/MyListener/MyListener.cpp)
set(HEADERS
        ../parserTree/MyListener/MyListener.h
        ../parserTree/include/ParserTree.h
        ../parserTree/include/ParserTreeNode.h
        ../runtime/src/antlr4-runtime.h
)
file(GLOB_RECURSE TEST_SOURCES "../parserTree/*" "../runtime/src/*" "../generated/*" "../queryOptimization/*" "../executor/*" "../metadataManager/*")

add_library(Utilities ${SOURCES} ${HEADERS})
target_include_directories(
        Utilities
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ../parserTree
        ../runtime/src
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run
        testParser.cpp
        testOptimization.cpp
)
message(STATUS "Google_Tests_run target is being added")


target_link_libraries(Google_Tests_run CommandProcessorLib VDBE_LAYER gtest gtest_main)