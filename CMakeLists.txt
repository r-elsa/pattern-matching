cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Code coverage
SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage") 
SET(GCC_COVERAGE_LINK_FLAGS "-lgcov") 
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}") 
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests tests/trie_test.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread curl jsoncpp)

