/*
To detect cycle in Directed Graph using BFS this technique is a kind of hack as we are using topological sort for it.
As in topological sort, it only works on DAG i.e. Directed Acyclic Graph, therefor we can use it and from the resultant list can check wether the size of it match the number of vertices in the graph and it should be exactly equal and it it is then we can say there is no cycle in the directed graph or else there is an cycle in the graph
*/
#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &g, int n)
{
    queue<int> q;
    vector<int> inOrder(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : g[i])
        {
            inOrder[j]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (inOrder[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        count++;
        for (auto i : g[top])
        {
            inOrder[i]--;
            if (inOrder[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if(count == n) return false;
    return true;
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
    cout<<bfs(g, n);
    return 0;
}