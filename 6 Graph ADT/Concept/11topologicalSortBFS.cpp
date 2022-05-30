#include <bits/stdc++.h>

using namespace std;

vector<int> topoBFS(vector<vector<int>> &g, int n)
{
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : g[i])
        {
            indegree[j]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto j : g[node])
        {
            indegree[j]--;
            if (indegree[j] == 0)
                q.push(j);
        }
    }
    return topo;
}


int main()
{
    vector<vector<int>> g = {
        // Directed Valid Graph
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2},
    };
    int n = g.size();
    vector<int> topo = topoBFS(g, n);
    for (auto i : topo)
        cout << i << " ";
    return 0;
}