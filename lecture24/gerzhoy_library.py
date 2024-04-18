'''
FILE I/O for binary data
want to write an image to a file
an image: a block on numbers
    we cna rasterize the image(describe every pixel, then to next rows)
rasterize: make into a ist or block of numbers
[125, 123, 200, 100, 153, ...]

Inefficient way of sorting an image: store he raster as text

when reading in: get rid of the [], split on the commas, and convert to numbers...

However, if I know that the numbers at most have three digits, 
I dont need to store the commas
If I know that the numbers are between 0 and 225,
Can more efficiently use space by storing as binary

Analogy:
Store as just 0s and is [0,1,0,0,0,1,1,0,1]
If i store 0's and 1's as text, need to use one byte per digit

But if I store only 0s and 1s, 
0s can be stored as "low voltage" and 1s as high "voltage"
Basic idea: store each num as efficiently as possible
dont store commas, by replying on the fact that each number will have a fixed number of digits

To write a block of memory to a file:
fwrite(block, sizeof(_UINT8_C), num_elements, FP)
-> write block of memeory, consistent of elemts of size sizeof(__UINT16_C) to the file pointed to by FP

To read a block of memory from a file:
fread(block, sizeof(_UINT8_C), num_elements, FP)

To read/write images, need meta-data:
width, height, (num of channels), 
channel (other possibility: just one intensity value, other: possibility: RGB + alpha(transparency level)

'''


'''
Graphs G = (V, E) consists of set of vertices(nodes) V and set of edges E
each edge would be a pain of vertices

Vertices are cities, edges are direct flights between cities
• Want to find the best route between cities
Vertices are classes, edges connect classes whose schedules overlap
• Want to find feasible schedules for a student
Vertices are objects in memory, edges connect objects that refer to each other
• Want to know when an object can be freed

for example implementation:
edges could be pointers of maybe a list of some sort 

Each edge has a weight associated with it (in analogy with cities and flights: some flights are worth more or they leave earlier etc)

Terminology:
Vertex 𝑣1 is adjacent to vertex 𝑣2 if an edge
connects 𝑣1 and 𝑣2
• There exists an edge 𝑒 = (𝑣1, 𝑣2) ∈ 𝐸
A path is a sequence of vertices in which each vertex is adjacent to the next one
• p = (𝑣1, … , 𝑣𝑛)s.t. 𝑣𝑖, 𝑣𝑖+1 ∈ 𝐸
• The length of the path is the number of edges in it
A cycle in a path is a sequence (𝑣1, … , 𝑣𝑛) s.t. 𝑣𝑖, 𝑣𝑖+1 ∈ 𝐸
and 𝑣𝑛, 𝑣1 ∈ 𝐸
A graph with no cycles is an acyclic graph
A DAG is a directed acyclic graph

EXAMPLE:
not a cyclic as you can only go back and forth on V3 and V4

A simple path is a path with no repetition of vertices
A simple cycle is a cycle with no repetition of vertices
Two vertices are connected is there is a path between them
A subset of vertices is a connected component of G if each pair of vertices in the subset are connected.
The degree of vertex v is the number of edges associated with v

'''



'''
                                        Is this electronic still functional
                                        Yes/                            No\
        Can the item be refurbished or repaired?                    Is the item suitable for disassembly and salvage?
            Yes/                            No\                         Yes/                    No\
Can the item be repaired with          Discard of Properly      Is the refurbished item       End of Process
minor fixes or component                                        suitable for resale?
replacements?                                                 Yes/                  No\                  
    Yes/            No\                                     Is there a market for   End of Process
Repair the item     Is the item suitable for                the refurbished item?
And proceed to      salvaging usable components?              Yes/              No\
Sell                Yes/                    No\             Sell the refurbished item.  End of Process
            Can salvaged components be          End of Process                 
            incorporated into new products 
            or projects?
              Yes/                    No\
Design and create new products        Can these salvaged components or materials be  
using salvaged components.            sold separately no manufacturers or ...?        
Market and sell the upcycled products.           Yes/                No\
                                Find producers who would be     Discard of materials and components properly
                                interested in purchasing the 
                                materials

'''                         
