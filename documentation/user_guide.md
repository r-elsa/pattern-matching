

## What to expect after compiling & running
(g++ main.cpp -o main -lcurl -Iinclude -ljsoncpp -std=c++17 AND  ./main)

1) The program will make an API call to [New York times API](https://developer.nytimes.com/) for articles
2) *Curl* will parse the JSON for *abstract* and *lead paragraph* fields.
3) The text will then be formatted (everything to lower case and delete special characters). 
4) A terminal character $ will be added to the end. It identifies as the leaf node.
5) The final test data can look something like this (articles retrieved 28.4): 


```bash
francis wants to reembrace hungarian christians but some worry the visit gives political cover to the countrys leader who is on the opposite side of nearly every issue important to the pontiff budapest pope francis who has made welcoming migrants embracing minorities and warning against nationalism central tenets of his pontificate visited budapest for the second time in less than two years on friday the trip gives prime minister viktor orban perhaps europes chief opponent of migrants closest ally of russia and most vocal critic of gay rights a political gift he is sure not to waste the filmmaker david lowery updates the classic tale with his own pixie dust saving whats good and scuttling the rest peter pan wendy is a case study in one of the agonies of growing up the realization that some of the entertainment that tickled us as youngsters as in the many troubling scenes in walt disneys animated adaptation of j m barries peter pan novel including the ditty what made the red man red have aged as gracefully as its lead character in the new season of the runup podcast the host astead w herndon interviews some of the political establishments loudest voices its not always easy the runup a new york times podcast hosted by the politics reporter astead w herndon returned this month to try to make sense of the political divisions in the united states and the intricacies of the presidential election no small tasks our columnist reviews the days puzzle warning contains spoilerswelcome to the wordle review be warned this article contains spoilers for todays puzzle solve wordle first or scroll at your own risk feeling stuck on todays puzzle we can help friday hi busy bees welcome to todays spelling bee forum there are a number of terms that appear in both this article and other online discussions of the spelling bee a glossary of those terms compiled by monicat a times reader can be found below for more spelling bee conversation check out deb amlens weekly humor column diary of a spelling bee fanatic what do you think this image is communicatingwhat do you think this image is saying how does it relate to or comment on society can you relate to it personally what is your opinion of its jimmy kimmel suggested that after leaving late night james corden should stick to corporate gigs podcasts maybe the masked singer welcome to best of late night a rundown of the previous nights highlights that lets you sleep and lets us get paid to watch comedy here are the best movies on netflix right now this word has appeared in articles on nytimes com in the past year can you use it in a sentencethe word curio has appeared in articles on nytimes com in the past year including on jan in indie makers to watch in the high jewelry scene by tina dark projections for russias energy industry evidence is mounting that russias natural gas export industry has fallen apart since the country invaded ukraine new estimates suggest that russias pipelineexports could drop by halfthis year compared with last year the city has about of the towers which opponents say are too large and poorly designed while fans say they benefit neighborhoods good morning well get an update on the new g towers that have been rising around the city well also track raul the peacocks night out and his return to home in the bronx zoo$
```

This might take a while as the time complexity of implementing a suffix trie is X. 

**Next up, the prompt *Type a word or sentence to search in the suffixtrie (empty space stops):* comes up.
You can either have a peek at the text above for words/sentences or alternatively use your imagination. **

E.g. 
```bash
for
```
Yes!
```bash
to
```
Yes!
```bash
in
```
Yes!
```bash
ukraine
```
Yes!
```bash
usa
```
No!
```bash
united
```
Yes!
```bash
united states
```
Yes!
```bash
united states of america
```
No!


**After empty space, in the prompt *Type character(s) for the suffixtrie to autocomplete (empty space stops):*, the DFS (preorder) algorithm give you suggestions on words based on input**

E.g. 

```bash
th
```
than </br>
that </br>
the </br>
there </br>
they </br>
think </br>
this </br>
those </br>

```bash
app
```
appear </br>
appeared </br>

```bash
z
```
query prefix not present



### Behind the scenes 

##### Suffixes for WORD SEARCH (not for AUTOCOMPLETE)

- Each path from *root* (first character) of to *leaf* ($) represents a suffix.
- The trie is implemented by storing each string.
 
           francis wants to ... in the bronx zoo$
            rancis wants to ... in the bronx zoo$
             ancis wants to ... in the bronx zoo$
              ncis wants to ... in the bronx zoo$
               cis wants to ... in the bronx zoo$
                is wants to ... in the bronx zoo$
                                 ...
                                       bronx zoo$
                                        ronx zoo$
                                         onx zoo$
                                          nx zoo$
                                           x zoo$
                                             zoo$
                                             zoo$
                                              oo$
                                               o$
                                                $



 
    
 
 
##### Input for AUTOCOMPLETE


 - In order to autocomplete a string the suffix trie stores words and not suffixes. 
 
           francis$
             wants$
                to$
         reembrace$
         hungarian$
                ...
            return$
                to$
              home$
                in$
               the$
             bronx$
               zoo$
 
 







 
