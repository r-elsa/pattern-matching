
# Requirement specification

## Aim of project:

The topic of the project is indexing with suffixes. Suffix trees provide (after preprocessing text namely building suffix tree) an efficent way to search any pattern from text in O(m) time where m is the length of the pattern. 

Naive methods (Suffix tries, Suffix tree implementation without Ukkonen's algorithm) will be explored on the way to Suffix tree implementation with Ukkonen's algorithm. 

## Programming language:
- C++, for user interface C++ GUI application 
- I can peer review: C++, python

## Scope of the project:

1. HTTP request to REST Server of New York Times for text (data). (https://developer.nytimes.com/docs/articlesearch-product/1/overview)

2. Preprocessing: extract all the words from text to simple datastructure (vector).

3. Creation of datastructures 
    1. Suffix trie (naive method 1, Time complexity: 0(n2), Space complexity: : 0(n2), meaning superlinear growth. 
    2. Suffix tree (naive method 2, Time complexity: 0(n2), Space complexity: 0(n), reduced space compared to Suffix trie.
    3. Suffix tree based on Ukkonen's algorithm.  The motivation behind exploring the algorithm is that text might change frequently (news change every day) and the preprocessing of text may become costly, which Ukkonen's algorithm provides a solution for.

4. Testing of algorithm:
    - Find a certain search word (string) from text based on user input. (O(m) time where m is length of the word)
    - Count number of times that word occures in text
    - Autocomplete based on user input.
    - Comparison of time and efficiency in implementation of suffix tree (with & without ukkonen's algorithm).
  
 
### Motivations behing choosing datastructures
  - Suffix tries and trees enable search in O(m) time where m is the length of the pattern. This is better than other pattern matching algorithms which are 0(n) where n is the length of the text. 

### Inputs the algorithms receive
  - User inputs
    - Word search : string
    - Amount of occurences of word: string
    - Autocompete: string

## Sources
  - Introduction to Algorithms(CLRS)
  - internet

## Study programe:
 Tietojenkäsittelytieteen kandidaatti (TKT) 
 
## Language for documentation, code and comments 
  - English
  - For peer review I can also write in Finnish. 





