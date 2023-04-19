#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    unordered_map<char,TrieNode*> hashmap;
    std::string s;

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
    
    string search(TrieNode* root, string s){
        TrieNode* curr = root;
      
        for (int i = 0; i< s.size(); i++){
            /* cout << s[i] << endl; */
            if(curr -> hashmap.find(s[i]) == curr -> hashmap.end()){
                return "No";
            }
            curr = curr->hashmap[s[i]];
        }
        return "Yes";
    }
};


