#include <bits/stdc++.h>

using namespace std;

/*
This is similar to BFS in BT but the only difference if we should not re-travell a same node or make a cycle
To avoiding that we can use a boolean array
*/

class Graph
{
    int v;
    list<int> *adj;

public:
    //v is the number of vertices in the graph
    Graph(int v);
    //v is the vertices and w is the element connected to that vertices
    void addEdge(int v, int w);
    //s is the sourse in the graph from where we want to BFS
    void bfs(int s);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::bfs(int s)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    list<int> queue;
    queue.push_back(s);
    visited[s] = true;

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (auto itr = adj[s].begin(); itr != adj[s].end(); itr++)
        {
            if (!visited[*itr])
            {
                queue.push_back(*itr);
                visited[*itr] = true;
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs(2);   

    return 0;
}