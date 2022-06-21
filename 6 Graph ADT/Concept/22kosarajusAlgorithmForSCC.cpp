/*
This is Kosarajus Algorithm For Strongly Connected Components(SCC).
Strongly connected components - They are the set of vertices which can be reachable from every other vertex.
Eg -
        0 -> 1 -> 3
         ↖  ⬇   ⬇
           2    4
    In the above graph we can see from node 2 we can get to 0 and 1 and similarly from 0 and 1, therefor 0,1,and 2 are SCC.
    From 3 we can get to 4 but from 4 to 3 we can't traverse, therefor 3 is only SCC in it's set. And from node 4 we can't get to anynode so 4 is also a single SCC

As we need to find connected component we need some kind of relation by which we can order/sort the graph vertices, also we need transpose of the graph
This problem can be broken into 3 sub problems
Topo Sort
Transpose of Graph
DFS on transpose of traph by topo sort order
*/
#include <bits/stdc++.h>

using namespace std;

void topoDFS(vector<vector<int>> &g, vector<bool> &visited, stack<int> &st, int i)//Topo sort DFS
{
    visited[i] = true;
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            topoDFS(g, visited, st, j);
        }
    }
    st.push(i);
}

void dfs(vector<vector<int>> &g, vector<bool> &visited, int i)//Regular DFS
{
    visited[i] = true;
    cout << i << " ";
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            dfs(g, visited, j);
        }
    }
}

stack<int> topoSort(vector<vector<int>> &g, int n)//Topo sort
{
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoDFS(g, visited, st, i);
        }
    }
    return st;
}

vector<vector<int>> tG(vector<vector<int>> &g, int n)//Transpose a graph
{
    vector<vector<int>> t(n);//Define new graph
    //Iterate over graph 
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            t[g[i][j]].push_back(i);//Set the g[i][j] -> i from i -> g[i][j]
        }
    }
    return t;
}

void Kosarajus(vector<vector<int>> &g, int n)
{
    stack<int> st = topoSort(g, n);//Get topo sort
    vector<vector<int>> transposeGraph = tG(g, n);//Get new transpose graph
    vector<bool> visited(n, false);//Regular dfs
    while (!st.empty())
    {
        int node = st.top();//Get the top most element in the graph and apply DFS on it
        st.pop();
        if (!visited[node])
        {
            cout << "SCC: ";//Get the SCC
            dfs(transposeGraph, visited, node);
            cout << "\n";
        }
    }
}

int main()
{
    //Define valid graph
    int n = 5;
    vector<vector<int>> g(n);
    g[0].push_back(1);
    g[1].push_back(2);
    g[2].push_back(0);
    g[1].push_back(3);
    g[3].push_back(4);

    Kosarajus(g, n);

    return 0;
}