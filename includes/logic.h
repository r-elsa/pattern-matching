
#pragma once

#include "suffixtrie.h"

bool APIcall();

bool suffixInsertionHelper(TrieNode myObj, string finalString, TrieNode *&curr);

bool wordInsertionHelper(TrieNode myObj, string finalString, TrieNode *&curr);

bool subStringSearchHelper(TrieNode myObj, string finalString, TrieNode *&curr, string searchString);

vector<string> autoCompleteHelper(TrieNode myObj, string finalString, TrieNode *&curr, string userInput);