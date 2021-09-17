#include <iostream>
#include <list>
using namespace std;
//graph class for DFS travesal
class Graph
{
    int V;                                // No. of vertices
    list<int> *adjList;                   // adjacency list
    void DFS_util(int v, bool visited[]); // A function used by DFS
public:
    // class Constructor
    Graph(int V)
    {
        this->V = V;
        adjList = new list<int>[V];
    }
    // function to add an edge to graph
    void addEdge(int v, int w)
    {
        adjList[v].push_back(w); // Add w to v’s list.
    }

    void DFS(); // DFS traversal function
};
void Graph::DFS_util(int v, bool visited[])
{
    // current node v is visited
    visited[v] = true;
    cout << v << " ";

    // recursively process all the adjacent vertices of the node
    list<int>::iterator i;
    for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
        if (!visited[*i])
            DFS_util(*i, visited);
}

// DFS traversal
void Graph::DFS()
{
    // initially none of the vertices are visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // explore the vertices one by one by recursively calling  DFS_util
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFS_util(i, visited);
}

int main()
{
    // Create a graph
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 3);
    g.addEdge(4, 4);

    cout << "Depth-first traversal for the given graph:" << endl;
    g.DFS();

    return 0;
}