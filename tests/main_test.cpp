#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <iostream>
#include <chrono>
#include "../includes/trie.h"
#include "../includes/helperfunctions.h"
#include "./regular_test.h"
#include "./complexity_test.h"

using namespace std;


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


