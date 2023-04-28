#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <algorithm>
#include <functional>
#include <tuple>
#include "apicall.cpp"
#include "suffixtrie_hashmap.cpp"

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
    auto [isSubstring_search, location_search] = myObj.search(curr, searchString);
    return isSubstring_search;
}

vector<string> autoCompleteHelper(TrieNode myObj, string finalString, TrieNode *&curr, string userInput)
{
    vector<string> suggestions;

    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    auto [isSubstring, location] = myObj.search(curr, userInput);

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

int main()
{
    // api call
    APICall api_instance;
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    string authkey = getenv("AUTH_KEY");

    api_instance.apicall(apiadress, authkey);
    string finalString = api_instance.dataparsing();
    cout << finalString << endl;

    // inserion of suffixes
    TrieNode myObj;
    TrieNode *curr = new TrieNode();
    bool suffixInsertionToTrie = suffixInsertionHelper(myObj, finalString, curr);

    // search substring
    std::string searchString;
    cout << " " << endl;
    cout << "Type a word or sentence to search in the suffixtrie (empty space stops):";

    while (true)
    {
        getline(std::cin, searchString);
        if (searchString.empty())
        {
            break;
        }
        bool subStringExists = subStringSearchHelper(myObj, finalString, curr, searchString);

        if (subStringExists)
        {
            cout << "Yes" << endl;
            cout << " " << endl;
        }
        else
        {
            cout << "No" << endl;
            cout << " " << endl;
        }
    }

    // insertion of words
    TrieNode myObj_autocomplete;
    TrieNode *curr_autocomplete = new TrieNode();

    bool wordInsertionToTrie = wordInsertionHelper(myObj_autocomplete, finalString, curr_autocomplete);

    // autocomplete
    string userInput;
    cout << " " << endl;
    cout << "Type character(s) for the suffixtrie to autocomplete: ";

    while (true)
    {
        getline(std::cin, userInput);

        if (userInput.empty())
        {
            break;
        }

        vector<string> suggestions = autoCompleteHelper(myObj_autocomplete, finalString, curr_autocomplete, userInput);

        for (int i = 0; i < suggestions.size(); i++)
        {
            cout << suggestions[i] << endl;
        }
    }
    return 0;
}
