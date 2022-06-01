/*
TC - O(N+E) N - number of nodes, E - number of edges
Auxiliary SC - O(N) + O(N)
There are many ways to find the shortest distence of all the vertices from 0th vertex when the distance between an edge is 1.
*/
#include <bits/stdc++.h>

using namespace std;

void shortestPath(vector<vector<int>> &g, int n)
{
    /*
    First of the way is to use BFS traversal and define an distance array of size equal to the number of vertex in the graph and set every element in the dist array to infinity i.e. maximum integer value.
    */
    vector<int> dist(n, INT_MAX);
    // Also define a queue to add the node whose shortest path have been found
    queue<int> q;
    // Push the first node in the queue and mark the dist as 0.
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int top = q.front(); // Remove the top most element from the queue
        q.pop();
        for (auto i : g[top]) // Find all the connecting nodes to the current node
        {
            if (dist[i] > dist[top] + 1) // If the distance of the next node is larger that the distance of the path and adding current weight.
            {
                dist[i] = dist[top] + 1; // Update the distance
                q.push(i);               // And push the node in the queue, so later it can be explored
            }
        }
    }
    for (int i = 0; i < n; i++) // Finally print all the distance
    {
        cout << i << " " << dist[i] << "\n";
    }
}

int main()
{
    vector<vector<int>> g = {
        {1, 3},
        {0, 2, 3},
        {1, 6},
        {0, 4},
        {3, 5},
        {4, 6},
        {2, 5, 7, 8},
        {6, 8},
        {6, 7},
    };
    int n = g.size();
    shortestPath(g, n);

    return 0;
}