
# Pattern matching 

The goal of the project is to develop data structures and algorithms for efficient pattern matching. The datastructures that will be explored are [suffix tries](https://en.wikipedia.org/wiki/Trie)(, [suffix trees](https://en.wikipedia.org/wiki/Suffix_tree) and in addition, the [Ukkonen's algorithm](https://en.wikipedia.org/wiki/Ukkonen%27s_algorithm) for efficient suffix tree implementation.) The text will be sourced from [New York Times REST API](https://developer.nytimes.com/apis). Functionality that the application will have are: word search, autocomplete and count number of occurences of search word. All are based on user input. In addition the implementation time of suffix tree will be improved by the Ukkonen's algorithm and further analyzed.



[Requirement specification](https://github.com/r-elsa/treecomparison/blob/master/documentation/requirements.md)

[Progress report week 6](https://github.com/r-elsa/treecomparison/blob/master/documentation/progress_reports/week6.md)

[Time report](https://github.com/r-elsa/pattern-matching/blob/master/documentation/progress_reports/time_report.md)

[Testing](https://github.com/r-elsa/pattern-matching/blob/master/documentation/testing.md)



## Installation, compilation and excecution

### Note: the commands are for Ubuntu 20.04.5. Please see links if the commands do not work. 


1. Install [**curl**](https://curl.se/download.html) if you don't have it installed yet:

```bash
sudo apt-get install libcurl4-openssl-dev
```


2. Install [**JsonCpp**](https://github.com/open-source-parsers/jsoncpp) if you don't have it installed yet:

```bash
sudo apt-get install libjsoncpp-dev

```
```bash

sudo ln -s /usr/include/jsoncpp/json/ /usr/include/json
```


3. Go inside project folder (where *main.cpp* is) and add authentication key. Or you can get your own key [here](https://developer.nytimes.com/docs/articlesearch-product/1/overview).

```bash
 export AUTH_KEY=5Qhi8r0Id0umhwQripAGo2YFmGBQ3kcj

```


4. Check that it worked (should print the auth key):

```bash
printenv AUTH_KEY

```


5. Compile:

```bash
g++ main.cpp -o main -lcurl -Iinclude -ljsoncpp -std=c++17
```


6. Run file:

```bash
 ./main
```


## Testing 

### Unit testing using Google Test


1. Install [**Google Test**](https://github.com/google/googletest) if you don't have it installed yet.

```bash
sudo apt-get install libgtest-dev
```
2. Install [**CMake**](https://cmake.org/install/) if you don't have it installed yet.

```bash
sudo apt-get install cmake
```

3. Go to folder where Google Test was installed.

```bash
cd /usr/src/gtest
```
```bash
sudo cp *.a /usr/lib
```

4. Go back to project folder and compile

```bash
cmake CMakeLists.txt
```

```bash
make
```

5. Run tests

```bash
./executeTests
```

### Test coverage using gcov and lcov

1. Install lcov if you don't already have it installed.

```bash
sudo apt-get install lcov
```

2. Navigate to *coverage* folder

```bash
cd coverage
```
3. Run

```bash
 lcov -c -d .. -o coverage.info
```

4. Generate visual 

```bash
genhtml -o results/ coverage.info
```


 ### Static analysis (style)
 
- Static style analysis is performed using *Cppcheck*. 
- As *Cppcheck* does not find standard include headers, the check is suppressed and only custom header files are included.
- Code style has been checked using the command below. 
 

1. Install [**Cppcheck**](https://cppcheck.sourceforge.io/) if you don't have it installed yet. 

```bash
 sudo apt-get install cppcheck
```

2. Run style tests in project folder.

```bash
 cppcheck --quiet --enable=all --suppress=missingIncludeSystem --error-exitcode=1 main.cpp
```

