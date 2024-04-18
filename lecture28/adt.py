#priotity quwuw
#adt
#insert(value, priority)
#pop:  return the value with highest priority (lowest numerically), remove it from the PQ

# Insert("ESC195", 5)
# Insert("CIV102", 10)
# Insert("ESC190", 0)

# pop() // ESC190
# pop() // ESC195
# pop() // ESC102

# {("ESC190", 0), ("ESC195", 5), ("CIV102", 10)}
# keep this list sorted by priority
# more conveneient {(0, "ESC190"), (5, "ESC195"), (10, "CIV102")}
#pop: remove the first element and return the value

class PriorityQueue:
    def __init__(self):
        self.queue = []

    def insert(self, value, priority):
        self.queue.append((priority, value))
        self.queue.sort()
        #could we do this in O(n)?
        #yes: go through self.queue, find the right place to insert new elem instead