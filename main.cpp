#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstdlib>


using namespace std;

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if (curl) {

    // get authentication key for API
    string authkey = getenv("AUTH_KEY");

    // concatination of url and auth key 
    string url = "https://api.nytimes.com/svc/search/v2/articlesearch.json?q=election&api-key="+authkey;
  
    // set url
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());


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

  return 0;
}