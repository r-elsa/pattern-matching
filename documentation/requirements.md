
# Requirement specification

<br />

## Aim of project:

The topic of the project is indexing with suffixes. Suffix tries (and regular tries) provide an efficent way to search any pattern from text in O(m) time where m is the length of the pattern. 
In order to traverse the trie, depth first search DFS (in-order traversal) is implemented. 

<br />

## Programming language:
- C++, for user interface cmd. 
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

4. **Features:**
    - Find a certain search word (string) from text based on user input. (O(m) time where m is length of the string).
    - Autocomplete based on user input. (DFS, time complexity: O(Vertices + Edges), Space complexity : O(Vertices).
  
<br />

### Motivations behing choosing datastructures
  - Suffix tries enable search in O(m) time where m is the length of the pattern. This is better than other pattern matching algorithms which are 0(n) where n is the length of the text. 

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





