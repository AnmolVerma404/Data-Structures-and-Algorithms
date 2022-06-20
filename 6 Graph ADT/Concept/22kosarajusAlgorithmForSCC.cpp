/*
This is Kosarajus Algorithm For Strongly Connected Components
*/
#include <bits/stdc++.h>

using namespace std;

void topoDFS(vector<vector<int>> &g, vector<bool> &visited, stack<int> &st, int i)
{
    visited[i] = true;
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            topoDFS(g, visited, st, j);
        }
    }
    st.push(i);
}

void dfs(vector<vector<int>> &g, vector<bool> &visited, int i)
{
    visited[i] = true;
    cout << i << " ";
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            dfs(g, visited, j);
        }
    }
}

stack<int> topoSort(vector<vector<int>> &g, int n)
{
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoDFS(g, visited, st, i);
        }
    }
    return st;
}

vector<vector<int>> tG(vector<vector<int>> &g, int n)
{
    vector<vector<int>> t(n);
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            t[g[i][j]].push_back(i);
        }
    }
    return t;
}

void Kosarajus(vector<vector<int>> &g, int n)
{
    stack<int> st = topoSort(g, n);
    vector<vector<int>> transposeGraph = tG(g, n);
    vector<bool> visited(n, false);
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            cout << "SCC: ";
            dfs(transposeGraph, visited, node);
            cout << "\n";
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> g(n);
    g[0].push_back(1);
    g[1].push_back(2);
    g[2].push_back(0);
    g[1].push_back(3);
    g[3].push_back(4);

    Kosarajus(g, n);

    return 0;
}