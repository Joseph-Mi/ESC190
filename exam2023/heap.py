class MyHeap:
    def __init__(self):
        self.heap = []

    def push(self, val):
        self.heap.append(val)
        self.heap_up(len(self.heap) - 1)

    def pop(self):
        if len(self.heap) == 0:
            raise IndexError("Can't pop from an empty heap")
        
        if len(self.heap) == 1:
            return self.heap.pop()
        else:
            min_val = self.heap[0]
            self.heap[0] = self.heap.pop()
            self.heap_down(0)

        return min_val


    def heap_up(self, index):
        while index > 0:
            parent_index = int((index-1) / 2)
            if (self.heap[index] < self.heap[parent_index]):
                self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
                index = parent_index
            else:
                break


    def heap_down(self, index):
        while True:
            left_child_index = 2 * index + 1
            right_child_index = 2 * index + 2
            smallest = index
    
            if left_child_index < len(self.heap) and self.heap[left_child_index] < self.heap[smallest]:
                smallest = left_child_index

            if right_child_index < len(self.heap) and self.heap[right_child_index] < self.heap[smallest]:
                smallest = right_child_index

            if smallest != index: 
                self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
                index = smallest

            else:
                break




'''
def _heapify_up(self, index):
        while index > 0:
            parent_index = (index - 1) // 2
            if self.heap[index] < self.heap[parent_index]:
                self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
                index = parent_index
            else:
                break

    def _heapify_down(self, index):
        while True:
            left_child_index = 2 * index + 1
            right_child_index = 2 * index + 2
            smallest = index

            if left_child_index < len(self.heap) and self.heap[left_child_index] < self.heap[smallest]:
                smallest = left_child_index
            if right_child_index < len(self.heap) and self.heap[right_child_index] < self.heap[smallest]:
                smallest = right_child_index

            if smallest != index:
                self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
                index = smallest
            else:
                break
'''