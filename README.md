
# Pattern matching 

The goal of the project is to develop data structures and algorithms for efficient pattern matching. The datastructures that will be explored are [trie](https://en.wikipedia.org/wiki/Trie) and  [suffix trie](https://en.wikipedia.org/wiki/Trie). The test data will be sourced from [New York Times REST API](https://developer.nytimes.com/apis). Functionality that the application will have are: *word search* and *autocomplete*, both based on user input.

<br />


**Documentation:**

[Requirement specification](https://github.com/r-elsa/treecomparison/blob/master/documentation/requirements.md)

[User guide](https://github.com/r-elsa/pattern-matching/blob/master/documentation/user_guide.md)

[Implementation](https://github.com/r-elsa/pattern-matching/blob/master/documentation/implementation.md)

[Testing](https://github.com/r-elsa/pattern-matching/blob/master/documentation/testing.md)

[Time report](https://github.com/r-elsa/pattern-matching/blob/master/documentation/progress_reports/time_report.md)


<br />



## Installation, compilation and excecution
<br />

**Note: the commands are for Ubuntu 20.04.5. Please see links if the commands do not work.**

<br />

1. Install [**curl**](https://curl.se/download.html) if you don't have it installed yet:

```bash
sudo apt-get install libcurl4-openssl-dev
```

<br />

2. Install [**JsonCpp**](https://github.com/open-source-parsers/jsoncpp) if you don't have it installed yet:

```bash
sudo apt-get install libjsoncpp-dev

```
```bash

sudo ln -s /usr/include/jsoncpp/json/ /usr/include/json
```

<br />

3. Go inside project folder (where *main.cpp* is) and add authentication key. Or you can get your own key [here](https://developer.nytimes.com/docs/articlesearch-product/1/overview).

```bash
 export AUTH_KEY=5Qhi8r0Id0umhwQripAGo2YFmGBQ3kcj

```

<br />

4. Check that it worked (should print the auth key):

```bash
printenv AUTH_KEY

```

<br />

5. Compile:

```bash
g++ main.cpp -o main -lcurl -Iinclude -ljsoncpp -std=c++17
```

<br />

6. Run file:

```bash
 ./main
```

<br />

## Testing 
<br />

### Unit testing using Google Test


1. Install [**Google Test**](https://github.com/google/googletest) if you don't have it installed yet.

```bash
sudo apt-get install libgtest-dev
```

<br />

2. Install [**CMake**](https://cmake.org/install/) if you don't have it installed yet.

```bash
sudo apt-get install cmake
```

<br />


3. Go to folder where Google Test was installed.

```bash
cd /usr/src/gtest
```
```bash
sudo cp *.a /usr/lib
```

<br />

4. Go back to project folder and compile

```bash
cmake CMakeLists.txt
```

```bash
make
```

<br />

5. Run tests

```bash
./executeTests
```

<br />

### Test coverage using gcov and lcov

1. Install lcov if you don't already have it installed.

```bash
sudo apt-get install lcov
```

<br />

2. Navigate to *coverage* folder

```bash
cd coverage
```

<br />

3. Run

```bash
 lcov -c -d .. -o coverage.info
```

<br />

4. Generate visual 

```bash
genhtml -o results/ coverage.info
```

<br />


 ### Static analysis (style)
 
- Static style analysis is performed using *Cppcheck*. 
- As *Cppcheck* does not find standard include headers, the check is suppressed and only custom header files are included.
- Code style has been checked using the command below. 
 
<br />

1. Install [**Cppcheck**](https://cppcheck.sourceforge.io/) if you don't have it installed yet. 

```bash
 sudo apt-get install cppcheck
```

<br />

2. Run style tests in project folder.

```bash
 cppcheck --quiet --enable=all --suppress=missingIncludeSystem --error-exitcode=1 main.cpp
```
<br />
<br />

