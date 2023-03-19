
# Requirement specification

## Aim of project:

The goal of the project is to get to know new and challenging tree like data structures by using string manipulation as an example. The objects of comparison are four different tree-like datastructures, which are tested on four different problems. The aim is to investigate and find which datastructure is the best in which problem situation.

## Programming language:
- C++, for user interface C++ GUI application 
- I can peer review: C++, python

## Scope of the project:

### The four data structures to be compared:
**1) Segment tree** 
  - Type of binary tree, helpful in range queries along with updates. 
  - Overall time complexity: O(n log n)
  
**2) Trie** 
  - Executes insert and search operations faster than a binary search tree.
  - Overall time complexity: 0(n)
  
**3) Treap/ Cartsian tree**
  - Combines binary tree and binary heap. Also called cartesian tree.
  - Overall time complexity: O(log n)
  
**4) Fenwick-tree / Binary indexed tree**
  - Efficiently updates elements and calculates prefix sums.
  - Overall time complexity: O(log n).
 
### Motivations behing choosing datastructures
  - These datastructures are all not covered in the Data structures and algorithms course, as required. 
  - Somewhat easier tree-like datastructures (Trie and Segment tree) were chosen to balance the more complex ones (Fenwick tree and Treap).
  - While suffix tree is one of the most well known datastructures for string manipulation, it's implementation (and Ukkonen's algorithm) seemed too complex. 

### 4 different problems that data structures help to solve. (INITIAL IDEAS)
1) UPDATE: Update a specific letter in the word at a specific index or over an interval. (Segment tree winner)
2) SEARCH: Searching the most popular letter. (Trie might be winner)
3) DELETE: Delete a letter from word. 
4) MERGE: Merge two words (strings). (Treap winner)


###  Which data structure is best for each problem? The comparison includes:
- Time complexity
- Execution time in milliseconds
- Space complexity

### Algorithms I will use:
To search I will use Binary search.
To traverse  I will use the in-order traversal. 

### Inputs the algorithms receive
  - Firstly, the input that the algorithm receives is a string.
  - Secondly 
    - Problem 1: an index or interval of indexes
    - Problem 2: a letter
    - Problem 3: a letter
    - Problem 4: a string 

## Sources
  - Introduction to Algorithms(CLRS)
  - internet

## Study programe:
 Tietojenkäsittelytieteen kandidaatti (TKT) 
 
## Language for documentation, code and comments 
  - English
  - For peer review I can also write in Finnish. 
  
