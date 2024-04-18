#python implementation of stack

def stack_push(stack, item):
    stack.append(item)

def stack_pop(stack):
    return stack.pop()

def stack_is_empty(stack):
    return(len(stack) == 0)

class Student:
   def __init__(self, name, esc190mark):
       self.name = name
       self.esc190mark = esc190mark
   def print(self):
       print("Name:", self.name, "Mark: ", self.esc190mark)

s = Student("Jack", 98)  # class __init__ . The first argument to init is the object being created
print(s.name)
s.print() # same as Student.print(s)


if __name__ == '__main__':
    stack  = []
    stack_push(stack, 1)
    stack_push(stack, 2)
    stack_push(stack, 3)
    print(stack)
    print(stack_pop(stack))

    