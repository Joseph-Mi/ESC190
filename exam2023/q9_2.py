class Step:
    def __init__(self, index):
        self.index = index
        self.cost = float('inf')
        self.neighbors = []
        self.determined = False
        self.prev_step = None

    def add_neighbor(self, neighbor, weight):
        self.neighbors.append((neighbor, weight))

def extract_min_priority(queue):
    min_cost = float('inf')
    min_step = None
    for step in queue:
        if step.cost < min_cost:
            min_cost = step.cost
            min_step = step
    queue.remove(min_step)
    return min_step

def neighboring_3(node, index, end, graph):
    for i in range(1, 4):
        if index + i < end:
            neighbor_index = index + i
            neighbor = graph[neighbor_index]
            node.add_neighbor(neighbor, neighbor_index)

def create_graph(end):
    graph = [Step(i) for i in range(end)]
    for i in range(end):
        neighboring_3(graph[i], i, end, graph)
    return graph

def take_steps(start, end, graph):
    start.cost = 0
    priority_queue = [start]
    start.prev_step = None
    result = []

    while priority_queue:
        current = extract_min_priority(priority_queue)
        current.determined = True

        if current.index == end - 1:
            break  # Found the end node

        for neighbor, weight in current.neighbors:
            new_cost = current.cost + weight
            if new_cost < neighbor.cost:
                neighbor.cost = new_cost
                priority_queue.append(neighbor)
                neighbor.prev_step = current

    current_step = graph[end - 1]
    step_list = []
    while current_step is not None:
        result.append(current_step.index)
        current_step = current_step.prev_step

    print(result)

    for i in range(len(result)-1):
        step_list.append(result[len(result)-2-i]-result[len(result)-i-1])


    return end - 1, graph[end - 1].cost, step_list


def main():
    # Define the start and end indices
    start_index = 0
    end_index = 5

    # Create the graph
    graph = create_graph(end_index+1)

    # Find the minimum cost path
    end_node_index, min_cost, path = take_steps(graph[start_index], end_index+1, graph)
    print(f"Minimum cost to reach step {end_node_index}: {min_cost} in {path}")

if __name__ == "__main__":
    main()

