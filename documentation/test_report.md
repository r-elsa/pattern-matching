 ## Testing
 
 ## 1. Static analysis

1. Install **Cppcheck** if you don't have it installed yet. Also available at https://cppcheck.sourceforge.io/ .

```bash
 sudo apt-get install cppcheck
```

2. Run tests in project folder (.../patternmatching$). (As cppcheck does not find standard include headers, the check is suppressed and only custom header files are included.)

```bash
 cppcheck --enable=all --suppress=missingIncludeSystem main.cpp
```
