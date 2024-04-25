class person:
    def __init__(self, name):
        self.name = name
        self.friends = []
        self.visited = False
        
def add_neighbors(dict):
    people = {}

    for name, friend_list in dict.items():
        if name not in people:
            people[name] = person(name)
        person_instance = people[name]
        for friend_name in friend_list:
            if friend_name not in people:
                people[friend_name] = person(friend_name)
            friend_instance = people[friend_name]
            person_instance.friends.append(friend_instance)

    return people
    

def dfs(start):
    visited = set()
    stack = []
    count = 0
    greatest = 0
    stack.append((start, 1))

    while stack:
        someone, depth = stack.pop()
        greatest = max(depth, greatest)

        if someone not in visited:
            visited.add(someone)
            someone.visited = True
        
        for friend in someone.friends:
            if friend not in visited:
                visited.add(friend)
                stack.append((friend, depth + 1))
    return greatest

def absolute_greatest(people):
    result = 0
    temp = 0
    for key in people:
        temp = dfs(people[key])
        if temp > result: 
            result = temp
    return result
            
def main():
    friends = {
        "Carl Gauss": ["Isaac Newton", "Gottfried Leibniz", "Charles Babbage"],
        "Gottfried Leibniz": ["Carl Gauss"],
        "Isaac Newton": ["Carl Gauss", "Charles Babbage"],
        "Ada Lovelace": ["Charles Babbage", "Michael Faraday"],
        "Charles Babbage": ["Isaac Newton", "Carl Gauss", "Ada Lovelace"],
        "Michael Faraday": ["Ada Lovelace"]
    }

    people = add_neighbors(friends)
    longest_chain_length = absolute_greatest(people)

    print("Length of the longest friendship chain:", longest_chain_length)

if __name__ == "__main__":
    main()