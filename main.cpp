#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>

using namespace std;


static size_t 
GetSizeOfDatafromAPI(void *data, size_t size, size_t nmemb, void *words)
{
    ((std::string*)words)-> append((char*)data, size * nmemb);
    return size * nmemb;
}


int loopOverJson(void){
    cout << "Json data parsing to be continued!" <<endl;
    return 1;
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
  loopOverJson();

  return 0;
}