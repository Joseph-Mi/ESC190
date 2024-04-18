#implement a linked list class in python
# use ut to implement a stack with O(1) push and pop
#everythin in python is an address

class LL:
    def __init__(self):
        self.head = None
    
    def insert(self, loc, element):
        new_node = Node(element) #data:element, next:None
        if loc == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            cur = self.head
            for i in range(loc):
                cur = cur.next
        new_node.next = cur.next #saying inserting.next is the same as the next in line
        cur.next = new_node #now the current.next is the intersting, so new_node has been correctly inserted\

#head is node
#head->next is node
    def delete(self, loc):
        if loc == 0:
            self.head = self.head.next
        else:
            cur = self.head
            for i in range(loc - 1):
                cur = cur.next
            #cur is now at loc-1, so cur.next is the one we want to delete
            cur.next = cur.next.next

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.stack = LL() #slef.stack is not a linkedlist with head ==None

    # push: insert at 0
    # pop: get 0th elem and then delete 0th elem
    
    def push(self, elem):
        self.stack.insert(0, elem)
    
    def pop(self, elem):
        cur_node = self.stack.head
        self.stack.delete(0)
        return cur_node.data