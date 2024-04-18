class LL:
    def __init__(self):
        self.head = None

    def insert(self, loc, element):
        new_node = Node(element)  # data: element, next: None
        if loc == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            cur = self.head
            for i in range(loc-1):
                cur = cur.next
            new_node.next = cur.next
            cur.next = new_node
        
    def delete(self, loc):
        if loc == 0:
            self.head = self.head.next 
        else:
            cur = self.head
            for i in range(loc-1):
                cur = cur.next
            # cur is the node before the node that we want to delete
            cur.next = cur.next.next


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
