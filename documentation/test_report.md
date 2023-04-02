 ## Testing
 
 ## 1. Static analysis (style)

1. Install **Cppcheck** if you don't have it installed yet. Also available at https://cppcheck.sourceforge.io/ .

```bash
 sudo apt-get install cppcheck
```

2. Run tests in project folder (.../patternmatching$). (As cppcheck does not find standard include headers, the check is suppressed and only custom header files are included.)

```bash
 cppcheck --quiet --enable=all --suppress=missingIncludeSystem --error-exitcode=1 main.cpp
```

## 2. Unit testing 

1. Install **Catch2** if you don't have it installed yet. Also available at https://github.com/catchorg/Catch2 .

```bash
sudo apt-get update
```

```bash
sudo apt-get install catch
```

