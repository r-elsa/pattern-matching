#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <algorithm>
#include <functional>
#include <tuple>
using namespace std;

   /* Class for calling the API,
    * parsing the JSON object,
    * doing some string mainpulating
    * and returning the final string.
    */// 
class APICall
{
public:
    APICall()
    {
        cout << "Instance created of APICall." << endl;
    }

    /* This function takes the API address and authentication key as paramethers
     * does API call using curl, does error handling
     * and stores json file in words.json
     */
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


    /* This function returns size of data in order to create a vector of right size
    */
    static size_t GetSizeOfDatafromAPI(void *data, size_t size, size_t nmemb, void *words)
    {
        ((std::string *)words)->append((char *)data, size * nmemb);
        return size * nmemb;
    }


    /* This function takes parses the json data from words.json file, 
     * loops the json for the fields "abstract" and "lead paragraph" for each article,
     * deletes special characters and transforms everything to lower case
     * and returns the final string  
     */
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
            string abstract_leadparagraph =  abstract;
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