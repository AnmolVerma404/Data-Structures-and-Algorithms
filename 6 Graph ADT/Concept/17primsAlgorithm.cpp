/*
Prims Algorithm is use to find MST of a graph, MST have been discussed in it's file and Prims Algorithm is one of the algorithm by which we can find MST.
In prims algorithm we start with a node eg. 0 and we find the connected node to 0 which have the smallest weight eg. 1 and mark it true in the mstSet and by that I mean it's a part of MST, also mark the next node parent as 0 and set the key to the weight b/w 0 and the next smallest node.
Now visit next node i.e. 1 and find the smallest unvisited node of both 0 and 1 and add it in mstset and setParent and key for it and repeat this process.
Finally print parent vector
*/
#include <bits/stdc++.h>

using namespace std;

void prims(int n, vector<vector<pair<int, int>>> &g) // Time Complexity - O(n^2)
{
    vector<int> key(n, INT_MAX);   // This will store the weight of the node
    vector<int> parent(n, -1);     // Parent vector will store parent node information
    vector<bool> mstSet(n, false); // This will store wether a node is visited or not/ present in the MST
    key[0] = 0;                    // Starting node
    parent[0] = -1;                // Starting node dosen't have a parent node in MST as discussed in MST.

    for (int i = 0; i < n - 1; i++) // As MST have N-1 vertex we will run this loop for n-1 times
    {
        int mn = INT_MAX, u;
        for (int j = 0; j < n; j++) // This will get the minimum next node which can we used next in MST
        {
            if (mstSet[j] == false && key[j] < mn)
            {
                mn = key[j];
                u = j;
            }
        }
        mstSet[u] = true; // Set the smallest weighted to true in mst Set

        for (auto it : g[u]) // Find all the connected node to the uth node in the graph
        {
            int node = it.first;                         // Get the node of uth neighbor
            int wt = it.second;                          // Get the weight of the uth neighbor
            if (mstSet[node] == false && wt < key[node]) // If neighbor node is not already a part of MST and it's new weight is less than the key weight
            // Point to notice wt<key[node] is the condition in which key[node] may or may not be INT_MAX i.e. infinity. If the node have already been visited but not added in MST that this step will store the smallest wright for the neighbor node
            {
                // Update parent to next node and key weight to new node
                parent[node] = u;
                key[node] = wt;
            }
        }
    }
    // Finally print all the node that have connection
    for (int i = 1; i < n; i++)
    {
        cout << i << " " << parent[i] << "\n"; // Here i is the node and parent[i] is the node which is connected to the ith node.
    }
}

void primsOpt(int n, vector<vector<pair<int, int>>> &g)//Time complexity - O((N+E)log(N))
{
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mstSet(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{a,b} a is weight and b is node
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    for (int i = 0; i < n - 1; i++)
    {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;
        for (auto i : g[u])
        {
            int node = i.first;
            int wt = i.second;
            if (mstSet[node] == false && wt < key[node])
            {
                parent[node] = u;
                key[node] = wt;
                pq.push({key[node], node});
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
    vector<vector<pair<int, int>>> g = {// Undirected Graph with weight as pair - {a,b} where a is the node and b is the weight
                                        {{1, 2}, {3, 6}},
                                        {{0, 2}, {3, 8}, {4, 5}, {2, 3}},
                                        {{1, 3}, {4, 7}},
                                        {{0, 6}, {1, 8}},
                                        {{1, 5}, {2, 7}}};
    int n = g.size();
    prims(n, g);
    cout << '\n';
    primsOpt(n, g);
    return 0;
}