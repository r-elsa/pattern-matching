
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <functional>
#include <tuple>
#include "trie.h"
#include "apicall.h"
#include "helperfunctions.h"

using namespace std;

// This is the header file for ui.cpp

void UIsearchSubString(TrieNode myObj, string finalString, TrieNode *&curr){
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
}



void UIAutocomplete(TrieNode myObj_autocomplete, string finalString, TrieNode *&curr_autocomplete){
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
        for (vector<string>::iterator t = suggestions.begin(); t != suggestions.end(); ++t)
        {
            cout << *t << endl;
        }
        cout << " " << endl;
    }
}

