#include <bits/stdc++.h>

using namespace std;

void topoSort(vector<vector<int>> &g, vector<bool>&visited, stack<int> &st, int i)
{
    visited[i] = true;
    cout<<i<<" ";
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            topoSort(g, visited, st, j);
        }
    }
    st.push(i);
}

void dfs(vector<vector<int>> &g, int n)
{
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i]!=true)
        {
            topoSort(g, visited, st, i);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    vector<vector<int>> g = {// Directed Valid Graph
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
    dfs(g, n);
    return 0;
}