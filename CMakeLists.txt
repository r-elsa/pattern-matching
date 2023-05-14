cmake_minimum_required(VERSION 2.6)
PROJECT(Patternmatching)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(executeTests tests/main_test.cpp)

# Link executeTests with what we want to test and the GTest, pthread, curl and jsoncpp libraries
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread curl jsoncpp)

add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/coverage
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/coverage
    COMMAND lcov -c -d .. -o coverage.info
    COMMAND genhtml -o results/ coverage.info
)

add_custom_target(DEPENDS coverage.info)

 



