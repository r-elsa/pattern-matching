#include <bits/stdc++.h>
#include <tuple>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> hashmap;
    std::string s;
    std::string alphabet = "$abcdefghijklmnopqrstuvwxyz";

    void insert(TrieNode *&root, string suffix)
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
    }

    tuple<bool, TrieNode *> search(TrieNode *root, string s)
    {
        TrieNode *curr = root;

        for (int i = 0; i < s.size(); i++)
        {
            if (curr->hashmap.find(s[i]) == curr->hashmap.end())
            {
                return {0, root};
            }
            curr = curr->hashmap[s[i]]; // update pointer
        }
        return {1, curr};
    }

    void dfs_helper(TrieNode *root, vector<string> words, string stringBuilder, int level, string original)
    { 
       
        for (int i = 0; i < alphabet.size(); i++)
        {
            if (root->hashmap.find(alphabet[i]) == root->hashmap.end())
            {
            }
            else
            {
                if (alphabet[i] == '$')
                {
                    string final = original + stringBuilder;
                    cout << final << endl;
                    stringBuilder = "";
                    
                }
                stringBuilder += alphabet[i];

                TrieNode *curr;
                curr = root->hashmap[alphabet[i]];
                dfs_helper(curr, words, stringBuilder, level + 1, original);
            }     
        }
    }

    vector<string> preorder(TrieNode *root, string originalString)
    {
        vector<string> words; 
        int level = 0;       
        std::string stringBuilder;
        dfs_helper(root, words, stringBuilder, level, originalString);

        return words;
    }
};
