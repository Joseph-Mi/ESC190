from importLL import Node, LL

# def are_linked(node1, node2, LL):

def create_list(node):
    linked = LL()
    linked.insert(0, node)
    return linked

def add(linked, node):
    temp = linked.head
    
    # If the linked list is empty, insert the node at the beginning
    if temp is None:
        linked.insert(0, node)
        return
    
    # Traverse the linked list to find the last node
    i = 0
    while temp.next is not None:
        i += 1
        temp = temp.next
    
    # Insert the node at the end of the linked list
    linked.insert(i+1, node)
    
if __name__ == "__main__":
    a = Node("A")
    b = Node("B")
    c = Node("C")
    d = Node("D")

    linked_list = create_list(a)
    add(linked_list, b)

    # linked_list = LL()
    # linked_list.insert(0, a)
    # linked_list.insert(1, b)
    # linked_list.insert(2, c)
    # linked_list.insert(3, d)

    current_node = linked_list.head
    while current_node:
        print(current_node.data.data)
        current_node = current_node.next


"""
Node 
- neighbours -> linked list 

A - B 
    |
    C 
A.neighbours.add(B)
B.neighbours.add(A)


"""
    
    

