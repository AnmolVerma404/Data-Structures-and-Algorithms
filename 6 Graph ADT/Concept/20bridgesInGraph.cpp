/*
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

void dfs(vector<vector<int>> &g, vector<bool> &visited, vector<int> &tin, vector<int> &low, int timer, int i, int parent)
{
    visited[i] = true;
    low[i] = tin[i] = timer++;
    for (auto j : g[i])
    {
        if (j == parent)
            continue;
        if (!visited[j])
        {
            dfs(g, visited, tin, low, timer, j, i);
            low[i] = min(low[i], low[j]);
            if (low[j] > tin[i])
            {
                cout << i << " " << j << "\n";
            }
        }
        else
        {
            low[i] = min(low[i], tin[j]);
        }
    }
}

void printBridges(vector<vector<int>> &g, int n)
{
    vector<bool> visited(n, false);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(g, visited, tin, low, timer, i, -1);
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> g(n);
    buildGraph(g, 0, 1);
    buildGraph(g, 0, 2);
    buildGraph(g, 1, 2);
    buildGraph(g, 1, 3);
    buildGraph(g, 3, 4);
    printBridges(g, n);
    return 0;
}