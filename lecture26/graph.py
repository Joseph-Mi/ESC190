#adjacency matric: M[i, j] is 1 if node i and j are linked
# nodes can be airports "YYZ" (3), "YVR" (2), "YUL" (1), "whitehourse" (0)

# whitehourse [0], YUL [1], ...
#0
#1

#nodes_dict["YYZ"] = 3

#are YYZ and YUL linked: M(nodes_dict["YYZ"], nodes_dict["YUL"]) == 1
#average case access fir dicts is 0(1), but worse case is O(n), n = # of nodes
#but for lists it is O(n) bc we need to go through entire list to match the input
#class Node:
#   def __init__(self, value):
#       self.value = value
#       self.neighbors = set() #O(1 to look up and insert on average)
#graph = [Node("YYZ"), Node("YUL")]
#To amke look-up more efficient, turn graph into a dictionary (use node_dict)

class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = set() #d(1) to look up and insert on average
                                #O(n) in the worse case scenario

def are_nodes_linked(node1, node2):
    #node1 and node2 are linked inf there is an edge in between node1 node2
    #assume graph is undirected 
    return node2 in node1.neighbours # dont need to check that node1 is in node2.neighbors(since undirected)

#helper function
def get_node_by_str(nodes, node_str):
    return nodes.get(node_str, None)

    # for node in nodes:
    #     if node.value == node_str:
    #         return node
    # return None

def are_airports_linked(airports, airport1_str, airport2_str):
    airport1 = get_node_by_str(airports, airport1_str)
    airport2 = get_node_by_str(airports, airport2_str)
    if airport1 is None or airport2 is None:
        return False
    return are_nodes_linked(airport1, airport2)

def make_airport_graph():
    yyz = Node("YYZ")
    yvr = Node("YVR")
    yul = Node("YUL")
    whitehorse = Node("Whitehorse")

    yyz.neighbours = [yvr, yul]
    yvr.neighbours = [yyz, yul, whitehorse]
    yul.neighbours = [yyz, yvr]
    whitehorse.neighbours = [yvr]

    airport_dict = {}
    for airport in [yyz, yur, yul, whitehorse]:
        airport_dict[airport.value] = airport

    return airport_dict



if __name__ == '__main__':
    airports = make_airport_graph()
    print("Toronto(yyz) is connected to Montreal(yul)", are_airports_linked(airports, "YYZ", "YUL"))

    #complexity of are_airports_linked:
    ## need
    ## find airport1 (O(n), n is num of airports) (assuming airport names are limited to length e.g. 100 characters)
            #new: find airport1 (O(1)) on average
            #find airport2 (O(1)) 
    ## are the nodes linked? Look through every neighbor of airport1 O(d). d is degree of airport1
            #Look up in set O(1)  #made specifically to have that properties
    ## total runtime: 2*c1*n + c2*d <= 2*c1*n + c2*n // d <= n since we cant have more than n neighbours out of n airports
    #               <= 3 * max(c1, c2) * n

    #O(n) // drop constant

#usually, algorithms are the same time complexity, maybe different coefficient, but not complexity. This is a special case
#trading off space complexity for time complexity (dictionary takes up more space than linked lists) 

#in C you could thin of neighbors as an array of pointers
#complexity of finding out whether yvr has an edge to yyz
    #O(d)




