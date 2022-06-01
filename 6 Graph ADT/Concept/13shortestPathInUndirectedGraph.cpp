/*
TC - O(N+E) N - number of nodes, E - number of edges
Auxiliary SC - O(N) + O(N)
*/
#include <bits/stdc++.h>

using namespace std;

void shortestPath(vector<vector<int>> &g, int n)
{
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto i : g[top])
        {
            if (dist[i] > dist[top] + 1)
            {
                dist[i] = dist[top] + 1;
                q.push(i);
            }
        }
    }
    for (auto i : dist)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<vector<int>> g = {
        {1, 3},
        {0, 2, 3},
        {1, 6},
        {0, 4},
        {3, 5},
        {4, 6},
        {2, 5, 7, 8},
        {6, 8},
        {6, 7},
    };
    int n = g.size();
    shortestPath(g, n);

    return 0;
}