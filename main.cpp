#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json/json.h>

using namespace std;


static size_t 
GetSizeOfDatafromAPI(void *data, size_t size, size_t nmemb, void *words)
{
    ((std::string*)words)-> append((char*)data, size * nmemb);
    return size * nmemb;
}




 vector<string> loopOverJson(void){
    std::vector<std::string> vector_of_words{};
    
    std::ifstream file_input("words.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(file_input, obj);
    const Json::Value& jsonofarticles =  obj["response"]["docs"]; // 
    for (int i = 0; i < jsonofarticles.size(); i++){
        string abstract = jsonofarticles[i]["abstract"].asString();
        string lead_paragraph =  jsonofarticles[i]["lead_paragraph"].asString();
        string abstract_leadparagraph = abstract + lead_paragraph;


        std::string word;
        for (auto letter : abstract_leadparagraph){

            if (letter == ' ' or letter == '.' or letter ==','){
                if ((!word.empty())){
                    vector_of_words.push_back(word);
                     word.clear();

                }
         

           }       
           else if (isalpha(letter) ){
            char letter_lowercase = tolower(letter);
            word = word + letter_lowercase;
           } 

           

        }
    

        }
  
 
    return vector_of_words;

                }


int main(void)
{
 
  CURL *curl;
  CURLcode res;
  std::string stringOfWords;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if (curl) {

    // get authentication key for API
    string authkey = getenv("AUTH_KEY");

    // concatination of url and auth key 
    string url = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key="+authkey;
  
    // set url
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
 
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, GetSizeOfDatafromAPI);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stringOfWords);
 
    // request prints to stdout
    res = curl_easy_perform(curl);


    // error checking
    if (res != CURLE_OK) {
      std::cerr << "Error during curl request: " 
                << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  } else {
    std::cerr << "Error initializing curl." << std::endl;
  }

  curl_global_cleanup();
  std::ofstream file("words.json");
  file << stringOfWords;
std::vector<std::string> vector_of_words = loopOverJson();


  for (int i = 0; i < vector_of_words.size(); i++)
      std::cout << vector_of_words[i] << endl;

  return 0;
}