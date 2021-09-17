#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int>g[],int v, int u){
    g[v].push_back(u);
    g[u].push_back(v);
}

void dfs_util(vector<int>v[],int s){
    // vector<int>visited()
}

int main()
{
    int v = 5;
    vector<int>g[5];//Or vector<vector<int>>v(5);


    return 0;
}