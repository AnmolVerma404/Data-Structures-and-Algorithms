/*
The problem here is to detect a edge in given graph which when removed will break the graph into 2 or more different non-connected graph.
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

void dfs(vector<vector<int>> &g, vector<bool> &visited, vector<int> &tin, vector<int> &low, int timer, int i, int parent)
{
    visited[i] = true;         // Set the ith node to true i.e. visited
    low[i] = tin[i] = timer++; // Set the lowest and the time of insertion of the ith node to timer as this node is just been visited, and increment the timer variable
    for (auto j : g[i])        // Get all the adjacent node to the ith node in the graph
    {
        if (j == parent) // This will stop a bridge edge from being update :: Also i is parent of j and parent variable is parent of ith node i.e. j->i->parent (where -> define a child to parent connection)
        /*
        Ex:  0 - 1 - 0
             p   i   j, here j == parent, this will happen as the given graph is undirected
        */
        {
            continue;
        }
        if (!visited[j]) // If the jth node is not yet visited
        {
            dfs(g, visited, tin, low, timer, j, i); // Call DFS
            low[i] = min(low[i], low[j]);           // After the DFS call return after visiting all it's adjacent and their adjacent node check if the low of the adjacent i.e. low[j] is smaller than low[i] -> that will mean our node is already visited from an different direction as it can't be the parent node due to the j == parent condition mentioned above
            if (low[j] > tin[i])
            /*
            If the time of insertion of the ith node is less that the jth node, that must meen the jth node still have been visited by node with smaller low time as it's parent is ith node.
            Therefor we can say that if we break i and j edge we will get the bridge.
            If an edge is the bridge let assume left side and right side of an bridge, the left side node will always have time less that all the right side node.
            */
            {
                cout << i << " " << j << "\n";
            }
        }
        else
        {
            // If already visited we can set the ith to the lowest time with comparing it with tin[j]
            low[i] = min(low[i], tin[j]);
        }
    }
}

void printBridges(vector<vector<int>> &g, int n)
{
    vector<bool> visited(n, false); // Define a visited array
    vector<int> tin(n, -1);         // Define a list which will store time of insertion of a node
    vector<int> low(n, -1);         // Define a list which will store the lowest time of insertion of a node
    int timer = 0;                  // This variable will set the time is both the above two list
    for (int i = 0; i < n; i++)     // Traverse to all n node
    {
        if (!visited[i]) // If the ith node is not visited
        {
            dfs(g, visited, tin, low, timer, i, -1);
        }
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
    printBridges(g, n);
    return 0;
}