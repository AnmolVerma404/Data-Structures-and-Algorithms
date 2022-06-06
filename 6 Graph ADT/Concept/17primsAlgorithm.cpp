#include <bits/stdc++.h>

using namespace std;

void prims(int n, vector<vector<pair<int, int>>> &g)
{
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mstSet(n, false);
    key[0] = 0;     // Starting node
    parent[0] = -1; // Starting node dosen't have a parent node in MST as discussed in MST.

    for (int i = 0; i < n - 1; i++)
    {
        int mn = INT_MAX, u;
        for (int j = 0; j < n; j++)
        {
            if (mstSet[j] == false && key[j] < mn)
            {
                mn = key[j];
                u = j;
            }
        }
        mstSet[u] = true;

        for (auto it : g[u])
        {
            int node = it.first;
            int wt = it.second;
            if (mstSet[node] == false && wt < key[node])
            {
                parent[node] = u;
                key[node] = wt;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << i << " " << parent[i] << "\n";
    }
}

int main()
{
    vector<vector<pair<int, int>>> g = {
        {{1, 2}, {3, 6}},
        {{0, 2}, {3, 8}, {4, 5}, {2, 3}},
        {{1, 3}, {4, 7}},
        {{0, 6}, {1, 8}},
        {{1, 5}, {2, 7}}};
    int n = g.size();
    prims(n, g);
    return 0;
}