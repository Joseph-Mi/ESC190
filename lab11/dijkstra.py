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
    visited = set([start])
    current = start
    while current != end:
        
        cur_dist = np.inf
        cur_v = None
        for node in visited:
            for con in node.connections:
                if con.node in visited:
                    continue
                if cur_dist > node.distance_from_start + con.weight:
                    cur_dist = node.distance_from_start + con.weight
                    cur_v = con.node

        if cur_v is None:
            print("no connections")
            exit()

        current = cur_v
        current.distance_from_start = cur_dist
        visited.add(current)
    return current.distance_from_start

def main():
    a = Node("A")
    b = Node("B")
    c = Node("C")
    d = Node("D")

    a.connections.append(Con(b, 5))
    # a.connections.append(Con(c, 10))
    # a.connections.append(Con(d, 2))
    d.connections.append(Con(c, 12))
    d.connections.append(Con(b, 6))
    b.connections.append(Con(c, 2))
    # c.connections.append(Con(d, 1))
    
    start = a
    end = d
    len = dijkstra(start, end)
    print(len)

if __name__ == "__main__":
    main()