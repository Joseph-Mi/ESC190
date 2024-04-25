class MyList:
    def __init__(self, ls):
        self.ls = ls
    
    def __lt__(self, other):
        return sum(self.ls) / len(self.ls) < sum(other.ls) / len(other.ls)
    
    def __repr__(self):
        return str(self.ls)

# Example usage
my_lists = [MyList([1, 3]), MyList([5, 4, 6]), MyList([20, -20])]
print(sorted(my_lists))