class Node:
    def __init__(self, id):
        self.id = id
        self.connections = []
        self.visited = False

def BFS(start_node):
    visited = set()
    queue = []

    queue.append(start_node)

    while queue:
        node = queue.pop(0)
        if node not in visited:
            print(node.id)
            visited.add(node)
            node.visited = True

        for connection in node.connections:
            
            if connection not in visited:
                print(connection.id)
                visited.add(connection)
                queue.append(connection)

def DFS(start_node):
    visited = set()
    stack = []

    stack.append(start_node)

    while stack:
        node = stack.pop()
        if node not in visited:
            print(node.id)
            visited.add(node)
            node.visited = True

        for connection in node.connections:
            if connection not in visited:
                stack.append(connection)

    
def create_graph():
    # Create nodes
    nA = Node('A')
    nB = Node('B')
    nC = Node('C')
    nD = Node('D')
    nE = Node('E')
    nF = Node('F')
    nG = Node('G')

    # Define connections
    nA.connections = [nB, nC]
    nB.connections = [nD, nE]
    nC.connections = [nF, nG]

    return nA  # Return the start node

def main():
    start_node = create_graph()
    print("BFS Traversal:")
    BFS(start_node)
    print("\nDFS Traversal:")
    DFS(start_node)

if __name__ == "__main__":
    main()