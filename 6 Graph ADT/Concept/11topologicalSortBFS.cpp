/*
Topological Sort using DFS traversal algo can be done using an extra array containing all the indegree's of a node.
Also this algo is known as Kahn's Algorithm
Why need of an extra array?
As we know in BFS all the adjacent node are explored and in DFS we explore the first not visited node and continue to do it, by that in dfs we can keep track of one single path whereas in BFS we are exploring all the adjacent node so we need an extra infromation to get the information about how many node are connected to current node.
As we know inDegree give information about how many node are direction towards the current node, and in topological sort in a graph of edge from u to v, u should always come before v.
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> topoBFS(vector<vector<int>> &g, int n)
{
    queue<int> q;//Define a queue 
    vector<int> indegree(n, 0);//Defina a Indegree list 
    /*
    Logic behind indegree is all the node directing towards the curr node therefor we will increment the jth index of indegree of size = number of vertex in the graph.
    */
    for (int i = 0; i < n; i++)
    {
        for (auto j : g[i])
        {
            indegree[j]++;//Add all nodes indegree
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)//If indegree of an vertex in an graph is 0 add it into the queue
            q.push(i);
    }
    vector<int> topo;//This will store the result
    while (!q.empty())//Run until the queue is not empty
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);//Push the top of queue in the topo vector
        for (auto j : g[node])//find all the connected node to current node and decrement the indegree as the current node is indegree is 0 and it's been added to topo list
        {
            indegree[j]--;
            if (indegree[j] == 0)//If the jth element indegree is 0 add it into the queue for used later
                q.push(j);
        }
    }
    return topo;//Finally return the list
}


int main()
{
    vector<vector<int>> g = {
        // Directed Valid Graph
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2},
    };
    int n = g.size();
    vector<int> topo = topoBFS(g, n);//Call topo BFS and store the topological sort in a list
    for (auto i : topo)
        cout << i << " ";
    return 0;
}