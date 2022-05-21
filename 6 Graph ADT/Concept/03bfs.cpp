/*
BFS - Breadth-first Search for Graph
This is an algorithm for traversing a graph. It starts from a node and then explores all the vertices that are connected to the node. The queue data structure is used to store the node, if a node in a graph is not visited we add it into the queue and start exploring when its turn comes. As a graph may contain a cycle therefore we use a visited array of size = number of edges.
It stores the true or false values of whether a node is visited or not.
*/
#include <bits/stdc++.h>

using namespace std;

void Bfs(int size, vector<vector<int>> &g)
{
    //bfs vector will store the bfs traversal so that it can later be used or printed
    vector<int> bfs;
    //visited array as discussed will store whether the node is already visited or not
    vector<bool> visited(size + 1, false);
    //This for loop is necessary, as if the graph is disconnected some node may not be reachable but still are in graph
    for (int i = 0; i < size; i++)
    {
        if (visited[i] != true)//If the ith node is already visited dont push it again the queue
        {
            queue<int> q;//Define queue to store the graph (FIFO)
            q.push(i);
            visited[i] = true;//As the pushed element is visited therefor set the ith node to true
            while (!q.empty())//This while loop will make sure that all the conneccted nodes are explored
            {
                //pop the top most elemnent is the queue and push it in the bfs vector
                int top = q.front();
                q.pop();
                bfs.push_back(top);
                for (int j : g[top])//Explore the popped node
                {
                    if (visited[j] != true)//Again if its connection are already visited don't push it in the queue
                    {
                        //If the connection was not visited push it in the queue and mark it a visited node
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    //Finally output the traversal
    for (auto i : bfs)
    {
        cout << i << " ";
    }
}

int main()
{
    //Make sure to take a vaild graph
    vector<vector<int>> graph = {
        {1, 5},
        {0, 2, 5, 3},
        {1, 3},
        {1, 2, 4},
        {3, 5},
        {0, 1, 4}};
    int size = graph.size();
    //Time Complexity - O(V+E) where V is vertex and E is Edge
    Bfs(size, graph);
    /*
    Output - 0 1 5 2 3 4
    */
    return 0;
}