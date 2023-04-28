#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <algorithm>
#include <functional>
#include <tuple>
#include "suffixtrie_hashmap.cpp"
using namespace std;

// Main class for doing API call to New York times and dfor parsing data and creating vector of strings
class APICall
{
public:
    APICall()
    {
        cout << "Instance created of APICall." << endl;
    }

    int apicall(string &apiadress, string &authkey)
    {
        CURL *curl;
        CURLcode res;
        std::string stringOfWords;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        if (curl)
        {
            string url = apiadress + authkey;
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, GetSizeOfDatafromAPI);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stringOfWords);
            res = curl_easy_perform(curl);

            if (res != CURLE_OK)
            {
                std::cerr << "Error during curl request: "
                          << curl_easy_strerror(res) << std::endl;
            }
            curl_easy_cleanup(curl);
        }
        else
        {
            std::cerr << "Error initializing curl." << std::endl;
        }
        curl_global_cleanup();
        std::ofstream file("words.json");
        file << stringOfWords;
        return 0;
    }
    // returns size of data in order to create vector
    static size_t GetSizeOfDatafromAPI(void *data, size_t size, size_t nmemb, void *words)
    {
        ((std::string *)words)->append((char *)data, size * nmemb);
        return size * nmemb;
    }
    // parses json data from words.json file, creates strings and splits strings
    string dataparsing(void)
    {
        string singleString;
        std::ifstream file_input("words.json");
        Json::Reader reader;
        Json::Value obj;
        reader.parse(file_input, obj);
        const Json::Value &jsonofarticles = obj["response"]["docs"];
        for (int i = 0; i < jsonofarticles.size(); i++)
        {
            string abstract = jsonofarticles[i]["abstract"].asString();
            string lead_paragraph = jsonofarticles[i]["lead_paragraph"].asString();
            string abstract_leadparagraph = lead_paragraph;

            std::string word;
            for (auto letter : abstract_leadparagraph)
            {
                if (letter == ' ' or letter == '.' or letter == ',')
                {
                    if ((!word.empty()))
                    {
                        singleString += word + ' ';
                        word.clear();
                    }
                }
                else if (isalpha(letter))
                {
                    char letter_lowercase = tolower(letter);
                    word = word + letter_lowercase;
                }
            }
        }
        singleString[singleString.size() - 1] = '$';
        return singleString;
    }
};

int main()
{
    APICall api_instance;
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    string authkey = getenv("AUTH_KEY");

    api_instance.apicall(apiadress, authkey);
    string finalString = api_instance.dataparsing();
    cout << finalString << endl;

    TrieNode myObj;
    TrieNode *curr = new TrieNode();

    // inserting data into suffix trie myObj
    for (int i = 0; i < finalString.size(); i++)
    {
        myObj.insert(curr, finalString.substr(i));
    }

    // search if string exists in trie
    std::string searchString;
    cout << " " << endl;
    cout << "Type a word or sentence to search in the suffixtrie (empty space stops):";

    while (true)
    {
        getline(std::cin, searchString);
        if (searchString.empty())
        {
            break;
        }
        auto [isSubstring_search, location_search] = myObj.search(curr, searchString);
        if (isSubstring_search)
        {
            cout << "Yes! " << endl;
        }
        else
        {
            cout << "No!" << endl;
        }
    }

    // autocomplete feature
    TrieNode myObj_autocomplete;
    TrieNode *curr_autocomplete = new TrieNode();
    std::string word;

    for (int i = 0; i < finalString.size(); i++)
    {
        if (finalString[i] == ' ')
        {
            word += '$';
            myObj_autocomplete.insert(curr_autocomplete, word);
            cout << word << endl;
            word = "";
        }
        else
        {
            word = word + finalString[i];
        }
    }

    string autoCompleteString;
    cout << " " << endl;
    cout << "Type character(s) for the suffixtrie to autocomplete (in progress, prefix needs to be adjusted to depth of tree): ";

    cin >> autoCompleteString;
    auto [isSubstring_autocomplete, location_autocomplete] = myObj_autocomplete.search(curr_autocomplete, autoCompleteString);
    if (isSubstring_autocomplete)
    {
        vector<string> suggestions = myObj_autocomplete.preorder(location_autocomplete, autoCompleteString);
        for (int i = 0; i < suggestions.size(); i++)
        {
            cout << "HELO" << endl;
            cout << suggestions[i] << endl;
        }
    }
    else
    {
        cout << "query prefix not present" << endl;
    }
    return 0;
}
