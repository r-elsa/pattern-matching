
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <iostream>
#include <chrono>
#include "../includes/trie.h"
#include "../includes/helperfunctions.h"


string testdata1 = "he assisted south african dissidents like the journalist donald woods whose story was told in the movie cry freedom$";
string testdata2 = "a proposal to make new york the third state to ban menthol cigarettes has created a furious and expensive lobbying war$";
string testdata3 = "cyclone mocha made landfall near myanmars border with bangladesh passing through the city that is home to the worlds largest refugee encampment and raising fears of a humanitarian catastrophe cyclone mocha made landfall near myanmars border with bangladesh passing through the city that is home to the worlds largest refugee encampment and raising fears of a humanitarian catastrophe donald j trump made the border a central focus of his campaign as president he relied on cruelty and fear to deter migrants from the united states when donald j trump became president he immediately set out to change the countrys immigration$";


// 2. Regular tests 

TEST(RSearchTest, SuffixFound1)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, testdata3, testCurr));
    std::string searchString = "gladesh passing through the city that is home to the worlds largest refugee encampment and raising fea";
    ASSERT_EQ(1, subStringSearchHelper(testObj, testdata3, testCurr, searchString));

}


TEST(RSearchTest, SuffixFound2)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, testdata2, testCurr));
    std::string searchString = "a proposal to make new york the third state to ban menthol cigarettes has created a furious and expensive lobbying war";
    ASSERT_EQ(1, subStringSearchHelper(testObj, testdata2, testCurr, searchString));

}

TEST(RSearchTest, SuffixNotFound1)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, testdata2, testCurr));
    std::string searchString = "fourth state";
    ASSERT_EQ(0, subStringSearchHelper(testObj, testdata1, testCurr, searchString));

}
TEST(RSearchTest, SuffixNotFound2)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, testdata2, testCurr));
    std::string searchString = "fourth state";
    ASSERT_EQ(0, subStringSearchHelper(testObj, testdata1, testCurr, searchString));

}

TEST(RSearchTest, WordFound)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, wordInsertionHelper(testObj, testdata3, testCurr));
    std::string searchString = "cyclone";
    ASSERT_EQ(1, subStringSearchHelper(testObj, testdata3, testCurr, searchString));
}


TEST(RSearchTest, WordNotFound)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, wordInsertionHelper(testObj, testdata3, testCurr));
    std::string searchString = "cyclone moche";
    ASSERT_EQ(0, subStringSearchHelper(testObj, testdata3, testCurr, searchString));
}



TEST(RAutoCompleteTest, AutocompleteSuccessful1)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    string userInput = "c";
    vector <string> expected = {"campaign","catastrophe","central","change","city","countrys","cruelty","cyclone"};
    ASSERT_EQ(1, wordInsertionHelper(testObj, testdata3, testCurr));
    ASSERT_EQ(expected, autoCompleteHelper(testObj, testdata3, testCurr, userInput));
}

TEST(RAutoCompleteTest, AutocompleteSuccessful2)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    string userInput = "th";
    vector <string> expected = {"that", "the","through"};
    ASSERT_EQ(1, wordInsertionHelper(testObj, testdata3, testCurr));
    ASSERT_EQ(expected, autoCompleteHelper(testObj, testdata3, testCurr, userInput));
}

TEST(RAutoCompleteTest, AutocompleteUnSuccessful1)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    string userInput = "x";
    vector <string> expected = {"query prefix not present"};
    ASSERT_EQ(1, wordInsertionHelper(testObj, testdata3, testCurr));
    ASSERT_EQ(expected, autoCompleteHelper(testObj, testdata3, testCurr, userInput));
}

TEST(RAutoCompleteTest, AutocompleteUnSuccessful2)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    string userInput = "p r";
    vector <string> expected = {"query prefix not present"};
    ASSERT_EQ(1, wordInsertionHelper(testObj, testdata1, testCurr));
    ASSERT_EQ(expected, autoCompleteHelper(testObj, testdata1, testCurr, userInput));
}