'''
while (there are non-visited nodes)
    Initialize data structure DS
    Add a non-visited vertex 𝑣𝑖 to DS
    Mark 𝑣𝑖 as visited
    while (DS is not empty)
        Remove 𝑣𝑗 from DS
        Mark 𝑣𝑗 as visited
        Add non-visited vertices adjacent to 𝑣𝑗 to DS
'''

'''
DataStruct(DS) = [] empty
for stronging nodes that i've seen but whose neighbours that I haven't visited yet

Keep:
1. taking out nodes from DS
2. adding neighbours to DS if they're not in DS and have not been visited


Example:
visited: 1
DS = [6, 3]

visited: 1, 6
DS = [3]

visited: 1, 6
DS = [3, 5]

visited: 1. 6, 3
DS = [5, 2, 4]

visited: 1, 6, 3, 5
DS = [2, 4]

visited: 1, 6, 3, 5, 2
DS = [4]





'''

while DS not empty:
    take out n from dis 
    visit n 
    add n's neighbours to DS
    if they weren't visited:
            cisit their neighbours
