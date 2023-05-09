
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <iostream>
#include <chrono>
#include "../includes/trie.h"
#include "../includes/helperfunctions.cpp"

using namespace std;

// Test data. Strings are named as [type]__[amount of characters]. 

// best case  - linear space
string linear_five = "aaaaa";
string linear_fifty = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
string linear_fivehundred = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa$";

// n^2 space
string quadratic_six = "aaabbb";
string quadratic_sixty = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
string quadratic_sixhundred = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb$";

// NY times testdata 

// 50 characters 
string nytimes_fifty = "a proposal to make new york the third state to$";
// 100 characters 
string nytimes_onehundred= "he assisted south like the journalist donald woods whose story was told in the movie cry freedom$";
// 200 characters 
string nytimes_twohundred = "is it time to ditch a powerful symbol of the american dream the perfect green lawnnote this is the last film club for the school year the astor place cube which has been stationary since is headed to$";
// 500 characters
string nytimes_fivehundred = "wideranging conversation this time the fashion designer and the ivory musician three days after his fall runway show in february while on his way to meet omar apollo at a photographers house in clinton hill brooklyn the yearold fashion designer willy chavarria studied the yearold musicians wikipedia page what chavarria lacked in detailed knowledge about apollos career he made up for with an immediate paternal tenderness each detail apollo revealed about himself during their afternoon together from$";
// 1000 characters
string nytimes_thousand = "microsoft linkedins owner had already pulled the flagship networking site from china in leaving only a strippeddown app that catered to job seekers linkedin the networking platform used by millions of employees and companies said on monday it will pare down its operations in china capping a multiyear pullback that exemplified the challenges of running a foreign business in china on a secluded cobblestone alley lined with former craftsmens workshops marin montagut makes a home steeped in the citys creative history parisians are often caricatured as blas yet when it comes to their citys cultural treasures they can be disarmingly sentimental new yorkers may dismiss the empire state building as kitsch but parisians have an unironic love for the eiffel tower and the arc de triomphe there is likewise widespread devotion to the capitals artisanal past many wouldnt dream for example of getting their brass door hardware anywhere but the thcentury a la providence on rue du faubourg st antoine or$";
// 1500 characters
string nytimes_thousandfivehundred = "lowkey smalltown existence as the characters on their favorite television shows leonard bernsteins country house hasnt changed much since he hosted stephen sondheim and jerome robbins there his daughter is ok with that leonard bernsteins country house hasnt changed much since he hosted stephen sondheim and jerome robbins there his daughter is ok with that the return of budget tour groups from mainland china is sparking frustrations and a dose of snobbery in a city starved for business one by one the tour buses descended on the blue collar neighborhood in hong kong known as to kwa wan literally translated as potato bay unloading throngs of travelers from mainland china outside large restaurants where a quick lunch awaited them inside mr burns a key figure in bolstering the biden administrations support for ukraine has amassed influence beyond most previous spy chiefs to mark the th anniversary of the americanled invasion of iraq the c i a director william j burns stood in the lobby of the agencys headquarters in langley va and sought to exorcise the ghosts of the prewar intelligence failures that haunt the building to this day the south carolina representative who has publicly criticized her party but backed it on most legislation is trying to figure out how to be a mainstreamrepublican in the hardright house g o p it was just after representative nancy mace republican of south carolina had fired off a blunt text to the no house g o p leader featuring two fbombs and four demands$";
// 2000 characters
string nytimes_twothousand = "the troubled lender is working on a lifeline but time is running out first republic is limping into the weekend days after reporting disastrous firstquarter results the bank is still working on a lifeline with some involved saying it is touch and go whether the federal government will assist in some way dealbook hears five countries whose farmers have been hurt by the policy including poland will get carveouts and compensation under an agreement reached friday brussels ukraines grains will continue to enter the european union tarifffree for another year despite protests from neighbors such as poland which have seen their own farmers hurt by the influx of cheaper foodstuffs the oil industry enjoyed record profits in after russia invaded ukraine but the prices of oil and natural gas have fallen sharply in recent months exxon mobil and chevron the two largest american oil companies reported modest earnings growth on friday as they were forced to manage their businesses in the face of sagging prices for oil and natural gas as the countrys oldest power station closed experts warn that the country needs a clearer strategy to manage its exit from coal power when it was first announced in that australias oldest power station liddell would close the news set off a political firestorm the metropolitan transportation authority said it would no longer provide service information on twitter because the reliability of the platform can no longer be guaranteed realtime train delays bus route changes and other service information that would be vital to millions of new york city commuters will no longer be shared on twitter because the reliability of the platform can no longer be guaranteed a metropolitan transportation authority official said on thursday long school closures have put public education and randi weingarten the leader of a major teachers union on the defensive during the early months of the covid pandemic randi weingarten and the teachers union she leads faced a vexing$";

