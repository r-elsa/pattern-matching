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

using namespace std;
const long long N = 1e5;
class SuffixTree{
        std::vector<tuple<int, char, int>> tree[N]; 
        string final_string;
    
    public:
        void setFinalString(string final_string){
            this-> final_string = final_string;
        }
        
        void getTree()
        {     }

    void print_final_string() {
            for (int i = 0; i < final_string.size(); i++) // print all words
                 std::cout << final_string[i] << endl;                    
        };
    
    void createSuffixTree(){          
        final_string = final_string + '$';    // adding terminator    
        int prev_id=0;
        char prev_letter = 'o';
        int prev_identifier = 0111;
        int counter = 1;
        char letter;
       
        for (int i = 0; i < final_string.size(); i++){
        
              for (int j = 0; j < final_string.substr(i).size(); j++){      
                    letter = final_string.substr(i)[j]; 
                    cout << letter << endl;
                 
                    bool nodeExists = checkIfNodeExists(prev_id, prev_letter, prev_identifier, letter); 
                  

                    if (nodeExists){ //nodeExists

                         if (letter == '$'){
                            prev_id = 0;
                            prev_letter ='o';
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
                    else
                    { // node does not exist  */
             
                        std::string identifier_counter = to_string(counter);                   
                        std::string identifier_letter = to_string(int(letter));               
                        std::string together = identifier_counter + identifier_letter;                        
                        int identifier = stoi(together);

                        /* cout <<"LETTER:"<< letter << endl;
                        cout << "LETTER IN ASCII " << identifier_letter << endl;
                        cout << "COUNTER " << identifier_counter << endl;
                        cout << "FINAL "<< identifier << endl;
                        cout << " " << endl; */
  
                        if (letter == '$'){
                            tree[(prev_id,prev_letter,prev_identifier)].push_back(std::make_tuple(counter, letter, identifier));
                            prev_id = 0;
                            prev_letter ='o';
                            prev_identifier = 0111;                           
                        }
                        else
                        {
                            tree[(prev_id,prev_letter,prev_identifier)].push_back(std::make_tuple(counter, letter, identifier));
                            prev_id = counter;
                            prev_letter = letter;
                            prev_identifier = identifier;     
                        }
                        counter++;                    
    }}; }}     
                
     void printFirstLevelChildrenOfRoot(){ 
            
         for (auto&& tuple: tree[(0,'o',0111)]){
                    int X;
                    char Y;
                    int Z;
                    std::tie(X, Y, Z) = tuple;
                    cout << X << " " << Y << " " << Z << endl;
                    }    
                     
    } 

    bool checkIfNodeExists(int prev_id, char prev_letter,int prev_identifier, char letter) {

        auto it = std::find_if(tree[(prev_id, prev_letter, prev_identifier)].begin(), tree[(prev_id, prev_letter, prev_identifier)].end(),
        [&letter](const std::tuple<int,char,int>& e) {
            return std::get<1>(e) == letter;});
            
            if (it != tree[(prev_id, prev_letter, prev_identifier)].end()) {
                return 1;
            }
            else{
                return 0;
            }} 
    
    pair<int,int> nodeDetails(int prev_id, char prev_letter,int prev_identifier, char letter) {

        auto it = std::find_if(tree[(prev_id, prev_letter, prev_identifier)].begin(), tree[(prev_id, prev_letter, prev_identifier)].end(),
        [&letter](const std::tuple<int,char,int>& e) {
            return std::get<1>(e) == letter;});
            std::pair<int,int> returnvalues;

            if (it != tree[(prev_id, prev_letter, prev_identifier)].end()) {
                returnvalues = std::make_pair(get<0>(*it),get<2>(*it));              
            }
            else{
               returnvalues= std::make_pair(get<0>(*it),get<2>(*it));             
            }
            return returnvalues;           
            } 


    bool followpath(string word){

        // follow path given by characters in 'word'. Return True (1) at end of path and False (0) if we fall off path.
        int prev_id=0;
        char prev_letter = 'o';
        int prev_identifier = 0111;
        char letter;
       
        for (int i = 0; i < word.size(); i++){
            letter = word[i];
            bool nodeExists = checkIfNodeExists(prev_id,prev_letter,prev_identifier,letter); 
            if (!(nodeExists)){
                return 0;
             
            }
            int existing_id;
            int existing_identifier;
            std::tie(existing_id, existing_identifier) = nodeDetails(prev_id, prev_letter, prev_identifier, letter); 
            prev_id = existing_id;
            prev_letter = letter;
            prev_identifier = existing_identifier;

      } 
      return 1; }  

    vector <string> autoComplete(string word){
        vector<string> vectorvtr = {};

        bool stringExists = followpath(word);
        if (!(stringExists)){
            vectorvtr.push_back("word does not exist");
            return vectorvtr;
        }

        vectorvtr = {"hello"};
        return vectorvtr;

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
            ((std::string*)words)-> append((char*) data, size * nmemb);
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
                            singleString += word +' ';
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
        string finalString = api_instance.dataparsing(); // parses data from json file and creates vector of string
        cout << finalString << endl;
        
        SuffixTree myinstance; // initialize suffixtree
        myinstance.setFinalString("the move is a");
        myinstance.createSuffixTree(); 
        myinstance.printFirstLevelChildrenOfRoot(); 

        //USER INPUT

        string userInputWord;
        cout << "Type a word to search in the suffixtree: ";
        cin >> userInputWord; 
        bool wordexists = myinstance.followpath(userInputWord); // check if word exists
        cout << wordexists << endl;

        string userInputAutoComplete;
        cout << "Type characters for the suffixtree to autocomplete: ";
        cin >> userInputAutoComplete; 
        std::vector<string> suggestions = myinstance.autoComplete(userInputAutoComplete); 
        for (int i = 0; i < suggestions.size(); i++){
            cout << suggestions[i] << endl;
        }

        return 0;}











