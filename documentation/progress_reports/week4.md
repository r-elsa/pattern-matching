## Progress report week 4 (10.4 - 16.4)

**This week I have** researched and implemented the suffix trie using adjacency lists (vector of vectors) and a method to look if a substring includes in a string. The suffix trie leads to a lot of redundancy in terms of space. The function renders a Segmentation fault with an input string longer than on an average 10 characters.  

**The project has progressed** well despite hardships with implemenation of the suffix trie. 

**This week I learned** implementation of suffix trie with adjacency lists. 

**Something that is unclear:** see questions. 

**Next up, I will** create tests for the suffix trie implementation. Start implementing the suffix tree. 

**Questions: 

Regarding implementation of suffix trie - Any suggestions on how to solve the problem that I currently have with space: As an example, the string of data that I retrieved from NY times API on 14/4 included 487 words (3,337 characters). The total amount of suffixes of such a data are 3337 (the amount of characters in the string) and following the formula m(m+1)/2 where m is the amount of characters in the string, the total amount of characters are 5,569,453. The vector datastructure cannot bear the amount of data in adjacency lists and leads to Segmentation fault. Would hashmaps/maps possibly solve the problem?




