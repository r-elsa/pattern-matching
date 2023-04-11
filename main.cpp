#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <unordered_map>


using namespace std;

class SuffixTree{
    public:
    std::vector<pair<int,char>> tree[1000]; 

    void create(){
        tree[(0,'o')].push_back(std::make_pair(1,'b')); // create root node.

    }

    void dfs(pair <int,char> node, pair<int,char> prev){
      
        cout << node.first;
        cout << node.second << endl;
        for (pair<int,char> next : tree[(node.first,node.second)]) {
            if (next == prev) continue;
            dfs(next, node);
        }
}

    void followpath(){
        dfs(std::make_pair(0,'o'),std::make_pair(0,'p'));


    }
    void hasSubString(){

    }

    void getId(string c){

       /*  auto index = std::distance(dict.begin(), std::find_if(dict.begin(), dict.end(), [&](const auto& pair) { return pair.first == soughtstring; }));
     */}
}  

;


class Helper{
    public:
    string final_string;
    

    void print_final_string() {
            for (int i = 0; i < final_string.size(); i++) // print all words
                 std::cout << final_string[i] << endl;
                    
        };
    
    void createSuffixTree(){
        final_string[final_string.size() - 1] = '$';   // adding terminator
       
      
        for (int i = 0; i < final_string.size(); i++){
            
              for (int j = 0; j < final_string.substr(i).size(); j++){
                /* cout << final_string.substr(i)[j] << endl; */
                if (final_string.substr(i)[j] == '$'){
                    cout << final_string.substr(i)[j] << endl;
                    // next instance is a new word -- check if root exists
                }
                else{

                    // continue to add as children of the previous 
                }
               
               /*  {'h': {'e': {'l': {'l': {'o': {'$': {}}}}}}, 'e': {'l': {'l': {'o': {'$': {}}}}}, 'l': {'l': {'o': {'$': {}}}, 'o': {'$': {}}}, 'o': {'$': {}}} */
               
        

              }

           

            
              
        };
          
     

    }

      
    

};


class APICall{ // Main class for doing API call to New York times and dfor parsing data and creating vector of strings 
   public:
         APICall(){ //Constructor
         cout << "Instance created of APICall." << endl;
      }
      // HELPERS

    int apicall(string &apiadress, string &authkey){
            CURL *curl;
            CURLcode res;
            std::string stringOfWords;

            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();
            if (curl) {
                string url = apiadress + authkey;    // concatination of url and auth key 
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());    // set url
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, GetSizeOfDatafromAPI);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stringOfWords);
                res = curl_easy_perform(curl);   // request prints to stdout

                if (res != CURLE_OK) {  // error checking
                std::cerr << "Error during curl request: " 
                            << curl_easy_strerror(res) << std::endl;
                }
                curl_easy_cleanup(curl);
                } else {
                    std::cerr << "Error initializing curl." << std::endl;}

            curl_global_cleanup();
            std::ofstream file("words.json");
            file << stringOfWords;
            return 0;    
            }

      
      static size_t GetSizeOfDatafromAPI(void *data, size_t size, size_t nmemb, void *words) {// returns size of data in order to create vector
            ((std::string*)words)-> append((char*)data, size * nmemb);
            return size * nmemb;
            }
    
     
      string dataparsing(void){ // parses json data from words.json file, creates strings and splits strings
            std:string singleString;
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
                std:: string endsign_included;
                for (auto letter : abstract_leadparagraph){

                    if (letter == ' ' or letter == '.' or letter ==','){
                        if ((!word.empty())){
                            singleString += word + ' ';
                            word.clear();
                        }
                }       
                else if (isalpha(letter) ){
                    char letter_lowercase = tolower(letter);
                    word = word + letter_lowercase;
                } }}

                
                return singleString;}

    
    };


    
        
int main() {
        /* APICall api_instance;  // Create an object of APICallAndParser - class
        std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
        string authkey = getenv("AUTH_KEY");  // get authentication key for API

        api_instance.apicall(apiadress, authkey);  // Calling API and storing data in json
        string finalString = api_instance.dataparsing(); // parses data from json file and creates vector of strings
        cout << finalString << endl; */

        Helper myinstance; // create an object of class Suffixtrie
        myinstance.final_string = "hello ";
        /* myinstance.print_final_string(); */  
        /* myinstance.createSuffixTree(); */

        SuffixTree mysuffixtree;
        mysuffixtree.create();
        
       
        mysuffixtree.tree[(0,'o')].push_back(std::make_pair(2,'c'));

        mysuffixtree.tree[(2,'c')].push_back(std::make_pair(3,'d'));
        mysuffixtree.tree[(1,'b')].push_back(std::make_pair(4,'y'));
        mysuffixtree.followpath();
        

        return 0;}












