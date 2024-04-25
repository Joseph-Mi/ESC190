import numpy as np

class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distance_from_start = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

def dijkstra(start, end):
    start.distance_from_start = 0
    visited = set()
    while end not in visited:
        cur_dist = np.inf
        cur_v = None
        for node in start.connections:
            if node.node in visited:
                continue
            if cur_dist > start.distance_from_start + node.weight:
                cur_dist = start.distance_from_start + node.weight
                cur_v = node.node

        if cur_v is None:
            print("No path exists")
            return np.inf

        cur_v.distance_from_start = cur_dist
        visited.add(start)
        start = cur_v
    
    return end.distance_from_start

# def dijkstra(start, end):
#     start.distance_from_start = 0
#     visited = set()
#     while start not in visited:
#         cur_dist = np.inf
#         cur_v = None
#         for node in start.connections:
#             if node.node in visited:
#                 continue
#             if cur_dist > start.distance_from_start + node.weight:
#                 cur_dist = start.distance_from_start + node.weight
#                 cur_v = node.node

#         if cur_v is None:
#             print("No path exists")
#             return np.inf

#         cur_v.distance_from_start = cur_dist
#         visited.add(start)
#         start = cur_v
    
#     return end.distance_from_start

# Example usage:
# node1 = Node(1)
# node2 = Node(2)
# node3 = Node(3)
# node1.connections.append(Con(node2, 5))
# node2.connections.append(Con(node3, 3))
# print(dijkstra(node1, node3))  # Output should be 8


def main():
    a = Node("A")
    b = Node("B")
    c = Node("C")
    d = Node("D")

    a.connections.append(Con(b, 5))
    a.connections.append(Con(c, 10))
    a.connections.append(Con(d, 2))
    d.connections.append(Con(c, 12))
    d.connections.append(Con(b, 6))
    b.connections.append(Con(c, 2))
    c.connections.append(Con(d, 1))
    
    start = a
    end = d
    length = dijkstra(start, end)
    print("The distance between A and D is:", length)

main()