
# Tree comparison

The goal of the project is to get to know new and challenging data structures that apply the structure of a tree. The objects of comparison are four different datastructures (trees) and four different problems, and to investigate which algorithm is the best in which problem situation. Possibly, the data structures are also ranked based on their suitability.

[Requirement specification](https://github.com/r-elsa/treecomparison/blob/master/documentation/requirements.md)

[Progress reports](https://github.com/r-elsa/treecomparison/tree/master/documentation/progress_reports)

[Time report](https://github.com/r-elsa/treecomparison/blob/master/documentation/progress_reports/time_report.md)



## Installation

1. Install **curl** if you don't have it installed yet:

```bash
$ sudo apt-get install libcurl4-openssl-dev
```

2. Go inside project folder (where *main.cpp* is) and add authentication key:

```bash
$ export AUTH_KEY=5Qhi8r0Id0umhwQripAGo2YFmGBQ3kcj

```

3. Check that it worked (should print the auth key):

```bash
$ printenv AUTH_KEY

```


3. Compile:

```bash
$ g++ main.cpp -o main -lcurl -Iinclude
```

2. Run file:

```bash
 $ ./main
```

