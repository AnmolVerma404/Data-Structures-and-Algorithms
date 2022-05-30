/*
DFS - It stands for Depth-first search
In this type of search in a graph, we start with a node and visit its connected node in the list, then the visited node is the current node and we visit its connected node this happens until all the nodes in the graph are visited.
Similar to BFS a visited boolean array of a total number of vertices. If a node/connection is visited it is marked true.
The only difference b/w BFS and DFS is that BFS explore all the node connected to the current node and then move to the next node whereas DFS algorithm start with a root node and explore as far as possible.
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> storeDFS;//To store the DFS traversal

void search(vector<vector<int>> &v, bool visited[], int i, int n)
{
    visited[i] = true;//Mart current node as the visited node
    storeDFS.push_back(i);//Store it in the storeDFS vector so that it can be used later
    for (auto j : v[i])//Explore the current node's connections
    {
        if (visited[j] != true)//If current node is already visited don't explore it again
        {
            search(v, visited, j, n);//Currnet node is not visited therefor recursively call the next node unlike BFS, DFS explore in depth
        }
    }
}

void dfs(vector<vector<int>> &v, int n)
{
    bool visited[n];//Define a visited array of size n == vertices in graph to store info about if the currnode is visited or not
    memset(visited, false, sizeof(visited));//Set all value in the visited array to false
    for (int i = 0; i < n; i++)//Loop will run for every vertices(as some may not be connected)
    {
        if (visited[i] != true)//If the current node is already visited no need to exlore it again
        {
            search(v, visited, i, n);//Call the search function for all the node's from 0 to n-1
        }
    }
}

int main()
{
    // Make sure to take a vaild graph
    vector<vector<int>> g = {
        {1, 5},
        {0, 2, 5, 3},
        {1, 3},
        {1, 2, 4},
        {3, 5},
        {0, 1, 4}};
    int size = g.size();
    dfs(g, size);//Call the DFS function
    for (auto i : storeDFS)
    {
        cout << i << " ";
    }
    return 0;
}