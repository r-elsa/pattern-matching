
# Requirement specification

<br />

## Aim of project:

The topic of the project is indexing with suffixes. Suffix tries (and regular tries) provide an efficent way to search any pattern from text in O(m) time where m is the length of the pattern. Suffix trees provide a more space efficient solution O(m) (in comparison to suffix tries which are O(m^2)). With the help of Ukkonen's algorithm the suffix tree can be constructed in linear time -  O(m).
In order to traverse the suffix trie and tree, depth first search DFS (in-order traversal) is implemented. 

<br />

## Programming language:
- C++, for user interface cmd.
- Python for Ukkonen's algorithm.
- I can peer review: C++, python

<br />

## Scope of the project:

1. **HTTP request**
    - To REST Server of New York Times for text (data). (https://developer.nytimes.com/docs/articlesearch-product/1/overview)

2. **Preprocessing**
   -  Extract all the words from json to a string.

3. **Creation of datastructures**
     1. Trie (Time complexity: 0(n2), Space complexity: : 0(n2), meaning superlinear growth)
     2. Suffix trie (Time complexity: 0(n2), Space complexity: : 0(n2), meaning superlinear growth.)
     3. Suffix tree (Time complexity: 0(n), Space complexity: : 0(n), meaning linear growth.)

4. **Features:**
    - Find a certain search word (string) from trie based on user input. (O(m) time where m is length of the string).
    - Autocomplete based on user input. (DFS, time complexity: O(Vertices + Edges), Space complexity : O(Vertices).
    - Find a certain search word (string) from suffix tree based on user input. (O(m) time where m is length of the string).
  
<br />

### Motivations behing choosing datastructures
  - Suffix tries enable search in O(m) time where m is the length of the pattern. This is better than other pattern matching algorithms which are 0(n) where n is the length of the text.
  - Suffix trees have a lower space complexity than suffix tries. With the help of Ukkonen's alorithm the suffix tre can be constructed in linear time. 

<br />

### Inputs the algorithms receive
  - User inputs
    - Word search : character/string
    - Autocompete: character/string

<br />

## Sources
  - Introduction to Algorithms(CLRS)
  - internet
  
<br />

## Study programe:
 Tietojenkäsittelytieteen kandidaatti (TKT) 
 
<br />

## Language for documentation, code and comments 
  - English
  - For peer review I can also write in Finnish. 





