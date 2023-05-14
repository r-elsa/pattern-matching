#include <iostream>
#include <string>
#include "trie.h"
#include "apicall.h"

using namespace std;

#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

// This is the header file for helperfunctions.cpp

string APIhelper(string apiAdress, string authKey)
{
    APICall api_instance;
    api_instance.apicall(apiAdress, authKey);
    string finalString = api_instance.dataparsing();
    return finalString;
}

bool suffixInsertionHelper(TrieNode myObj, string finalString, TrieNode *&curr)
{
    int totalNodeCount = 0;
    for (int i = 0; i < finalString.size(); i++)
    {
        int nodeCount = myObj.insert(curr, finalString.substr(i));
        totalNodeCount+=nodeCount;
    }
    return 1;
}

bool wordInsertionHelper(TrieNode myObj, string finalString, TrieNode *&curr)
{
    int totalNodeCount = 0;
    std::string word;
    finalString[finalString.size() - 1] = ' ';
    for (int i = 0; i < finalString.size(); i++)
    {
        if (finalString[i] == ' ')
        {
            word += '$';
            int nodeCount = myObj.insert(curr, word);
            totalNodeCount += nodeCount;
            word = "";
        }
        else
        {
            word = word + finalString[i];
        }
    }
    return 1;
}


bool subStringSearchHelper(TrieNode myObj, string finalString, TrieNode *&curr, string searchString)
{
    transform(searchString.begin(), searchString.end(), searchString.begin(), ::tolower);
    auto tup = myObj.search(curr, searchString);
    bool isSubstring_search = std::get<0>(tup);
    return isSubstring_search;
}

vector<string> autoCompleteHelper(TrieNode myObj, string finalString, TrieNode *&curr, string userInput)
{
    vector<string> suggestions;
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    auto tup = myObj.search(curr, userInput);
    bool isSubstring = std::get<0>(tup);
    TrieNode *location = std::get<1>(tup);

    if (isSubstring)
    {
        suggestions = myObj.preorder(location, userInput);
    }
    else
    {
        suggestions = {"query prefix not present"};
    }
    return suggestions;
}

#endif