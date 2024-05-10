import unittest
from algorithm.ukkonen import  is_substring, ukkonen, Node, count_nodes_dfs
import timeit
import time


# 4000 characters
fourthousand = "while enough for no the bigbudget original movie gave hollywood its moslowest start to its summer box office season since the fall guy seemed to have everything after letting exclusive talks with the movie studio skydance lapse paramounts directors met over the weekend and decided to negotiate with all the suitors paramount has decided to formally open negotiations with a bidding group led by sony pictures entertainment and the private equity giant apollo according to three people familiar with the matter the move comes after a period of exclusive talks with the hollywood studio skydance lapsed on friday night rivers in southeast texas could be swollen for days or weeks forecasters said as multiple rounds of heavy rainfall continued on sunday southeast texas faced more heavy rainfall on sunday with forecasters warning that flash flooding could happen in houston after several rounds of storms in the past few days prompted evacuations and rescues in the area the south dakota governor defending her tale of shooting and killing her familys dog suggested that president bidens german shepherd commander had merited a similar fate gov kristi noem of south dakota already under fire for killing her familys monthold dog and boasting about it on sunday took aim at another familys pet commander president bidens biteprone german shepherd he won tournaments before moving into tv he explained the game that was going out in front of him in a very relaxed manner a former cbs producer said peter oosterhuis a british golfer who won tournaments around the world played in the ryder cup six times and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte n c he was a section of the highway a crucial link between connecticut and new york city had closed on thursday when fuel from a burning tanker ignited an overpass a section of interstate in connecticut reopened on sunday morning after a fiery accident last week damaged an overpass and shut down the highway a major artery along the east coast the pop superstar performed a final date on her global trek marking four decades of hits a set on copacabana beach before the largest live crowd of her career when madonna stepped out onto the mammoth stage constructed on rio de janeiros copacabana beach on saturday night in a gleaming halo headpiece and black kimono she was greeted by the largest live crowd of her fourdecade career readers discuss a guest essay that argued they are both also college roommates tech in school truths about russia water and politics to the with horseradishcheddar tuna melts and vegan tantanmen for the coming week good morning it was peak cherry blossoms last week where i stay the flowers almost ready to spring off their branches to blanket the curbs like drifts of snow there was a deep humidity in the air and it made me think of summer down south the way the atmosphere can seem almost liquid under the sun everything ripe everything slow i made sweet tea and drank it over an enormous amount of ice on the stoop marveling at how sometimes sweet tea is the best tea even if you usually drink tea straight no sugar with not even a lemon to counter the tannins the secret service said the incident posed no threat to the public and president biden was in delaware at the time of the crash a driver died after crashing into a security barrier near the white house on saturday night around prompting an investigation by the washington police department the secret service said in a statement and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte nc he was a section of the highway a crucial link between connecticut and new york city had closed on thursday when fuel from a burning tanker ignited an overpass a section of interstate in connecticut reopened on su and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte n c he was a section and  how sometimes sweet"

# 3500 characters = 
threethousandfivehundred = "the matter the move comes after a period of exclusive talks with the hollywood studio skydance lapsed on friday night rivers in southeast texas could be swollen for days or weeks forecasters said as multiple rounds of heavy rainfall continued on sunday southeast texas faced more heavy rainfall on sunday with forecasters warning that flash flooding could happen in houston after several rounds of storms in the past few days prompted evacuations and rescues in the area the south dakota governor defending her tale of shooting and killing her familys dog suggested that president bidens german shepherd commander had merited a similar fate gov kristi noem of south dakota already under fire for killing her familys monthold dog and boasting about it on sunday took aim at another familys pet commander president bidens biteprone german shepherd he won tournaments before moving into tv he explained the game that was going out in front of him in a very relaxed manner a former cbs producer said peter oosterhuis a british golfer who won tournaments around the world played in the ryder cup six times and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte n c he was a section of the highway a crucial link between connecticut and new york city had closed on thursday when fuel from a burning tanker ignited an overpass a section of interstate in connecticut reopened on sunday morning after a fiery accident last week damaged an overpass and shut down the highway a major artery along the east coast the pop superstar performed a final date on her global trek marking four decades of hits a set on copacabana beach before the largest live crowd of her career when madonna stepped out onto the mammoth stage constructed on rio de janeiros copacabana beach on saturday night in a gleaming halo headpiece and black kimono she was greeted by the largest live crowd of her fourdecade career readers discuss a guest essay that argued they are both also college roommates tech in school truths about russia water and politics to the with horseradishcheddar tuna melts and vegan tantanmen for the coming week good morning it was peak cherry blossoms last week where i stay the flowers almost ready to spring off their branches to blanket the curbs like drifts of snow there was a deep humidity in the air and it made me think of summer down south the way the atmosphere can seem almost liquid under the sun everything ripe everything slow i made sweet tea and drank it over an enormous amount of ice on the stoop marveling at how sometimes sweet tea is the best tea even if you usually drink tea straight no sugar with not even a lemon to counter the tannins the secret service said the incident posed no threat to the public and president biden was in delaware at the time of the crash a driver died after crashing into a security barrier near the white house on saturday night around prompting an investigation by the washington police department the secret service said in a statement and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte nc he was a section of the highway a crucial link between connecticut and new york city had closed on thursday when fuel from a burning tanker ignited an overpass a section of interstate in connecticut reopened on su and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte n c he was a section and  how sometimes sweet"

