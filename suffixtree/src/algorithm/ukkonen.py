class Node:
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.next = {}


class SuffixTree:
    def __init__(self, input_string):
        self.input_string = input_string
        self.nodes = []
        self.position = -1 
         ##  part of active point. 
        self.active_node= 0 # default : root
        self.active_edge = None ##  default: null
        self.active_length = 0 ##  dfault :0
        self.remainder = 0 ## an integer that shows the amount of suffixes we are waiting to insert.incremented at beginning of step & decremented at end of step for each suffix insertion
        self.starting_characters = dict()
    
    def addNode(self,start, letter):

        ## automatically appended 
        self.remainder +=1 # always incremented at the beginning of a step 
       

        ## insert new edg of does not exist
        if letter not in self.starting_characters:  ## constant time to look up if edge exists
            self.starting_characters[letter]= start
            new_node = Node(start, '#')
            self.nodes.append(new_node)


            self.active_node =0 # back at root
            self.active_edge =None 
            self.active_length = 0
            self.remainder =0


        
        
        else: # letter already exists
            ## remainder is not decremented because no successful insertion
            self.active_node =0 ## stay th same - Root :0 
            self.active_edge = next(x for x in self.nodes if x.start == self.starting_characters[letter])  ## the edge which starts with the letter that already exists 
            self.active_length+=1
        
        print("ROUND",start+2, "Active node:", self.active_node, "Active edge:", self.active_edge, "Active length:", self.active_length, "Remainder:", self.remainder)

  
            

    
    def loopoverstring(self, ):
        for i, letter in enumerate(self.input_string):
            self.addNode(i,letter)
            
        



if __name__ == "__main__":
    input_string = 'statistics'
    instance = SuffixTree(input_string)
    instance.input_string = input_string
    instance.loopoverstring()
    print([vars(i) for i in instance.nodes] )
    print(instance.starting_characters)
    
