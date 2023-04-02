
#define CATCH_CONFIG_MAIN
#include "../main.cpp"
#include "catch.hpp"  


TEST_CASE("Testing API : with right API address and authkey") {
    APICall s = APICall();
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    string authkey = getenv("AUTH_KEY"); 
    REQUIRE(s.apicall(apiadress, authkey) == 0);
}


TEST_CASE("Testing API - verify correct status 200") {
    APICall s = APICall();
    string authkey = getenv("AUTH_KEY"); 
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    REQUIRE(s.apicall(apiadress,authkey) == 200);
}


TEST_CASE("Testing  - verify that words.json is created") {
    APICall s = APICall();
    string authkey = getenv("AUTH_KEY"); 
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    REQUIRE(s.apicall(apiadress,authkey) == 0);
    REQUIRE(std::filesystem::exists("helloworld.txt") == 0);
}

TEST_CASE("Testing dataparsing - verify that vector length is longer than 20 ") {
    APICall s = APICall();
    vect = s.dataparsing();
    REQUIRE(int t=count(vec.begin(),vec.end(),item)>20)
}

 
