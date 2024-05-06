from dotenv import load_dotenv
import requests
import os                                                                                                                                                                                                          


def fetch_articles(api_key):
    """
    Fetches articles from the New York Times API.

    Args:
        api_key (str): The API key for accessing the New York Times API.

    Returns:
        dict or None: A dictionary containing the article data if successful, else None.
    """
    url = f"https://api.nytimes.com/svc/search/v2/articlesearch.json?api-key={api_key}"
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        return data
    else:
        print("Error:", response.status_code)
        return None

def process_json(articles):
    """
    Processes JSON data containing articles and returns a single string.

    Args:
        articles (dict): A dictionary containing JSON data of articles.

    Returns:
        str: A single string containing processed text from the articles.
    """
    single_string = ""
    json_of_articles = articles["response"]["docs"]
    for article in json_of_articles:
        abstract = article.get("abstract", "")
        lead_paragraph = article.get("lead_paragraph", "")
        abstract_lead_paragraph = abstract + " " + lead_paragraph
        word = ""
        for letter in abstract_lead_paragraph:
            if letter == ' ' or letter == '.' or letter == ',':
                if word:
                    single_string += word + ' '
                    word = ""
            elif letter.isalpha():
                letter_lowercase = letter.lower()
                word += letter_lowercase
    single_string = single_string.rstrip() + '$'
    return single_string

class Node:
    """
    Represents a node in the suffix tree.

    Attributes:
        parent: The parent node.
        edges: The edges connected to the node.
        suffix_link: The suffix link of the node.
        id: The ID of the node.
    """

    __num__ = -1

    def __init__(self, parent, edges, suffix_link=None):
        """
        Initializes a node in the suffix tree.

        Args:
            parent: The parent node.
            edges: The edges connected to the node.
            suffix_link: The suffix link of the node.
        """
        self.parent = parent
        self.edges = edges
        self.suffix_link = suffix_link
        Node.__num__ += 1
        self.id = Node.__num__

    def get_edges(self):
        """
        Getter method for edges.

        Returns:
            dict: A dictionary containing edges connected to the node.
        """
        return self.edges

    def set_edge(self, key, edge_value):
        """
        Setter method for an edge.

        Args:
            key: The key of the edge.
            edge_value: The value of the edge.
        """
        if self.edges is None:
            self.edges = {}
        self.edges[key] = edge_value

    def get_edge(self, key):
        """
        Getter method for a specific edge.

        Args:
            key: The key of the edge.

        Returns:
            tuple or None: A tuple containing the edge value if present, else None.
        """
        if key in self.edges:
            return self.get_edges()[key]
        else:
            return None

    def get_parent(self):
        """
        Getter method for parent.

        Returns:
            Node: The parent node.
        """
        return self.parent

    def set_parent(self, parent):
        """
        Setter method for parent.

        Args:
            parent: The parent node.
        """
        self.parent = parent

    def get_suffix_link(self):
        """
        Getter method for suffix link.

        Returns:
            Node: The suffix link of the node.
        """
        return self.suffix_link

    def set_suffix_link(self, node):
        """
        Setter method for suffix link.

        Args:
            node: The suffix link node.
        """
        self.suffix_link = node

    def get_id(self):
        """
        Getter method for node ID.

        Returns:
            int: The ID of the node.
        """
        return self.id

def ukkonen(chars, regularize=False):
    """
    Constructs the suffix tree using Ukkonen's algorithm.

    Args:
        chars (str): The input string.
        regularize (bool): Whether to regularize the input string.

    Returns:
        Node, str: The root node of the suffix tree and the processed string.
    """
    root = Node(None, None, None)
    current_node = root
    current_key = ''
    current_length = 0
    remainder = 0  
    index = 0
    while index < len(chars):
        ch = chars[index]
        if remainder == 0:
            if current_node.get_edges() is not None and ch in current_node.get_edges():
                current_key = ch
                current_length = 1
                remainder = 1
                anode, start, end, bnode = current_node.get_edge(current_key)
                if end == '#':
                    end = index
                if end - start + 1 == current_length:
                    current_node = current_node.get_edge(current_key)[3]
                    current_key = ''
                    current_length = 0
            else:
                aleaf = Node(None, None, None)
                aedge = (current_node, index, '#', aleaf)
                aleaf.set_parent((current_node, chars[index]))
                current_node.set_edge(chars[index], aedge)
        else:
            if current_key == '' and current_length == 0:  
                if ch in current_node.get_edges():
                    current_key = ch
                    current_length = 1
                    remainder += 1
                else:
                    remainder += 1
                    remainder, current_node, current_key, current_length = unfold(root, chars, index, remainder, current_node, current_key, current_length)
            else:  
                anode, start, end, bnode = current_node.get_edge(current_key)
                if end == '#':
                    end = index
                compare_position = start + current_length
                if chars[compare_position] != ch:
                    remainder += 1
                    remainder, current_node, current_key, current_length = unfold(root, chars, index, remainder, current_node, current_key, current_length)
                else:
                    if compare_position < end:  
                        current_length += 1
                        remainder += 1
                    else:  
                        remainder += 1
                        current_node = current_node.get_edge(current_key)[3]
                        if compare_position == end:
                            current_length = 0
                            current_key = ''
                        else:
                            current_length = 1
                            current_key = ch
        index += 1
        if index == len(chars) and remainder > 0:
            if regularize:
                chars = chars + '$'
    return root, chars

