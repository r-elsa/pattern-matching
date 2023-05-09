cmake_minimum_required(VERSION 2.6)
PROJECT(Patternmatching)


# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests tests/trie_test.cpp)


target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread curl jsoncpp)

add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/coverage
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/coverage
    COMMAND lcov -c -d .. -o coveragenew.info
    COMMAND genhtml -o results/ coveragenew.info

)

add_custom_target(DEPENDS coveragenew.info)


# Link runTests with what we want to test and the GTest and pthread library



