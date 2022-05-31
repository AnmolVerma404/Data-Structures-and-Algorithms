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
    if(count == n) return true;
    return false;
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