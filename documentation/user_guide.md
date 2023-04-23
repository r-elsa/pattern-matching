## Suffix trie & Suffix tree


##### Suffixes of the word 'suffixes'
 
                  suffixes$
                   uffixes$ 
                    ffixes$  
                     fixes$ 
                      ixes$  
                       xes$  
                        es$  
                         s$  
                          $ 
 

### 1) Suffix Trie

Terminal character $ identifies a leaf node. Each path from root to leaf represents a suffix.The suffixes are stored in a trie like structure starting from the root.
The implemetation of the suffix trie enables the following features:

a) **Search**

- By starting at the root and following the edges labeled with the characters of the search string S, we can find out if S belongs to the data. 
- If there is no outgoing edge for next character of the search string S, then the search string S is not a substring of the data. 

b) **Autocomplete**

 - In order to autocomplete a string (which the program currently does, later this will be changed to suffixes) the suffix tree stores words and not suffixes. 
 -  Depth first search algorithm on N-ary tree. 



### 2) Suffix Tree

to be implemented
 
 
