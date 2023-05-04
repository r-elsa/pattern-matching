#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <algorithm>
#include <functional>
#include <tuple>
#include "includes/apicall.h"
#include "includes/suffixtrie.h"
#include "includes/helperfunctions.h"
#include "includes/ui.h"


int main()
{
    string apiAddress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    string authKey = getenv("AUTH_KEY");
    string finalString = APIhelper(apiAddress, authKey);  // gdgdgbdbdfb
    cout << finalString << endl;

    TrieNode myObj;
    TrieNode *curr = new TrieNode();
    bool suffixInsertionToTrie = suffixInsertionHelper(myObj, finalString, curr);  // dvdsvdsv

    TrieNode myObj_autocomplete;
    TrieNode *curr_autocomplete = new TrieNode();
    bool wordInsertionToTrie = wordInsertionHelper(myObj_autocomplete, finalString, curr_autocomplete);  // insertion of words

    UIsearchSubString(myObj, finalString, curr);  // insertion of words
    UIAutocomplete(myObj_autocomplete, finalString, curr_autocomplete);     // autocomplete
    
    return 0;
}
