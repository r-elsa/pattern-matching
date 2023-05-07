# Implementation document

## Project structure 

Excluding all files that appear after compiling and running tests: CMakefiles, CMakeLists.txt, Makefile, cmake_install.cmake, executeTests & content of CMakefiles.


├── README.md <br />
├── documentation <br />
│   ├── implementation.md <br />
│   ├── progress_reports <br />
│   │   ├── time_report.md <br />
│   │   ├── week1.md <br />
│   │   ├── week2.md <br />
│   │   ├── week3.md <br />
│   │   └── week4.md <br />
│   ├── requirements.md <br />
│   ├── testing.md <br />
│   └── user_guide.md <br />
├── main <br />
├── main.cpp <br />
├── suffixtrie.cpp <br />
├── tests <br />
│   └── trie_test.cpp <br />
└── words.json <br />


## Implemented time and space complexities (big-O complexity analysis of (pseudo)code)

Suffix Trie:
- Preprocessing text  using all suffixes of text = 0(n^2)
- Pattern matching: 0(m)
- Total time complexity: 0(n^2 +m)



## Comparative performance and complexity analysis if applicable




## Possible flaws and improvements




## Sources

