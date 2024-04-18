# import Queue

class CircularQueue:

    def __init__(self, capacity, begin):
        self.q = [None] * capacity
        self.capacity = capacity
        self.start = begin
        self.rear = begin
        self.size = 0

    def enqueue(self, elem):
        if self.size >= self.capacity:
            return f"Queue is FULL"

        # self.q.insert(0, elem) #O(n), when n is len(self.q)
        self.q[self.rear] = elem
        self.rear = (self.rear + 1) % self.capacity
        self.size += 1

    def dequeue(self):
        if self.size <= 0:
            return f"No more elements to dequeue"
        
        self.q[self.start] = None
        self.start = (self.start + 1) % self.capacity
        self.size -= 1
        return self.q
        # return self.q.pop() #O(1) as it only pops from back

    def __repr__(self):
        items = [str(self.q[(self.start + i) % self.capacity]) for i in range(self.size)]
        return f"Queue: {self.q}\t start -> {self.q[(self.start)%self.capacity]}, end -> {self.q[(self.rear-1)%self.capacity]}"
    
    def __lt__(self, other):
        for i in range(self.start, min(self.rear, other.rear)):
            if self.q[i] < other.q[i]:
                return True
            elif self.q[i] > other.q[i]:
                return False
        return self.rear < other.rear
        
# cd = CircularQueue(6,2)
# cd.enqueue(2)
# cd.enqueue(3)
# print(cd)
# cd.enqueue(7)
# cd.dequeue()
# print(cd)
# cd.enqueue(1)
# cd.enqueue(6)
# print(cd)
# cd.enqueue(81)
# cd.enqueue(21)
# print(cd)
# cd.dequeue()
# print(cd)
# cd.enqueue(5)
# print(cd)
# cd.enqueue(-3)
# print(cd)

queues = [
    CircularQueue(3, 0),
    CircularQueue(2, 0),
    CircularQueue(3, 0)
]

queues[0].enqueue(1)
queues[0].enqueue(18)
queues[0].enqueue(12)

queues[1].enqueue(1)
queues[1].enqueue(15)

queues[2].enqueue(2)
queues[2].enqueue(5)
queues[2].enqueue(6)

sorted_queues = sorted(queues)

# Print the sorted list
for idx, queue in enumerate(sorted_queues, start=1):
    print(f"Queue {idx}: {queue}")