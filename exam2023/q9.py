from collections import defaultdict

class Step:
    def __init__(self, index):
        self.index = index
        self.cost = float('inf')
        self.neighbors = []
        self.determined = False

    def step_neighbors(self, index):
        n = len(index)
        steps = [Step(i) for i in range(n)]

        for i in range(n):
            for j in range(1, 4):
                if i + j < n:
                    steps[i].neighbors.append((steps[i+j], index[i+j]))
    
        return steps

def extract_min(q):
    min_step = None
    min_cost = float('inf')

    for step in q:
        if step.cost < min_cost and not step.determined:
            min_cost = step.cost
            min_step = step

    return min_step

def min_cost(index):
    n = len(index)
    steps = Step(0).step_neighbors(index)
    zero = steps[0]
    zero.cost = 0

    priority_queue = [zero]

    while priority_queue:
        current = extract_min(priority_queue)
        if current is None:
            break  # Exit loop if priority queue is empty
        current.determined = True

        for neighbor, step_cost in current.neighbors:
            new_cost = current.cost + step_cost
            if new_cost < neighbor.cost:
                neighbor.cost = new_cost
                priority_queue.append(neighbor)

    # Trace back the minimum cost path
    result = []
    current_step = steps[-1]
    while current_step.index != 0:
        if not current_step.neighbors:
            result.append(index[current_step.index])
            current_step = steps[current_step.index - 1]
        else:
            min_neighbor = min(current_step.neighbors, key=lambda x: x[0].cost)
            result.append(min_neighbor[1])
            current_step = min_neighbor[0]

    result.append(index[-1])  # Add the last step to the result
    return result[::-1]  # Reverse the result to get the correct order


def main():
    # Generate random costs for each step
    n = 10
    cost = [i for i in range(n)]
    
    print("Cost of each step:", cost)

    # Find the least-cost plan
    least_cost_plan = min_cost(cost)
    print("Least-cost plan:", least_cost_plan)

if __name__ == "__main__":
    main()