# 3000 characters
threethousand = "the matter the move comes after a period of excluive talks with the hollywood studio skydance lapsed on friday night rivers in southeast texas could be swollen for days or weeks forecasters said as multiple rounds of heavy rainfall continued on sunday southeast texas faced more heavy rainfall on sunday with forecasters warning that flash flooding could happen in houston after several rounds of storms in the past few days prompted evacuations and rescues in the area the south dakota governor defending her tale of shooting and killing her familys dog suggested that president bidens german shepherd commander had merited a similar fate gov kristi noem of south dakota already under fire for killing her familys monthold dog and boasting about it on sunday took aim at another familys pet commander president bidens biteprone german shepherd he won tournaments before moving into tv he explained the game that was going out in front of him in a very relaxed manner a former cbs producer said peter oosterhuis a british golfer who won tournaments around the world played in the ryder cup six times and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte n c he was a section of the highway a crucial link between connecticut and new york city had closed on thursday when fuel from a burning tanker ignited an overpass a section of interstate in connecticut reopened on sunday morning after a fiery accident last week damaged an overpass and shut down the highway a major artery along the east coast the pop superstar performed a final date on her global trek marking four decades of hits a set on copacabana beach before the largest live crowd of her career when madonna stepped out onto the mammoth stage constructed on rio de janeiros copacabana beach on saturday night in a gleaming halo headpiece and black kimono she was greeted by the largest live crowd of her fourdecade career readers discuss a guest essay that argued they are both also college roommates tech in school truths about russia water and politics to the with horseradishcheddar tuna melts and vegan tantanmen for the coming week good morning it was peak cherry blossoms last week where i stay the flowers almost ready to spring off their branches to blanket the curbs like drifts of snow there was a deep humidity in the air and it made me think of summer down south the way the atmosphere can seem almost liquid under the sun everything ripe everything slow i made sweet tea and drank it over an enormous amount of ice on the stoop marveling at how sometimes sweet tea is the best tea even if you usually drink tea straight no sugar with not even a lemon to counter the tannins the secret service said the incident posed no threat to the public and president biden was in delaware at the time of the crash a driver died after crashing into a security barrier near the white house on saturday night around prompting an investigation by the washington police department the secret"

# 2500 characters
twothousandfivehundred = "the matter the move comes after period of exclusive talks with the hollywood studdio skydance lapsed on friday night rivers in southeast texas could be swollen for days or weeks forecasters said as multiple rounds of heavy rainfall continued on sunday southeast texas faced more heavy rainfall on sunday with forecasters warning that flash flooding could happen in houston after several rounds of storms in the past few days prompted evacuations and rescues in the area the south dakota governor defending her tale of shooting and killing her familys dog suggested that president bidens german shepherd commander had merited a similar fate gov kristi noem of south dakota already under fire for killing her familys monthold dog and boasting about it on sunday took aim at another familys pet commander president bidens biteprone german shepherd he won tournaments before moving into tv he explained the game that was going out in front of him in a very relaxed manner a former cbs producer said peter oosterhuis a british golfer who won tournaments around the world played in the ryder cup six times and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte n c he was a section of the highway a crucial link between connecticut and new york city had closed on thursday when fuel from a burning tanker ignited an overpass a section of interstate in connecticut reopened on sunday morning after a fiery accident last week damaged an overpass and shut down the highway a major artery along the east coast the pop superstar performed a final date on her global trek marking four decades of hits a set on copacabana beach before the largest live crowd of her career when madonna stepped out onto the mammoth stage constructed on rio de janeiros copacabana beach on saturday night in a gleaming halo headpiece and black kimono she was greeted by the largest live crowd of her fourdecade career readers discuss a guest essay that argued they are both also college roommates tech in school truths about russia water and politics to the with horseradishcheddar tuna melts and vegan tantanmen for the coming week good morning it was peak cherry blossoms last week where i stay the flowers almost ready to spring off their branches to blanket the curbs like drifts of snow there was a deep humidity in the air and it made me think of summer down south the way the atmosphere can seem almost liquid under the sun everything ripe everything slow i made sweet tea and"

