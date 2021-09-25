#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> g[], int v, int u)
{
    g[v].emplace_back(u);
}

void topoSortDFS(int v, vector<int> g[], vector<bool> &visited, stack<int> &s)
{
    visited[v] = true;

    for (auto itr = g[v].begin(); itr != g[v].end(); itr++)
    {
        if (visited[v] == false)
        {
            topoSortDFS(*itr, g, visited, s);
        }
    }
    s.push(v);
}

void topologicalSort(vector<int> g[], int v)
{
    vector<bool> visited(v, false);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            topoSortDFS(i, g, visited, s);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int V = 5;
    vector<int> g[V];
    // addEdge(g, 5, 2);
    // addEdge(g, 5, 0);
    // addEdge(g, 4, 0);
    // addEdge(g, 4, 1);
    // addEdge(g, 2, 3);
    // addEdge(g, 3, 1);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    addEdge(g, 2, 4);
    topologicalSort(g, V);

    return 0;
}