/*
The Graph is a non linear data structure with consist of nodes and edges
nodes == vertices
edges == lines
Graph consist of finite vertices
Eg:
       5--------1       
       \      | \ \
       \     |  \    \->edges
       \    |   \       \
       \   |    \         2->vertics
       \  |     \       |   
       \ |      \     |
       \|       \ |
       4--------3 
            ^       
            \
            edges


*/
/*
A graph can be represented as a collection of adjacency list of adjacency matrix, in both of them can be again be represented as a direct or undirected graph
Directed graph - Is's a graph in which the edge is going only from one side i.e. is the above graph may be a D.G. if 5 -> 1 or 1 -> 5 not 5<->1
Undirected graph  - It is the visa versa of directed graph or 5<->1
*/
/*
Complete Graph - In this type of graph every vertices is connected to a distinct vertices or all connected to all
Sparse Graph - Not every vertices is connected to each vertices in simple words, a direct path between two vertices a and b may not be as simple as a ->b as they are not directly connected, path may be as complex as a->c->k->g->....->b
So there we find that there can be multiple path one of them is the shortest and due to that reason we have Dijastra, Floyed, Belman's Algorithm to find the shortest path
*/
/*
Graph as adjacency list -> It's like a 2D linked list i.e. their is a main linked list and from each node arises a new linked list.
                        ->In a list the sored values are like 1->5->4->3->2 as in the above example the 1 vertex is connected with 0,4,3 and 2.
Disadvantages -> It have no quicker way to search a vertices in graph
Eg - 
list - {
     1:2,3,4,5
     2:1,3
     3:1,4
     4:1,3,5
     5:1,4
}
Graph as adjacency matrix -> It's like a 2D matrix
                          -> If a vertex is connected the the G[r][c] == 1 and if it is not present/connected to some vectices it's G[r][c] == 0 
                                        1   2   3   4   5                         
                          ->Eg -- 1 ->  0   1   1   1   1   As One is not connected with it self and connected to every other vertices  
                          ->The adjacency matrix A of an undirected graph is its own transpose.
Advantage - It have quicker way to search
          - Only one bit memory is used in unweighted graph
Disadvantages - More Memory use
Eg:
Matrix  = [
     \1\    \2\    \3\    \4\    \5\
  \1\ 0      1      1      1      1   
  \2\ 1      1      1      0      0
  \3\ 1      1      0      1      0    
  \4\ 1      0      1      0      1
  \5\ 1      0      1      1      0
]
*/
/*
Weighted graph -> In this each edge consist of some weight it can we +ve or -ve 
*/