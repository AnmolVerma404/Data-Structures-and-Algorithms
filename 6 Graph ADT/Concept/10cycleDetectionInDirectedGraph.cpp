#include <bits/stdc++.h>

using namespace std;

bool dfsCycle(vector<vector<int>> &g, vector<bool> &visited, int i,int p)
{
    visited[i] = true;
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            if (dfsCycle(g, visited, j,i))
            {
                return true;
            }
        }else if(j!=p){
            cout<<j<<" "<<p<<"\n";
            return true;
        }
    }
    return false;
}

bool cycle(vector<vector<int>> &g, int n)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfsCycle(g, visited, i,-1))
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
    cout << cycle(g, n);
    return 0;
}