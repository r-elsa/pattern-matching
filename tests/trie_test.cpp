
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "../includes/trie.h"
#include "../includes/helperfunctions.cpp"

using namespace std;

// space complexity testing

// bast case  - linear space
string bestcase_five = "aaaaa";
string bestcase_fifty = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";


// n^2 space
string quadratic_six = "aaabbb";
string quadratic_sixty = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";

// NY times testdata 
// 50 characters 
string nytimes_fifty = "a proposal to make new york the third state to$";


// 100 characters 
string nytimes_onehundred= "he assisted south like the journalist donald woods whose story was told in the movie cry freedom$";


// 200 characters 
string nytimes_twohundred = "";

// 500 characters

string nytimes_fivehundred = "wideranging conversation this time the fashion designer and the ivory musician three days after his fall runway show in february while on his way to meet omar apollo at a photographers house in clinton hill brooklyn the yearold fashion designer willy chavarria studied the yearold musicians wikipedia page what chavarria lacked in detailed knowledge about apollos career he made up for with an immediate paternal tenderness each detail apollo revealed about himself during their afternoon together from$";


// 1000 characters
string nytimes_thousand = "";


// 1500 characters
string nytimes_thousandfivehunderd = "";


// 2000 characters
string nytimes_twothousand = "the troubled lender is working on a lifeline but time is running out first republic is limping into the weekend days after reporting disastrous firstquarter results the bank is still working on a lifeline with some involved saying it is touch and go whether the federal government will assist in some way dealbook hears five countries whose farmers have been hurt by the policy including poland will get carveouts and compensation under an agreement reached friday brussels ukraines grains will continue to enter the european union tarifffree for another year despite protests from neighbors such as poland which have seen their own farmers hurt by the influx of cheaper foodstuffs the oil industry enjoyed record profits in after russia invaded ukraine but the prices of oil and natural gas have fallen sharply in recent months exxon mobil and chevron the two largest american oil companies reported modest earnings growth on friday as they were forced to manage their businesses in the face of sagging prices for oil and natural gas as the countrys oldest power station closed experts warn that the country needs a clearer strategy to manage its exit from coal power when it was first announced in that australias oldest power station liddell would close the news set off a political firestorm the metropolitan transportation authority said it would no longer provide service information on twitter because the reliability of the platform can no longer be guaranteed realtime train delays bus route changes and other service information that would be vital to millions of new york city commuters will no longer be shared on twitter because the reliability of the platform can no longer be guaranteed a metropolitan transportation authority official said on thursday long school closures have put public education and randi weingarten the leader of a major teachers union on the defensive during the early months of the covid pandemic randi weingarten and the teachers union she leads faced a vexing$";


// 2500 characters
string nytimes_twothousandfivehundred = "at any moment about one out of every two americans feels lonely how can we help one another feel more connecteddr vivek h murthy is the surgeon general of the united states as the nations doctor it is his job to protect and improve the health and safety of the american people the new surge at the u s mexico border highlights a broader reality about immigration policy the surge of migrants gathering at the u s mexico border underscores a point that democratic party politicians often try to play down u s border policy has a big effect on how many people try to enter the country illegally the meeting was one of the highestlevel engagements between american and chinese officials since the downing of a suspected chinese spy balloon in february chinas foreign minister qin gang met with the american ambassador to china in beijing on monday ina possible hint at a thaw in relations between the two powers after months of growing tension allegations of misconduct have brought calls for tighter rules on the justices on the nations highest court debate about ethical standards for supreme court justices has intensified after a series of revelations about undisclosed gifts luxury travel and property deals the i r a will spur the takeover of our infrastructure by private entities particularly large global asset managers with likely negative consequences the inflation reduction act will reshape the physical and economic landscape of the united states over the next decade including in ways that might surprise a lot of people gardeners and small farmers are growing food with minimal water in ways large and small that could help the southwest survive an epochal drought kim elle had never grown anything more complicated than houseplants when she and her husband moved from georgia to suburban phoenix in faced with a sizable yard in a wellgroomed subdivision she turned to gardening fighting superior russian firepower ukrainian forces turn offtheshelf drones into deadly weapons by adapting them to carry explosives buzzing like an oversize mosquito a small drone lifted off from a farm field in eastern ukraine hovered for a bit then raced toward russian positions near the battleravaged city of bakhmut the annual spectacle featuring fanciful caravans and riders on horseback and is arguably the most potent visual representation of andalusian culture you cant wear that flamenco dress for the el roco pilgrimage bonita maria crdenas our airbnb host said with a laugh youll die in the heat$";

// 3000 characters 
string nytimes_threethousand = "the new surge at the us mexico border highlights a broader reality about immigration policy the surge of migrants gathering at the u s mexico border underscores a point that democratic party politicians often try to play down u s border policy has a big effect on how many people try to enter the country illegally the meeting was one of the highestlevel engagements between american and chinese officials since the downing of a suspected chinese spy balloon in february chinas foreign minister qin gang met with the american ambassador to china in beijing on monday ina possible hint at a thaw in relations between the two powers after months of growing tension allegations of misconduct have brought calls for tighter rules on the justices on the nations highest court debate about ethical standards for supreme court justices has intensified after a series of revelations about undisclosed gifts luxury travel and property deals the ira will spur the takeover of our infrastructure by private entities particularly large global asset managers with likely negative consequences the inflation reduction act will reshape the physical and economic landscape of the united states over the next decade including in ways that might surprise a lot of people gardeners and small farmers are growing food with minimal water in ways large and small that could help the southwest survive an epochal drought kim elle had never grown anything more complicated than houseplants when she and her husband moved from georgia to suburban phoenix in faced with a sizable yard in a wellgroomed subdivision she turned to gardening fighting superior russian firepower ukrainian forces turn offtheshelf drones into deadly weapons by adapting them to carry explosives buzzing like an oversize mosquito a small drone lifted off from a farm field in eastern ukraine hovered for a bit then raced toward russian positions near the battleravaged city of bakhmut the annual spectacle featuring fanciful caravans and riders on horseback and is arguably the most potent visual representation of andalusian culture you cant wear that flamenco dress for the el roco pilgrimage bonita maria crdenas our airbnb host said with a laugh youll die in the heat two creative people in two different fields in one wideranging conversation this time the fashion designer and the ivory musician three days after his fall runway show in february while on his way to meet omar apollo at a photographers house in clinton hill brooklyn the yearold fashion designer willy chavarria studied the yearold musicians wikipedia page what chavarria lacked in detailed knowledge about apollos career he made up for with an immediate paternal tenderness each detail apollo revealed about himself during their afternoon together from his recent grammy nomination for best new artist to his middle name apolonio also the title of his mixtape drew oohs and aahs from chavarria a senior vice president at calvin klein and the founder of his own namesake line$";



string testdata1 = "he assisted south african dissidents like the journalist donald woods whose story was told in the movie cry freedom$";
string testdata2 = "a proposal to make new york the third state to ban menthol cigarettes has created a furious and expensive lobbying war$";


TEST(InsertAndSearchTest, SuffixFound)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, testdata1, testCurr));
    std::string searchString = "movie cry freedom";
    ASSERT_EQ(1, subStringSearchHelper(testObj, testdata1, testCurr, searchString));

}

TEST(InsertAndSearchTest, SuffixNotFound)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, testdata2, testCurr));
    std::string searchString = "fourth state";
    ASSERT_EQ(0, subStringSearchHelper(testObj, testdata1, testCurr, searchString));

}

TEST(InsertTest, WordInsert)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, wordInsertionHelper(testObj, testdata1, testCurr));
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


