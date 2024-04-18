'''
adjacency list: nodes can be in any order and will be determined by our interests
adjacency matrix:
    0   1   2   3   
0   inf 8   inf 6
1   8   inf 9   inf
2   inf 9   inf inf
3   6   inf inf inf

Operations:
• Is there an edge between 𝑣𝑖 and 𝑣𝑗?
    • Adjacency Matrix: O(1)
    • Adjacency List: O(d)
        • d: the maximum degree in the graph
• Find all vertices adjacent to 𝑣𝑖
    • Adjacency Matrix: O(|V|)
        • |V|: the number of vertices in the graph
    • Adjacency List: O(d)

degree: number of connections going out of one node    

a1(v) + a2(E) <= max(O([V] + [E]))

'''
class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = []

def make_airport_graph():
    yyz = Node("YYZ")
    yvr = Node("YVR")
    yul = Node("YUL")
    whitehorse = Node("Whitehorse")

    yyz.neighbours = [yvr, yul]
    yvr.neighbours = [yyz, yul, whitehorse]
    yul.neighbours = [yyz, yvr]
    whitehorse.neighbours = [yvr]
