/*
Time Complexity - O(N+E)*2
Space Complexity - O(2N)
*/
#include <bits/stdc++.h>

using namespace std;

void topo(int i, stack<int> &st, vector<bool> &visited, vector<vector<pair<int, int>>> &g)
{
    visited[i] = true;
    for (pair<int, int> j : g[i])
    {
        if (!visited[j.first])
        {
            topo(j.first, st, visited, g);
        }
    }
    st.push(i);
}

void shortestPath(int n, vector<vector<pair<int, int>>> g)
{
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topo(i, st, visited, g);
        }
    }
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (dist[top] != INT_MAX)
        {
            for (auto i : g[top])
            {
                if (dist[top] + i.second < dist[i.first])
                {
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << i << " "
                 << "INF\n";
        else
            cout << i << " " << dist[i] << "\n";
    }
}

int main()
{
    //{a,b} -> a is the vertex and b is the weight
    vector<vector<pair<int, int>>> g = {
        {{1, 2}, {4, 1}},
        {{2, 3}},
        {{3, 6}},
        {},
        {{2, 2}, {5, 4}},
        {{3, 1}}};
    int n = g.size();
    shortestPath(n, g);
    return 0;
}