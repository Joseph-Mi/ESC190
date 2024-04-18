#want to make a queue class
#queue: first in, first out
import queue

q = [7, 5, 6]

#enqueue(10) = [10, 7, 5, 6]
#dequeue(6) -> [10, 7, 5]

#enqueue: add an object to the queue
#dequeue: remoce the first object in line from the queue

class Queue:
    def __init__(self):
        self.q = []

    def enqueue(self, elem):
        self.q.insert(0, elem) #O(n), when n is len(self.q)

    def dequeue(self):
        return self.q.pop() #O(1) as it only pops from back
    
    def __repr__(self):
        return f"Queue: LAST IN -> {self.q} <- FIRST IN"
    
#idea 0 fr enqueue ising append, O(1) for dequeue at pop(0)
    
#idea 1 doe O(1) and dequeue:
    #linked lists:
    # A -> B -> C -> D  (needs to be doubly linked so that D has a link to C)
    # to enqueue, add to the end (O(1) if you need to keep track of the node at the end currently)
    # to dequeue, remoce the first node(O(1) if you keep track of the head node currently)

#idea 2 for O(1) (almost) enqueue and dequeue
    # Use a circular array
    # [ ,   ,   ,   ,F, G, H, X, ]
    # keep track of the last and first index
    # to enqueue Y at the end, wrap around
    # [Y,   ,   ,   ,   F, G, H, X, ]

q1 = queue.Queue()
q1.enqueue(10)
q1.enqueue(20)
q1.dequeue()
q1.enqueue(5)
print(q1) #[5, 20]
