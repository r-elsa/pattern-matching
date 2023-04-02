
#define CATCH_CONFIG_MAIN
#include "../main.cpp"
#include "catch.hpp"  


TEST_CASE("Testing API with right API address and authkey") {
    APICall s = APICall();
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    string authkey = getenv("AUTH_KEY"); 
    REQUIRE(s.apicall(apiadress, authkey) == 0);
}


TEST_CASE("Testing API - verify correct status 200") {
    APICall s = APICall();
    string authkey = getenv("AUTH_KEY"); 
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    REQUIRE(s.apicall(apiadress,authkey) == "");
}


TEST_CASE("Testing API - verify that json is returned") {
    APICall s = APICall();
    string authkey = getenv("AUTH_KEY"); 
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    REQUIRE(s.apicall(apiadress,authkey) == "");
}

TEST_CASE("Testing  - verify that words.json is created") {
    APICall s = APICall();
    string authkey = getenv("AUTH_KEY"); 
    std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
    REQUIRE(s.apicall(apiadress,authkey) == "");
    REQUIRE(std::filesystem::exists("helloworld.txt") == 0);
}

TEST_CASE("Testing dataparsing  verify that it returns a vector of strings") {
    APICall s = APICall();
    REQUIRE(s.dataparsing() == "");
    REQUIRE(TYPE& dynamic_cast<TYPE&> (s.dataparsing());== std::vector);
}

 

