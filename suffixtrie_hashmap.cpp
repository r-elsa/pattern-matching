#include <bits/stdc++.h>
#include <tuple>
using namespace std;




class TrieNode{
    public:
    unordered_map<char,TrieNode*> hashmap;
    std::string s;
    std::string alphabet = "$abcdefghijklmnopqrstuvwxyz";

    void insert(TrieNode* &root,string suffix){
        TrieNode *curr = root;
           
        char letter;
        for (int i = 0; i < suffix.size(); i++){
            letter = suffix[i];
             if (curr->hashmap.find(letter) == curr->hashmap.end()){
                    curr->hashmap[letter] = new TrieNode;
            }  
            curr = curr->hashmap[letter];
           /*  cout << curr << endl; */
                 
        }                         
     }



     tuple<bool, TrieNode*> search(TrieNode* root, string s){  
        TrieNode* curr = root;
      
        for (int i = 0; i< s.size(); i++){
            /* cout << s[i] << endl; */
            if(curr -> hashmap.find(s[i]) == curr -> hashmap.end()){
                return {0, root};
            }
            curr = curr->hashmap[s[i]]; // update pointer
        }
        return {1, curr};    
    }



    void dfs_helper(TrieNode* root, vector <string> words, string stringBuilder, int level, string original){  // recursion private
    
    TrieNode* curr = root;
    for (int i = 0; i< alphabet.size(); i++){
        /* cout << s[i] << endl; */
        if(!(curr -> hashmap.find(alphabet[i]) == curr -> hashmap.end())){
            if(alphabet[i] == '$'){
                
                string w = original + stringBuilder;
                words.push_back(w);
                cout << "$: " << w << endl;
                
            }else{
            
            cout << "FOUND" << alphabet[i] << endl;
            stringBuilder += alphabet[i];
            curr = curr -> hashmap[alphabet[i]];
            dfs_helper(curr, words, stringBuilder, level, original);
         
           
            }
           
        }
    
    }
   
    }


    vector <string> preorder(TrieNode* root, string originalString){ // root node 
       
    vector <string> words;  // string builder
    int level = 0;  // current level index/ depth within trie
    std::string stringBuilder;
    dfs_helper(root, words, stringBuilder, level, originalString);
    
            // process rot & call reorder on each node in child

         // If the last matching node of the query has no children, return.

         // Else recursively print all nodes under a subtree of last matching node.

    return words;

    }
};


