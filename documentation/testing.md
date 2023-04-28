 ## Testing document

 
 ### 1. Static analysis (style)
 
- Static style analysis is performed using *Cppcheck*. 
- As *Cppcheck* does not find standard include headers, the check is suppressed and only custom header files are included.
- Code style has been checked using the command below. 
 

1. Install [**Cppcheck**](https://cppcheck.sourceforge.io/) if you don't have it installed yet. 

```bash
 sudo apt-get install cppcheck
```

2. Run style tests in project folder (.../patternmatching$). 

```bash
 cppcheck --quiet --enable=all --suppress=missingIncludeSystem --error-exitcode=1 main.cpp
```

### 2. Unit testing 

Unit testing using Google Test.


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

## What has been tested and how


## What types of input were used (especially important for comparative analysis)


## How can the tests be repeated


## Results of empirical testing presented in graphical form




