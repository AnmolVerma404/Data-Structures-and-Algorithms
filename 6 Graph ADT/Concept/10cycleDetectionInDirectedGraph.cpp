/*
DFS is already previously explained only logic behind Cycle checking in Directed Graph is present here!!!
*/
#include <bits/stdc++.h>

using namespace std;

bool dfsCycle(vector<vector<int>> &g, vector<bool> &visited, vector<bool> &dfsVisited, int i)
{
    visited[i] = true;
    dfsVisited[i] = true;
    for (auto j : g[i])
    {
        if (visited[j] == false)
        {
            if (dfsCycle(g, visited, dfsVisited, j))
            {
                return true;
            }
        }
        else if (dfsVisited[j] == true)
        {
            return true;
        }
    }
    dfsVisited[i] = false;
    return false;
}

bool dfs(vector<vector<int>> g, int n)
{
    vector<bool> visited(n, false);
    vector<bool> dfsVisited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            if (dfsCycle(g, visited, dfsVisited, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> g = {
        {1},
        {2},
        {3},
        {4, 6},
        {5},
        {},
        {5},
        {2, 8},
        {9},
        {7}};
    int n = g.size();
    cout << dfs(g, n);
    return 0;
}