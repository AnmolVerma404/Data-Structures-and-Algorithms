/*
It's similar to Bridge in Graph, the only difference here is we have to get the vertices which when remove break the graph into two parts.
Somer changes have to be made due to edge cases and few conditions
This code is majorly a modification in DFS traversal.
Undirected Graph
Time Complexity - O(N+E)
Space Complexity - O(N)
*/
#include <bits/stdc++.h>

using namespace std;

void buildGraph(vector<vector<int>> &g, int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(vector<vector<int>> &g, vector<bool> &visited, vector<int> &tin, vector<int> &low, vector<int> &aP, int timer, int i, int parent)
{
    // Similar to bridges everything is going on just extra child variable for an edge case which is -
    /*
    Child will get the number of child of a node and this will be helpful for the starting node i.e. 0 if 0 is connected with 1 and 2 and 3 but they are not connected that mean if we remove 0 graph will break in 3 different part, therefor we must check this edge case
    */
    visited[i] = true;
    tin[i] = low[i] = timer++;
    int child = 0;
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            if (j == parent)
                continue;
            dfs(g, visited, tin, low, aP, timer, j, i);
            low[i] = min(low[i], low[j]);
            if (low[j] >= tin[i] && parent != -1)
            // The condition here is different from bridges in graph i.e. low[j] >= tin[i] && low[j] > tin[i], as earlier there was an edge now it's just a node we are talking about and if low[j]>=tin[i] that mean no other node during jth node traversal got to it and set the low[j] value lower that tin[i] that mean it's an articulation point
            {
                aP[i] = 1;
            }
            child++; // Increment the child
        }
        else
        {
            low[i] = min(low[i], tin[j]); // If already visited compare low of i with tin of i
        }
    }
    if (parent == -1 && child > 1)
    // If parent is -1 i.e. starting node and child is greater that 1 i.e. child whould not be greater that one if dfs would be there as it will already be visited and child will not get increment. Eg: 0-1 0-2 1-2 :: dfs at 0 will increment child as 1 then 1 will visit 2 and return it. So 0's have only 1 child, but iff 1-2 edge was not present then 1's dfs call 2 would not be visited and 0 visit's 2 and increment the child therefor child > 1 will be true!!!
    {
        aP[i] = 1;
    }
}

void articulationPoint(vector<vector<int>> &g, int n)
{
    // Here everything is similar to bridge in graph, and just aP which store's all the articulation point. As there can be duplicates we will store it as an hash value
    vector<bool> visited(n, false);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> aP(n, 0);
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(g, visited, tin, low, aP, timer, i, -1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (aP[i] == 1)
            cout << i << " ";
    }
}

int main()
{
    int n = 5;                // Number of vertices
    vector<vector<int>> g(n); // Define the graph
    buildGraph(g, 0, 1);
    buildGraph(g, 0, 2);
    buildGraph(g, 1, 2);
    buildGraph(g, 1, 3);
    buildGraph(g, 3, 4);
    articulationPoint(g, n);
    return 0;
}