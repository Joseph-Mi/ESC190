class Node:
    def __init__(self, name):
        self.name = name
        self.neighbors = {}
        self.visited= False
        self.distance = float('inf')

    def add_neighbors(self, neighbor, weight):
        self.neighbors[neighbor] = weight

def extract_min_priority(queue):
    min_dist = float('inf')
    min_node = None
    for node in queue:
        if (node.distance < min_dist):
            min_dist = node.distance
            min_node = node
    queue.remove(min_node)
    return min_node

def dijkstras(start):
    start.distance = 0
    priority_queue = [start]

    while priority_queue:
        current = extract_min_priority(priority_queue)
        current.visited = True

        if current is None:
            break  # No more nodes to visit

        for neighbor, weight in current.neighbors.items():
            if neighbor.visited == False:
                new_distance = current.distance + weight
                if new_distance < neighbor.distance:
                    neighbor.distance = new_distance
                    priority_queue.append(neighbor)

def main():
    # Create nodes
    node_a = Node('A')
    node_b = Node('B')
    node_c = Node('C')
    node_d = Node('D')
    node_e = Node('E')

    # Add neighbors and weights
    node_a.add_neighbors(node_b, 10)
    node_a.add_neighbors(node_c, 15)
    node_b.add_neighbors(node_d, 12)
    node_b.add_neighbors(node_e, 15)
    node_c.add_neighbors(node_d, 10)
    node_c.add_neighbors(node_e, 10)
    node_d.add_neighbors(node_e, 2)

    # Perform Dijkstra's algorithm
    dijkstras(node_a)

    # Print the shortest distances
    print("Shortest distances from node A:")
    for node in [node_a, node_b, node_c, node_d, node_e]:
        print(f"To node {node.name}: {node.distance}")

if __name__ == "__main__":
    main()