def unfold(root, chars, index, remainder, current_node, current_key, current_length):
    """
    Unfolds the suffix tree.

    Args:
        root: The root node of the suffix tree.
        chars (str): The input string.
        index (int): The current index.
        remainder (int): The remainder value.
        current_node: The current node.
        current_key (str): The current key.
        current_length (int): The current length.

    Returns:
        tuple: A tuple containing updated values.
    """
    previous_node = None
    while remainder > 0:
        remains = chars[index - remainder + 1:index + 1]
        current_length_remaining = len(remains) - 1 - current_length
        current_node, current_key, current_length, current_length_remaining = hop(index, current_node, current_key, current_length, remains, current_length_remaining)
        lost, current_node, current_key, current_length, current_length_remaining = step(chars, index, current_node, current_key, current_length, remains, current_length_remaining)
        if lost:
            if current_length == 1 and previous_node is not None and current_node is not root:
                previous_node.set_suffix_link(current_node)
            return remainder, current_node, current_key, current_length
        if current_length == 0:
            if remains[current_length_remaining] not in current_node.get_edges():
                aleaf = Node(None, None, None)
                aedge = (current_node, index, '#', aleaf)
                aleaf.set_parent((current_node, chars[index]))
                current_node.set_edge(chars[index], aedge)
        else:  
            anode, start, end, bnode = current_node.get_edge(current_key)
            if remains[current_length_remaining + current_length] != chars[start + current_length]:
                # 
                anode, start, end, bnode = current_node.get_edge(current_key)
                new_node = Node(None, None, None)
                half_edge1 = (current_node, start, start + current_length - 1, new_node)
                half_edge2 = (new_node, start + current_length, end, bnode)
                current_node.set_edge(current_key, half_edge1)
                new_node.set_parent((current_node, current_key))
                new_node.set_edge(chars[start + current_length], half_edge2)
                aleaf = Node(None, None, None)
                aedge = (new_node, index, '#', aleaf)
                aleaf.set_parent((new_node, chars[index]))
                new_node.set_edge(chars[index], aedge)
            else:
                return remainder, current_node, current_key, current_length
        if previous_node is not None and 'aleaf' in locals() and aleaf.get_parent()[0] is not root:
            previous_node.set_suffix_link(aleaf.get_parent()[0])
        if 'aleaf' in locals() and aleaf.get_parent()[0] is not root:
            previous_node = aleaf.get_parent()[0]
        if current_node == root and remainder > 1:
            current_key = remains[1]
            current_length -= 1
        if current_node.get_suffix_link() is not None:
            current_node = current_node.get_suffix_link()
        else:
            current_node = root
        remainder -= 1
    return remainder, current_node, current_key, current_length

def step(chars, index, current_node, current_key, current_length, remains, index_remainder):
    """
    Performs a step in the suffix tree construction.

    Args:
        chars (str): The input string.
        index (int): The current index.
        current_node: The current node.
        current_key (str): The current key.
        current_length (int): The current length.
        remains (str): The remaining characters.
        index_remainder (int): The remainder index.

    Returns:
        tuple: A tuple containing updated values.
    """
    remainder_label = remains[index_remainder:]
    if current_length > 0:
        anode, start, end, bnode = current_node.get_edge(current_key)
        if end == '#':
            end = index
        edge_label = chars[start:end + 1]
        if edge_label.startswith(remainder_label):
            current_length = len(remainder_label)
            current_key = remainder_label[0]
            return True, current_node, current_key, current_length, index_remainder
    else:
        if index_remainder < len(remains) and remains[index_remainder] in current_node.get_edges():
            anode, start, end, bnode = current_node.get_edge(remains[index_remainder])
            if end == '#':
                end = index
            edge_label = chars[start:end + 1]
            if edge_label.startswith(remainder_label):
                current_length = len(remainder_label)
                current_key = remainder_label[0]
                return True, current_node, current_key, current_length, index_remainder
    return False, current_node, current_key, current_length, index_remainder

def hop(index, current_node, current_key, current_length, remains, index_remainder):
    if current_length == 0 or current_key == '':
        return current_node, current_key, current_length, index_remainder
    anode, start, end, bnode = current_node.get_edge(current_key)
    if end == '#':
        end = index
    edge_length = end - start + 1
    while current_length > edge_length:
        current_node = current_node.get_edge(current_key)[3]
        index_remainder += edge_length
        current_key = remains[index_remainder]
        current_length -= edge_length
        anode, start, end, bnode = current_node.get_edge(current_key)
        if end == '#':
            end = index
        edge_length = end - start + 1
    if current_length == edge_length:
        current_node = current_node.get_edge(current_key)[3]
        current_key = ''
        current_length = 0
        index_remainder += edge_length
    return current_node, current_key, current_length, index_remainder

def is_substring(root, chars, substring):
    current_node = root
    index = 0
    while index < len(substring):
        ch = substring[index]
        if current_node.get_edges() is not None and ch in current_node.get_edges():
           
            anode, start, end, bnode = current_node.get_edge(ch)
            if end == '#':
                end = len(chars) - 1
        
            while start <= end and index < len(substring):
                if chars[start] != substring[index]:
                    return False
                start += 1
                index += 1
            if index == len(substring):
                if bnode is not None:  
                    return True
            current_node = bnode 
        else:
            return False  
    return False  



if __name__ == "__main__":
    
    load_dotenv()
    api_key = os.getenv("API_KEY")
    articles = fetch_articles(api_key)
    if articles:
        result = process_json(articles)
        print(result)
    

    tree, chars = ukkonen(result, regularize=True)

    while True:
        try:
            print(" ")
            user_input = input("Enter substring here: ")
            if user_input == '':
                break
            result = is_substring(tree, chars, user_input)
            print(f"'{user_input}' is a substring: {result}")
        except ValueError:
            break
