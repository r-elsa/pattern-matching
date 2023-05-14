#include <iostream>
#include <string>
#include "includes/apicall.h"
#include "includes/trie.h"
#include "includes/helperfunctions.h"
#include "includes/ui.h"

 /* This is the main function, which calls the function that does an api call to NY Times API. 
  * Then it creates two different suffix tries of the data it received (one with suffixes, one with words).
  * Finally it calls two UI functions for input from user. 
  */
int main()
{
    string apiAddress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    string authKey = getenv("AUTH_KEY");
    string finalString = APIhelper(apiAddress, authKey); 
    cout << finalString << endl;

    TrieNode myObj;
    TrieNode *curr = new TrieNode();
    suffixInsertionHelper(myObj, finalString, curr); 

    TrieNode myObj_autocomplete;
    TrieNode *curr_autocomplete = new TrieNode();
    wordInsertionHelper(myObj_autocomplete, finalString, curr_autocomplete); 

    UIsearchSubString(myObj, finalString, curr);  
    UIAutocomplete(myObj_autocomplete, finalString, curr_autocomplete);     
    
    return 0;
}
