// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
#include <bits/stdc++.h>

using namespace std;
/*
Application :(https://www.geeksforgeeks.org/applications-of-depth-first-search/)
            - Detecting a cycle in a graph
            - Find the path form the sourse vertex to given vertex
            - Topological sorting, only possible if the given graph is a directed Acyclic graph
            - To test if a graph is bipartite (not that importang)
            - Finding strongly connected components i.e. if all the vertices in the graph is connected to every vertices
            - Maze problems
*/
class Graph
{
    int V;
    list<int> *adjList;
    void DFS_util(int v, bool visited[]);

public:
    Graph(int V)
    {
        this->V = V;
        adjList = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adjList[v].push_back(w);
    }

    void DFS();
};

void Graph::DFS_util(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    for (auto i = adjList[v].begin(); i != adjList[v].end(); i++)
    {
        if (!visited[*i])
        {
            DFS_util(*i, visited);
        }
    }
}

void Graph::DFS()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFS_util(i, visited);
        }
    }
}

int main()
{
    Graph g(5);
    /*
    The order will matter on the first node that is added i.e. 0->1 aftere that if the change the order nothing will change or opposite of BFS
        - The node 0 will give 1
        - 1 will give 2
        - 2 will give 4
        - 4 will give 4 but visited[4] = true therefore 4 will not be printed again 
        - 2 will say I don't have any more connection and same will be done by 1
        - 0 will say I have 3 left, so 0->3
        - 43will give 4 but visited[3] = true therefore 3 will not be printed again 
    */
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 3);
    g.addEdge(4, 4);

    // g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(0,3);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.addEdge(5,0);
    cout << "The DFS of the Graph is :\n";
    g.DFS();

    return 0;
}