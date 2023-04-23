#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <tuple>
#include <functional>
using namespace std;

// This is a first attempt to build a suffix trie using adjacency lists (vectors).
// However, due to limited space (10^5 of a vector) the implementation remains unused as it is not sufficient for the amount of data aimed to use.
// Please see suffixtree_hashmap.cpp for optimal solution using suffix trie.

class SuffixTrie
{

    std::vector<tuple<int, char, int>> trie[100000];
    string final_string;

public:
    void setFinalString(string final_string)
    {
        this->final_string = final_string;
    }

    void print_final_string()
    {
        for (int i = 0; i < final_string.size(); i++)
            std::cout << final_string[i] << endl;
    };

    void createSuffixTrie()
    {
        final_string = final_string + '$'; // adding terminator
        int prev_id = 0;
        char prev_letter = 'o';
        int prev_identifier = 0111;
        int counter = 1;
        char letter;

        for (int i = 0; i < final_string.size(); i++)
        {
            for (int j = 0; j < final_string.substr(i).size(); j++)
            {
                letter = final_string.substr(i)[j];
                bool nodeExists = checkIfNodeExists(prev_id, prev_letter, prev_identifier, letter);

                if (nodeExists)
                { // nodeExists
                    if (letter == '$')
                    {
                        prev_id = 0;
                        prev_letter = 'o';
                        prev_identifier = 0111;
                    }
                    else
                    {
                        int existing_id;
                        int existing_identifier;
                        std::tie(existing_id, existing_identifier) = nodeDetails(prev_id, prev_letter, prev_identifier, letter);

                        prev_id = existing_id;
                        prev_letter = letter;
                        prev_identifier = existing_identifier;
                    }
                }
                else // node does not exist  */
                {
                    std::string identifier_counter = to_string(counter);
                    std::string identifier_letter = to_string(int(letter));
                    std::string together = identifier_counter + identifier_letter;
                    int identifier = stoi(together);

                    if (letter == '$')
                    {
                        trie[(prev_id, prev_letter, prev_identifier)].push_back(std::make_tuple(counter, letter, identifier));

                        prev_id = 0;
                        prev_letter = 'o';
                        prev_identifier = 0111;
                    }
                    else
                    {
                        trie[(prev_id, prev_letter, prev_identifier)].push_back(std::make_tuple(counter, letter, identifier));

                        prev_id = counter;
                        prev_letter = letter;
                        prev_identifier = identifier;
                    }
                    counter++;
                }
            };
        }
    }

    void printFirstLevelChildrenOfRoot()
    {
        for (auto &&tuple : trie[(0, 'o', 0111)])
        {
            int X;
            char Y;
            int Z;
            std::tie(X, Y, Z) = tuple;
            cout << X << " " << Y << " " << Z << endl;
        }
    }

    bool checkIfNodeExists(int prev_id, char prev_letter, int prev_identifier, char letter)
    {

        auto it = std::find_if(trie[(prev_id, prev_letter, prev_identifier)].begin(), trie[(prev_id, prev_letter, prev_identifier)].end(),
                               [&letter](const std::tuple<int, char, int> &e)
                               { return std::get<1>(e) == letter; });

        if (it != trie[(prev_id, prev_letter, prev_identifier)].end())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    pair<int, int> nodeDetails(int prev_id, char prev_letter, int prev_identifier, char letter)
    {
        auto it = std::find_if(trie[(prev_id, prev_letter, prev_identifier)].begin(), trie[(prev_id, prev_letter, prev_identifier)].end(),
                               [&letter](const std::tuple<int, char, int> &e)
                               { return std::get<1>(e) == letter; });
        std::pair<int, int> returnvalues;

        if (it != trie[(prev_id, prev_letter, prev_identifier)].end())
        {
            returnvalues = std::make_pair(get<0>(*it), get<2>(*it));
        }
        else
        {
            returnvalues = std::make_pair(get<0>(*it), get<2>(*it));
        }
        return returnvalues;
    }

 // follow path given by characters in 'word'. Return True (1) at end of path and False (0) if we fall off path.
    bool followpath(string word)
    {
       
        int prev_id = 0;
        char prev_letter = 'o';
        int prev_identifier = 0111;
        char letter;

        for (int i = 0; i < word.size(); i++)
        {
            letter = word[i];
            bool nodeExists = checkIfNodeExists(prev_id, prev_letter, prev_identifier, letter);
            if (!(nodeExists))
            {
                return 0;
            }
            int existing_id;
            int existing_identifier;
            std::tie(existing_id, existing_identifier) = nodeDetails(prev_id, prev_letter, prev_identifier, letter);
            prev_id = existing_id;
            prev_letter = letter;
            prev_identifier = existing_identifier;
        }
        return 1;
    }
};
