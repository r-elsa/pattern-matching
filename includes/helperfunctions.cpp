
#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <algorithm>
#include <functional>
#include <tuple>
#include "trie.h"
#include "apicall.h"


using namespace std;

/* This function serves as a helper function for calling the API.
 * It returns the final data which is a long string that includes lead paragraph-fields and abstract-fields of articles
 */
string APIhelper(string apiAdress, string authKey)
{
    APICall api_instance;
    api_instance.apicall(apiAdress, authKey);
    string finalString = api_instance.dataparsing();
    return finalString;
}

/*  This function serves as a helper function for implementing the trie of suffixes. 
 *  It loops through the final string,
 *  and calls the insertion function on each suffix. 
  
 */
bool suffixInsertionHelper(TrieNode myObj, string finalString, TrieNode *&curr)
{
    for (int i = 0; i < finalString.size(); i++)
    {
        myObj.insert(curr, finalString.substr(i));
    }
    return 1;
}

/*  This function serves as a helper function for implementing the trie of words. 
 *  It loops through the final string,
 *  adds a terminator ($) character to end of each word
 *  and calls the insertion function on each word. 
 */
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

/*  This function serves as a helper function for both the search - feature and the autocomplete - feature. 
 *  It transforms the user input to lowercase,
 *  and calls the search - function to see whether the user input is a substring.
 */
bool subStringSearchHelper(TrieNode myObj, string finalString, TrieNode *&curr, string searchString)
{
    transform(searchString.begin(), searchString.end(), searchString.begin(), ::tolower);
    auto tup = myObj.search(curr, searchString);
    bool isSubstring_search = std::get<0>(tup);
    TrieNode *location_search = std::get<1>(tup);
    return isSubstring_search;
}

/* This function serves as a helper function to the autocomplete - feature. 
 * It transforms the user input to lower case and calls the search function to see whether the user input exists the text.
 * If it exists, the preorder - function is called. If not, the information is delivered that the user input is not a prefix to any word. 
 */
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
