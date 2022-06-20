/*
It's similar to Bridge in Graph, the only difference here is we have to get the vertices which when remove break the graph into two parts.
Somer changes have to be made due to edge cases and few conditions
This code is majorly a modification in DFS traversal.
Undirected Graph
Time Complexity - O(N+E)
Space Complexity - O(N)
*/
#include <bits/stdc++.h>

using namespace std;

void buildGraph(vector<vector<int>> &g, int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(vector<vector<int>> &g, vector<bool> &visited, vector<int> &tin, vector<int> &low, vector<int> &aP, int timer, int i, int parent)
{
    visited[i] = true;
    tin[i] = low[i] = timer++;
    int child = 0;
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            if (j == parent)
                continue;
            dfs(g, visited, tin, low, aP, timer, j, i);
            low[i] = min(low[i], low[j]);
            if (low[j] >= tin[i] && parent != -1)
            {
                aP[i] = 1;
            }
            child++;
        }
        else
        {
            low[i] = min(low[i], tin[j]);
        }
    }
    if (parent == -1 && child > 1)
        aP[i] = 1;
}

void articulationPoint(vector<vector<int>> &g, int n)
{
    vector<bool> visited(n, false);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> aP(n, 0);
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(g, visited, tin, low, aP, timer, i, -1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (aP[i] == 1)
            cout << i << " ";
    }
}

int main()
{
    int n = 5;                // Number of vertices
    vector<vector<int>> g(n); // Define the graph
    buildGraph(g, 0, 1);
    buildGraph(g, 0, 2);
    buildGraph(g, 1, 2);
    buildGraph(g, 1, 3);
    buildGraph(g, 3, 4);
    articulationPoint(g, n);
    return 0;
}