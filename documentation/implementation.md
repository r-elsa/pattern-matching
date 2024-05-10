# Implementation document

## Project structure 

Excluding all files that are added in .gitignore

├── CMakeLists.txt <br />
├── README.md <br />
├── documentation <br />
│   ├── images <br />
│   │   ├── code_coverage7.5.jpg <br />
│   │   ├── space_complexity_insertion.jpg <br />
│   │   ├── statistics.jpg <br />
│   │   ├── time_complexity_insertion.jpg <br />
│   │   └── time_complexity_search.jpg <br />
│   ├── implementation.md <br />
│   ├── progress_reports <br />
│   │   ├── time_report.md <br />
│   │   ├── week1.md <br />
│   │   ├── week2.md <br />
│   │   ├── week3.md <br />
│   │   ├── week4.md <br />
│   │   ├── week5.md <br />
│   │   └── week6.md <br />
│   ├── requirements.md <br />
│   ├── testing.md <br />
│   └── user_guide.md <br />
├── includes <br />
│   ├── apicall.cpp <br />
│   ├── apicall.h <br />
│   ├── helperfunctions.cpp <br />
│   ├── helperfunctions.h <br />
│   ├── trie.cpp <br />
│   ├── trie.h <br />
│   ├── ui.cpp <br />
│   └── ui.h <br />
├── main.cpp <br />
├── tests <br />
│    ├── complexity_test.h <br />
│    ├── main_test.cpp <br />
│    └── regular_test.h <br />
└── suffixtree
    ├──htmlcov
    ├──src
    ├──algorithm
    │   └── ukkonen.py
    └── tests
        └── algorithm_tests.py
  


<br />
<br />

## Implemented time and space complexities 

### Insertion of a string to a trie by inserting one key at at time:

Starting from the root, each following node corresponds to the first key character. 

There are two cases :

1) A node exists. Then we move down the tree following the node to the next child level. The algorithm continues with searching for the next key character.
2) A node does not exist. Then we create a new node. We repeat this step until we encounter the last character of the key, then we mark the current node as an end node and the algorithm finishes.

**Time complexity: O(m)**
 - In each iteration of the algorithm, we either examine or create a node in the trie till we reach the end of the key. This takes m operations.

**Space complexity: O(m)**
 -  worst case newly inserted key doesn't share a prefix with the the keys already inserted in the trie. We have to add m new nodes, O(m) space.)

### Search for a key in a trie:

Each key is represented in the trie as a path from the root to the internal node or leaf. We start from the root with the first key character. We examine the current node for a link corresponding to the key character. 

There are two cases:

1) A node exist. We move to the next node in the path following this link, and proceed searching for the next key character.
2) A node does not exist. If there are no available key characters and we return false:


**Time complexity: O(m)**
 In each step of the algorithm we search for the next key character. In the worst case the algorithm performs m operations.

**Space complexity: O(1)**

<br />

### Implementation of a suffix tree using Ukkonen's algorithm


**Time complexity: O(n)**

- Ukkonen's algorithm is well-known for constructing suffix trees in linear time complexity O(n), where n is the length of the input string.

- Ukkonen's algorithm constructs the suffix tree incrementally in a series of linear-time steps.

**Space complexity: <O(n)- O(n^2)**

- Depends on the type of the constructed suffix tree.
  - Highly repetitive strings: worst case is O(n^2), where n is the length of the input string.
  - Relatively random or diverse input strings: O(n) or less

### Searching whether a substring exists in a suffix tree

**Time complexity: O(m)**

- Typically O(m), where m is the length of the string.
- In worst case one is searching for the whole string that was inserted to the suffix tree, where the entire suffix tree needs to be traversed. The time complexity would still be O(m).
- Edge length comparison is O(1) as edges are represented as indices.


## Possible flaws and improvements

 - Currently header files (.h) and files for complilation (.cpp) are not ideal, yet they do work.
<br />


## Sources

- Introduction to Algorithms(CLRS)
- internet
<br />

