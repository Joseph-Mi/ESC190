import numpy as np
from collections import defaultdict, deque

class Node:
    def __init__(self, id):
        self.id = id
        self.neighbours = []
        self.visited = False

def BFS(start_node):
    visited = set()
    queue = deque([start_node])
    visited.add(start_node)

    while queue:
        current_node = queue.popleft()
        print(current_node.id, end = "  ")
        visited.add(current_node)
        current_node.visited = True
        
        for neighbor in current_node.neighbours:
            if not neighbor.visited:
                queue.append(neighbor)
                visited.add(neighbor)
                neighbor.visited = True

def DFS(current_node, visited):
    visited.add(current_node)
    print(current_node.id, end="  ")
    
    for neighbor in current_node.neighbours:
        if neighbor not in visited:
            DFS(neighbor, visited)

if __name__ == '__main__':
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    node5 = Node(5)
    node6 = Node(6)

    # Add edges between nodes
    node1.neighbours.extend([node6, node3])
    node2.neighbours.extend([node3, node5])
    node3.neighbours.extend([node1, node2, node4, node5])
    node4.neighbours.extend([node3, node5])
    node5.neighbours.extend([node4, node3, node2, node6])
    node6.neighbours.extend([node5])

    # Perform BFS starting from node1
    print("BFS Traversal:")
    BFS(node1)

    visited = set()
    # DFS(node1, visited)

