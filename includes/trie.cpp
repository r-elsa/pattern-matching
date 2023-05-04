#include <bits/stdc++.h>
#include <tuple>
#include <cstdlib>

using namespace std;


/* This class creates the trie as an unordered map 
 * with a character as the key and a node as value.
 * If further keeps track of some additional paramethers needed for the dfs- function
 */
class TrieNode
{
public:
    unordered_map<char, TrieNode *> hashmap;
    std::string alphabet = "$abcdefghijklmnopqrstuvwxyz";
    std::string s;
    string prevstring = "";
    string stringBuilder = "";
    vector<string> words;


    /* This function inserts node in the suffixtrie. 
     * It gets called by the functions suffixInsertionHelper and wordInsertionHelper in helperfunctions.cpp
     * It receives a suffix or a word  
     *  and for each character in i'th suffix/word it adds an outgoing edge if necessary 
     * (and sets the new outgoing edge as current node)
    */
    bool insert(TrieNode *&root, string suffix)
    {
        TrieNode *curr = root;
        char letter;
        for (int i = 0; i < suffix.size(); i++)
        {
            letter = suffix[i];
            if (curr->hashmap.find(letter) == curr->hashmap.end())
            {
                curr->hashmap[letter] = new TrieNode;
            }
            curr = curr->hashmap[letter];
        }
        return 1;
    }


    /* The purpose of this function is to find out whether the string s is a substring of the text.
     * It follows the path given by characters of s
     * and returns information about:
     *     1) whether the string is included or we fell of the path (boolean value).
     *     2) node at end of path.
    */
    tuple<bool, TrieNode *> search(TrieNode *root, string s)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (curr->hashmap.find(s[i]) == curr->hashmap.end())
            {
                return std::make_tuple(0, root);
            }
            curr = curr->hashmap[s[i]];
        }
        return std::make_tuple(1, curr);
    }


    /* This is the in-order depth first search algorithm. 
    * It traverses the tree with the end of the user's string as root node.
    * It stores as parameters the level of the tree and the previous string in order to later build the final word. 
    * and add it to the vector suggestions, ehich it then returns
    */
    void dfs(TrieNode *root, std::vector<string> &suggestions, int level, string original)
    {
        TrieNode *curr;
        for (int i = 0; i < alphabet.size(); i++)
        {
            if (!(root->hashmap.find(alphabet[i]) == root->hashmap.end()))
            {
                if (alphabet[i] == '$')
                {
                    string buildFinal;
                    int checkIfSubstring = level - stringBuilder.length();
                    if (checkIfSubstring > 0)
                    {
                        prevstring = prevstring.substr(0, checkIfSubstring) + stringBuilder;
                        buildFinal = original + prevstring;
                    }
                    else
                    {
                        prevstring = stringBuilder;
                        buildFinal = original + prevstring;
                    }
                    stringBuilder = "";
                    suggestions.push_back(buildFinal);
                }
                else
                {
                    stringBuilder += alphabet[i];
                }

                TrieNode *curr;
                curr = root->hashmap[alphabet[i]];
                dfs(curr, suggestions, level + 1, original);
            }
        }
    }

    /* This function works as a helper function for the depth first search (dfs)
    * It initializes the parameters needed for the dfs, 
    * including the vector where suggestions will be stored,
    * before calling the recursive function.
    */
    vector<string> preorder(TrieNode *root, string originalString)
    {
        int level = 0;
        std::vector<string> suggestions;
        dfs(root, suggestions, level, originalString);
        return suggestions;
    }
};