# 2000 characters
twothousand = "the matter the move comes after a period of exclusive talks with the hollywood studio skydance lapsed on a ffriday nights rivers in southeast texas could be swollen for days or weeks forecasters said as multiple rounds of heavy rainfall continued on sunday southeast texas faced more heavy rainfall on sunday with forecasters warning that flash flooding could happen in houston after several rounds of storms in the past few days prompted evacuations and rescues in the area the south dakota governor defending her tale of shooting and killing her familys dog suggested that president bidens german shepherd commander had merited a similar fate gov kristi noem of south dakota already under fire for killing her familys monthold dog and boasting about it on sunday took aim at another familys pet commander president bidens biteprone german shepherd he won tournaments before moving into tv he explained the game that was going out in front of him in a very relaxed manner a former cbs producer said peter oosterhuis a british golfer who won tournaments around the world played in the ryder cup six times and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte n c he was a section of the highway a crucial link between connecticut and new york city had closed on thursday when fuel from a burning tanker ignited an overpass a section of interstate in connecticut reopened on sunday morning after a fiery accident last week damaged an overpass and shut down the highway a major artery along the east coast the pop superstar performed a final date on her global trek marking four decades of hits a set on copacabana beach before the largest live crowd of her career when madonna stepped out onto the mammoth stage constructed on rio de janeiros copacabana beach on saturday night in a gleaming halo headpiece and black kimono she was greeted by the largest live crowd of her fourdecade career readers discuss a guest essay that argued they are both also"

# 1500 characters
onethousandfivehundred = "the matter the move comes after a period of exclusive talks with the holywood studio skydance lapsed on friday night rivers in southeast texas could be swollen for days or weeks forecasters said as multiple rounds of heavy rainfall continued on sunday southeast texas faced more heavy rainfall on sunday with forecasters warning that flash flooding could happen in houston after several rounds of storms in the past few days prompted evacuations and rescues in the area the south dakota governor defending her tale of shooting and killing her familys dog suggested that president bidens german shepherd commander had merited a similar fate gov kristi noem of south dakota already under fire for killing her familys monthold dog and boasting about it on sunday took aim at another familys pet commander president bidens biteprone german shepherd he won tournaments before moving into tv he explained the game that was going out in front of him in a very relaxed manner a former cbs producer said peter oosterhuis a british golfer who won tournaments around the world played in the ryder cup six times and later distinguished himself as a commentator for cbs and golf channel died on thursday in charlotte n c he was a section of the highway a crucial link between connecticut and new york city had closed on thursday when fuel from a burning tanker ignited an overpass a section of interstate in connecticut reopened on sunday morning after a fiery accident last week damaged an overpass and shut down"

# 1000 characters
onethousand = "the matter the move comes after a period of exclusive talks with the hollywood studio skydance lapsed on friday night rivers in southeast texas could be swollen for days or weeks forecasters said as multiple rounds of heavy rainfall continued on sunday southeast texas faced more heavy rainfall on sunday with forecasters warning that flash flooding could happen in houston after several rounds of storms in the past few days prompted evacuations and rescues in the area the south dakota governor defending her tale of shooting and killing her familys dog suggested that president bidens german shepherd commander had merited a similar fate gov kristi noem of south dakota already under fire for killing her familys monthold dog and boasting about it on sunday took aim at another familys pet commander president bidens biteprone german shepherd he won tournaments before moving into tv he explained the game that was going out in front of him in a very relaxed manner a former cbs producer said pete"

# 500 characters
fivehundred = "the matter the move comes after a period of exclusive talks with the holllywood studio skydance lapsed on friday night rivers in southeast texas could be swollen for days or weeks forecasters said as multiple rounds of heavy rainfall continued on sunday southeast texas faced more heavy rainfall on sunday with forecasters warning that flash flooding could happen in houston after several rounds of storms in the past few days prompted evacuations and rescues in the area the south dakota governor de"

# 100 characters 
onehundred = "the matter the move comes after a period of exclusive talks with the hollywood studio skydance laps "

# 20 characters
twenty = "the matter the move "


