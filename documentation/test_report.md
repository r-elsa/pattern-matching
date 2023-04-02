 ## Testing
 
 ## 1. Static analysis

1. Install **Cppcheck** if you don't have it installed yet:

```bash
 sudo apt-get install cppcheck
```

2. Run tests in project folder (.../patternmatching$)

```bash
 cppcheck --enable=all --suppress=missingIncludeSystem main.cpp
```
