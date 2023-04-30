#include "suffixtrie.h"

bool APIcall()
{
    return 1;
}

bool suffixInsertionHelper(TrieNode myObj, string finalString, TrieNode *&curr)
{
    for (int i = 0; i < finalString.size(); i++)
    {
        myObj.insert(curr, finalString.substr(i));
    }
    return 1;
}

bool wordInsertionHelper(TrieNode myObj, string finalString, TrieNode *&curr)
{
    std::string word;
    finalString[finalString.size() - 1] = ' ';

    for (int i = 0; i < finalString.size(); i++)
    {
        if (finalString[i] == ' ')
        {
            word += '$';
            myObj.insert(curr, word);
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
    TrieNode *location_search = std::get<1>(tup);
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