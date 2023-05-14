# Implementation document

## Project structure 

Excluding all files that are added in .gitignore

├── CMakeLists.txt <br />
├── README.md <br />
├── documentation <br />
│   ├── images <br />
│   │   ├── code_coverage7.5.jpg <br />
│   │   ├── space_complexity_insertion.jpg <br />
│   │   ├── statistics.jpg <br />
│   │   ├── time_complexity_insertion.jpg <br />
│   │   └── time_complexity_search.jpg <br />
│   ├── implementation.md <br />
│   ├── progress_reports <br />
│   │   ├── time_report.md <br />
│   │   ├── week1.md <br />
│   │   ├── week2.md <br />
│   │   ├── week3.md <br />
│   │   ├── week4.md <br />
│   │   ├── week5.md <br />
│   │   └── week6.md <br />
│   ├── requirements.md <br />
│   ├── testing.md <br />
│   └── user_guide.md <br />
├── includes <br />
│   ├── apicall.cpp <br />
│   ├── apicall.h <br />
│   ├── helperfunctions.cpp <br />
│   ├── helperfunctions.h <br />
│   ├── trie.cpp <br />
│   ├── trie.h <br />
│   ├── ui.cpp <br />
│   └── ui.h <br />
├── main.cpp <br />
├── tests <br />
    ├── complexity_test.h <br />
    ├── main_test.cpp <br />
    └── regular_test.h <br />

<br />
<br />
<br />

## Implemented time and space complexities (big-O complexity analysis of (pseudo)code)

Suffix Trie:
- Preprocessing text  using all suffixes of text = 0(n^2)
- Pattern matching: 0(m)
- Total time complexity: 0(n^2 +m)

<br />
<br />
<br />

## Comparative performance and complexity analysis if applicable

<br />
<br />
<br />


## Possible flaws and improvements

<br />
<br />
<br />


## Sources

<br />
<br />
<br />

