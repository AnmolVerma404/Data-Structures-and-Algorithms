/*
Time Complexity - O(N+E)log(N) ~ Nlog(N) - As we will be visiting N vertices and E edges if we find out an shorter path.
Auxiliary Space Complexity - O(N) + O(N) - One is for the distance array and another for priority queue.
Point to notice - Here we are not taking any visited array as we are storing the data in distance and comparing the distance we are inserting in min heap.
*/
#include <bits/stdc++.h>

using namespace std;

void dijkstra(int n, vector<vector<pair<int, int>>> &g)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n, INT_MAX);
    pq.push({0, 0}); //{a,b} here a is the weight and b is the node
    distance[0] = 0;
    while (!pq.empty())
    {
        /*
        If you are confused in the variable naming you can take your own also, and the variable dist is not beeing used here as we can just get that information using the prev variable and the distance vector
        */
        int dist = pq.top().first;//This will store the current shortest distance of previous(prev) node
        int prev = pq.top().second;//previous node
        pq.pop();
        for (pair<int, int> i : g[prev])//all adjacent node to the prev node
        {
            int next = i.first;//the next node is stored in graph
            int nextDist = i.second;//the weight to the next node stored in the graph
            if (distance[prev] + nextDist < distance[next])//If the distance of the next node in the distance array is grater than the current popped element from priority queue and the next node distance then update the distance of the next node to the shortest distance
            {
                distance[next] = distance[prev] + nextDist;
                pq.push({distance[next], next});//Also push it into the pq to be further used and checked for more shorter paths
            }
        }
    }
    for (int i = 0; i < n; i++)//Finally iterate over the distance array and print them out!!!
    {
        cout << i << " " << distance[i] << "\n";
    }
}

int main()
{
    //{a,b} where a is the node and b is the weight
    vector<vector<pair<int, int>>> g = {
        {{1,0}},
        {{2, 2}, {4, 1}},
        {{1, 2}, {5, 5}, {3, 4}},
        {{2, 4}, {4, 3}, {5, 1}},
        {{1, 1}, {3, 3}},
        {{2, 5}, {3, 1}}};
    int n = g.size();
    dijkstra(n, g);
    return 0;
}