import numpy as np

# class PriorityQueue:
#     def __init__(self):
#         self.queue = []

#     def insert(self, x, p):
#         self.queue.append((x, p))

#     def extract_min(self): # O n
#         index = 0
#         for i in range(1, len(self.queue)):
#             if self.queue[i][1] < self.queue[index][1]:
#                 index = i
            
#         return self.queue.pop(index)[0]
    
class PriorityQueue2: 
    def __init__(self):
        self.queue = []

    def insert(self, item, priority): #O nlog(n)
        # Find the correct position to insert using binary search
        self.queue.append((item, priority))
        self.queue = sorted(self.queue, key=lambda x: x[1])

    def extract_min(self): #O n
        if not self.queue:
            return None
        return self.queue.pop()[0]

pq = PriorityQueue2()
pq.insert('task1', 3)
pq.insert('task2', 1)
pq.insert('task3', 5)

print("Extracted:", pq.extract_min())  # Should print 'task2'
print("Extracted:", pq.extract_min())  # Should print 'task3'
print("Extracted:", pq.extract_min())  # Should print 'task1'
