#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> g, int v, int u)
{
    g[v].push_back(u);
    g[u].push_back(v);
}

void dfs_util(vector<vector<int>> g, int v, vector<bool> visited)
{
    visited[v] = true;
    cout << v << " ";
    for (auto itr = g[v].begin(); itr != g[v].end(); itr++)
    {
        if (visited[*itr] == false)
        {
            dfs_util(g, *itr, visited);
        }
    }
}

void dfs(vector<vector<int>> g, int v)
{
    vector<bool> visited(v, false); //This will initilize 0 to v to false
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfs_util(g, i, visited);
        }
    }
}

int main()
{
    int v = 4;
    vector<vector<int>> g(v); //Or vector<vector<int>>v(5);
    // addEdge(g,0,1);
    // addEdge(g,0,2);
    // addEdge(g,0,3);
    // addEdge(g,1,2);
    // addEdge(g,2,3);
    // addEdge(g,3,4);
    // addEdge(g,4,5);
    // addEdge(g,5,0);

    // addEdge(g,0, 1);
    // addEdge(g,0, 2);
    // addEdge(g,0, 3);
    // addEdge(g,1, 2);
    // addEdge(g,2, 4);
    // addEdge(g,3, 3);
    // addEdge(g,4, 4);

    addEdge(g,0, 1);
    addEdge(g,0, 2);
    addEdge(g,1, 2);
    addEdge(g,2, 0);
    addEdge(g,2, 3);
    addEdge(g,3, 3);
    cout << "The DFS of the Graph is :\n";
    dfs(g,v);
    return 0;
}