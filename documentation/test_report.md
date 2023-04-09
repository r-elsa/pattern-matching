 ## Testing document

 
 ### 1. Static analysis (style)
 
- Static style analysis is performed using *Cppcheck*. 
- As *Cppcheck* does not find standard include headers, the check is suppressed and only custom header files are included.
- Code style has been checked using the command below. 
 

1. Install **Cppcheck** if you don't have it installed yet. Also available at https://cppcheck.sourceforge.io/ .

```bash
 sudo apt-get install cppcheck
```

2. Run style tests in project folder (.../patternmatching$). 

```bash
 cppcheck --quiet --enable=all --suppress=missingIncludeSystem --error-exitcode=1 main.cpp
```

### 2. Unit testing 

Unit testing is currently in the process of being implemented. While the library *Catch2* seems lightweight and great for the purposes of this project it is currently being upgraded and documentation is not up to date.


1. Install **Catch2** if you don't have it installed yet. Also available at https://github.com/catchorg/Catch2 .

```bash
sudo apt-get update
```

```bash
sudo apt-get install catch
```