class TestNode(unittest.TestCase):
    def setUp(self):
        self.sample_string = "banana"
        self.root, _ = ukkonen(self.sample_string)
    

    ## Regular tests

    def test_suffix_tree_construction(self):
        # Test that the root node is not None
        self.assertIsNotNone(self.root)


    def test_is_substring(self):
        # Test cases where the substring exists in the tree
        self.assertTrue(is_substring(self.root, self.sample_string, "banana"))
        self.assertTrue(is_substring(self.root, self.sample_string, "ana"))
        self.assertTrue(is_substring(self.root, self.sample_string, "n"))
        self.assertTrue(is_substring(self.root, self.sample_string, "a"))
    
    
    def test_is_not_substring(self):
        # Test cases where the substring does not exist in the tree
        self.assertFalse(is_substring(self.root, self.sample_string, "b "))
        self.assertFalse(is_substring(self.root, self.sample_string, "anna"))
        self.assertFalse(is_substring(self.root, self.sample_string, "bag")) 
        self.assertFalse(is_substring(self.root, self.sample_string, " ")) 
    

    def measure_suffix_tree_construction(self, sample_string):
        # Measure the time it takes to build the suffix tree
        time_taken = timeit.timeit(lambda: ukkonen(sample_string), number=1)
        print(f"Construction time for {len(sample_string)} characters: {time_taken:.5f} seconds")
    
     ## Complexity tests:  1) implementation of suffixtree using Ukkonen's algorithm with strings of different length

    def test_construction_of_suffix_tree_20_characters(self):
        self.measure_suffix_tree_construction(twenty)

    def test_construction_of_suffix_tree_100_characters(self):
        self.measure_suffix_tree_construction(onehundred)

    def test_construction_of_suffix_tree_500_characters(self):
        self.measure_suffix_tree_construction(fivehundred)

    def test_construction_of_suffix_tree_1000_characters(self):
        self.measure_suffix_tree_construction(onethousand)

    def test_construction_of_suffix_tree_1500_characters(self):
        self.measure_suffix_tree_construction(onethousandfivehundred)

    def test_construction_of_suffix_tree_2000_characters(self):
        self.measure_suffix_tree_construction(twothousand)

    def test_construction_of_suffix_tree_2500_characters(self):
        self.measure_suffix_tree_construction(twothousandfivehundred)

    def test_construction_of_suffix_tree_3000_characters(self):
        self.measure_suffix_tree_construction(threethousand)

    def test_construction_of_suffix_tree_3500_characters(self):
        self.measure_suffix_tree_construction(threethousandfivehundred)

    def test_construction_of_suffix_tree_4000_characters(self):
        self.measure_suffix_tree_construction(fourthousand)
    
    
    ## Complexity tests:  2) space complexity of constructing a suffix tree

    def test_space_construction_of_suffix_tree_20_characters(self):
        tree, chars = ukkonen(twenty, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(twenty)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_100_characters(self):
        tree, chars = ukkonen(onehundred, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(onehundred)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_500_characters(self):
        tree, chars = ukkonen(fivehundred, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(fivehundred)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_1000_characters(self):
        tree, chars = ukkonen(onethousand, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(onethousand)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_1500_characters(self):
        tree, chars = ukkonen(onethousandfivehundred, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(onethousandfivehundred)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_2000_characters(self):
        tree, chars = ukkonen(twothousand, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(twothousand)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_2500_characters(self):
        tree, chars = ukkonen(twothousandfivehundred, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(twothousandfivehundred)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_3000_characters(self):
        tree, chars = ukkonen(threethousand, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(threethousand)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_3500_characters(self):
        tree, chars = ukkonen(threethousandfivehundred, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(threethousandfivehundred)} characters: ", node_count)

    def test_space_construction_of_suffix_tree_4000_characters(self):
        tree, chars = ukkonen(fourthousand, regularize=True)
        node_count = count_nodes_dfs(tree)
        print(f"Node count of {len(fourthousand)} characters: ", node_count)

    
    ## Complexity tests:  3) search for a substring in the suffix tree


    def test_search_for_substring1(self):
        start_time = time.time() 
        is_substring(self.root, self.sample_string, twenty)
        end_time = time.time()  
        print("Execution time:","{:.5f}".format(end_time - start_time))

    def test_search_for_substring2(self):
        start_time = time.time() 
        is_substring(self.root, self.sample_string, onehundred)
        end_time = time.time()  
        print("Execution time:","{:.5f}".format(end_time - start_time))
    
    def test_search_for_substring3(self):
        start_time = time.time() 
        is_substring(self.root, self.sample_string, "a")
        end_time = time.time()  
        print("Execution time:","{:.5f}".format(end_time - start_time))

 



   
if __name__ == "__main__":
    unittest.main()