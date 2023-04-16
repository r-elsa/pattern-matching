
# Pattern matching 

The goal of the project is to develop data structures and algorithms for efficient pattern matching. The datastructures that will be explored are suffix tries, suffix trees and in addition, the Ukkonen's algorithm for efficient suffix tree implementation. The text will be sourced from New York Times REST API. Functionality that the application will have are: word search, count number of occurences of search word and autocomplete. All are based on user input. In addition the implementation time of suffix tree will be improved by the Ukkonen's algorithm and further analyzed.



[Requirement specification](https://github.com/r-elsa/treecomparison/blob/master/documentation/requirements.md)

[Progress report week 4](https://github.com/r-elsa/treecomparison/blob/master/documentation/progress_reports/week4.md)

[Time report](https://github.com/r-elsa/pattern-matching/blob/master/documentation/progress_reports/time_report.md)

[Testing](https://github.com/r-elsa/pattern-matching/blob/master/documentation/testing.md)



## Installation

1. Install **curl** if you don't have it installed yet:

```bash
sudo apt-get install libcurl4-openssl-dev
```


2. Install **JsonCpp** if you don't have it installed yet:

```bash
sudo apt-get install libjsoncpp-dev

```
```bash

sudo ln -s /usr/include/jsoncpp/json/ /usr/include/json
```


3. Go inside project folder (where *main.cpp* is) and add authentication key:
(or get your own key by signing up at https://developer.nytimes.com/docs/articlesearch-product/1/overview)

```bash
 export AUTH_KEY=5Qhi8r0Id0umhwQripAGo2YFmGBQ3kcj

```


4. Check that it worked (should print the auth key):

```bash
printenv AUTH_KEY

```


5. Compile (example for linux):

```bash
g++ main.cpp -o main -lcurl -Iinclude -ljsoncpp
```


6. Run file:

```bash
 ./main
```

