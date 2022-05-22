/*

*/
#include <bits/stdc++.h>

using namespace std;

void search(vector<vector<int>> &v, bool visited[], int i, int n)
{
    visited[i] = true;
    cout<<i<<" ";
    for (auto j : v[i])
    {
        if (visited[j] != true)
        {
            search(v, visited, j, n);
        }
    }
}

void dfs(vector<vector<int>> &v, int n)
{
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != true)
        {
            search(v, visited, i, n);
        }
    }
}

int main()
{
    // Make sure to take a vaild graph
    vector<vector<int>> g = {
        {1, 5},
        {0, 2, 5, 3},
        {1, 3},
        {1, 2, 4},
        {3, 5},
        {0, 1, 4}};
    int size = g.size();
    dfs(g, size);
    return 0;
}