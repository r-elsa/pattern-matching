class Node:
    def __init__(self, start, end):
        self.start = start
        self.letter =''
        self.end = end
        self.children = []


class SuffixTree:
    def __init__(self, input_string):
        self.input_string = input_string
        self.nodes = []

    
    def extend(self,index, letter):
        new_node = Node(index, '#')
        self.nodes.append(new_node)


    
    def loopoverstring(self, input_string):
        for i, letter in enumerate(input_string):
            self.extend(i, letter)
            
        



if __name__ == "__main__":
    input_string = 'abc'
    instance = SuffixTree(input_string)
    instance.loopoverstring(input_string)
    print([vars(i) for i in instance.nodes] )
    
