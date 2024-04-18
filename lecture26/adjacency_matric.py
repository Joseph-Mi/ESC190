import numpy as np
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
    for airport in [yyz, yvr, yul, whitehorse]:
        airport_dict[airport.value] = airport

    return airport_dict

def convert_to_adj_matrix(airports):
    adj_matrix = np.zeros(len(airports), len(airports))
    airport_callsigns = sorted(list(airports.keys()))
    airport_callsigns_index = {}
    for i, airport_callsigns in enumerate(airport_callsigns):
        airport_callsigns_index[airport_callsigns] = i

    for airport_callsigns, airport in airports.items():
        for neighbours in airport.neighbours:
            adj_matrix[airport_callsigns_index[airport_callsigns], airport_callsigns_index]
            adj_matrix[airport_callsigns_index[airport_callsigns], airport_callsigns_index[airport_callsigns]]
    
    return adj_matrix, airport_callsigns_index

if __name__ == '__main__':
    airports = make_airport_graph()
    print("Toronto(yyz) is connected to Montreal(yul)", are_airports_linked(airports, "YYZ", "YUL"))