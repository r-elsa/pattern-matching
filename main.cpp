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
using namespace std;



class SuffixTree{
        std::vector<pair<int,char>> tree[10000]; 
        string final_string;
    
    public:
        void setFinalString(string final_string){
            this-> final_string = final_string;
        }
        
        void getTree()
        { 
        }

    void print_final_string() {
            for (int i = 0; i < final_string.size(); i++) // print all words
                 std::cout << final_string[i] << endl;                    
        };
    
    void createSuffixTree(){          
        final_string[final_string.size() - 1] = '$';   // adding terminator

        pair <int, char> prev_node;
        prev_node.first=0;
        prev_node.second = 'o';
        int counter = 1;
        char letter;
       
        for (int i = 0; i < final_string.size(); i++){
              for (int j = 0; j < final_string.substr(i).size(); j++){      
                    letter = final_string.substr(i)[j]; 
                    /* cout << letter << endl;   */   
                    /* bool nodeExists = checkIfNodeExists(prev_node, letter); */
                    /* cout << nodeExists << endl; */

                    /* if (nodeExists){
                        
                        if (letter == '$'){
                            int node_id = getNodeId(prev_node,letter);
                            prev_node.first = 0;
                            prev_node.second= 'o';
                        }
                        else
                        {
                             int node_id = getNodeId(prev_node,letter);
                             prev_node.first = node_id;
                             prev_node.second=letter;
                        }  
                    }
                    else
                    { // node does not exist  */
                        
                        if (letter == '$'){
                            tree[(prev_node.first,prev_node.second)].push_back(std::make_pair(counter,letter));
                            prev_node.first = 0;
                            prev_node.second='o';
                        }
                        else
                        {
                            tree[(prev_node.first,prev_node.second)].push_back(std::make_pair(counter,letter));
                            prev_node.first = counter;
                            prev_node.second = letter;
                            
                        }
                        counter++;                    
                     }}; }     
                
    void printFirstLevelChildrenOfRoot(){ 
        for(int i = 0; i < tree[(0,'o')].size(); i++){
            cout << tree[(0,'o')][i].first << ", " << tree[(0,'o')][i].second << endl;}                
    }

    bool checkIfNodeExists(std::pair<int, char> node, char letter){
        /* cout << node.first;
        cout << node.second << endl;
        cout << letter<< endl; */
        auto it = std::find_if( tree[(node.first, node.second)].begin(), tree[(node.first,node.second)].end(),[&letter](const std::pair<int, char>& element){ 
            return element.second == letter;} );
        
        if (it != tree[(node.first, node.second)].end()) {  // check if iterator points to end of vector --> no letter exists
            return 1;  }
        else {
            return 0;}

    }

    int getNodeId(std::pair<int, char> node, char letter){
        auto it = std::find_if( tree[(node.first, node.second)].begin(), tree[(node.first,node.second)].end(),[&letter](const std::pair<int, char>& element){ 
            return element.second == letter;} );
            
            return it-> first;
        
    }

    void dfs(pair <int,char> node, pair<int,char> prev){
        /* cout << node.first;
        cout << node.second << endl; */
        for (pair<int,char> next : tree[(node.first, node.second)]) {
            if (next == prev) continue;
            dfs(next, node);
        }}

    void followpath(){
        dfs(std::make_pair(1,'t'), std::make_pair(0,'o')); // first is root node, second is imaginary previous node 

    }
    void hasSubString(){

    }
  
};


class APICall{ // Main class for doing API call to New York times and dfor parsing data and creating vector of strings 
   public:
         APICall(){ //Constructor
         cout << "Instance created of APICall." << endl;
      }

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
        APICall api_instance;  // Create an object of APICallAndParser - class
        std::string apiadress = "https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key=";
        string authkey = getenv("AUTH_KEY");  // get authentication key for API

        api_instance.apicall(apiadress, authkey);  // Calling API and storing data in json
        string finalString = api_instance.dataparsing(); // parses data from json file and creates vector of strings
        /* cout << finalString << endl; */

        SuffixTree myinstance; 
        myinstance.setFinalString("test ");
        myinstance.createSuffixTree(); 
        /* myinstance.followpath();  */
        myinstance.printFirstLevelChildrenOfRoot();
      
           
        return 0;}