string testdata1 = "he assisted south african dissidents like the journalist donald woods whose story was told in the movie cry freedom$";
string testdata2 = "a proposal to make new york the third state to ban menthol cigarettes has created a furious and expensive lobbying war$";

// 1. Time and space complexity testing 

// 1.1 Insertion 
TEST(CInsertTest, LinearFive)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, linear_five, testCurr));
}

TEST(CInsertTest, LinearFifty)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, linear_fifty, testCurr));
}

TEST(CInsertTest, LinearFiveHundred)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, linear_fivehundred, testCurr));
}

TEST(CInsertTest, QuadraticSix)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, quadratic_six, testCurr));
}

TEST(CInsertTest, QuadraticSixty)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, quadratic_sixty, testCurr));
}

TEST(CInsertTest, QuadraticSixHundred)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, quadratic_sixhundred, testCurr));
}

TEST(CInsertTest, NY_Fifty)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_fifty, testCurr));
}

TEST(CInsertTest, NY_OneHundred)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_onehundred, testCurr));
}

TEST(CInsertTest, NY_TwoHundred)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_twohundred, testCurr));
}

TEST(CInsertTest, NY_FiveHundred)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_fivehundred, testCurr));
}

TEST(CInsertTest, NY_Thousand)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_thousand, testCurr));
}

TEST(CInsertTest, NY_ThousandFiveHundred)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_thousandfivehundred, testCurr));
}

TEST(CInsertTest, NY_TwoThousand)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_twothousand, testCurr));
}


// 1.2 Search 

// Three tests to search the same string in tries of vastly different size. 
TEST(CSearchTest, DifferentSizesOfTriesTwoHundred)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_twohundred, testCurr));
    std::string searchString = "for";
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    ASSERT_EQ(1, subStringSearchHelper(testObj, nytimes_twohundred, testCurr, searchString));
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();  
    std::cout << "200 characters - Time difference: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
}


TEST(CSearchTest, DifferentSizesOfTriesFiveHundred)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_fivehundred, testCurr));
    std::string searchString = "for";
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    ASSERT_EQ(1, subStringSearchHelper(testObj, nytimes_fivehundred, testCurr, searchString));
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();  
    std::cout << "500 characters - Time difference: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    }


TEST(CSearchTest, DifferentSizesOfTriesThousand)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, nytimes_thousand, testCurr));
    std::string searchString = "for";
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    ASSERT_EQ(1, subStringSearchHelper(testObj, nytimes_thousand, testCurr, searchString));
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();  
    std::cout << "1000 characters - Time difference: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    }

// 2. Regular tests 
TEST(RInsertTest, SuffixNotFound1)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, testdata2, testCurr));
    std::string searchString = "fourth state";
    ASSERT_EQ(0, subStringSearchHelper(testObj, testdata1, testCurr, searchString));

}
TEST(RInsertTest, SuffixNotFound2)
{
    TrieNode testObj;
    TrieNode *testCurr = new TrieNode();
    ASSERT_EQ(1, suffixInsertionHelper(testObj, testdata2, testCurr));
    std::string searchString = "fourth state";
    ASSERT_EQ(0, subStringSearchHelper(testObj, testdata1, testCurr, searchString));

}

TEST(RInsertTest, WordInsert)
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


