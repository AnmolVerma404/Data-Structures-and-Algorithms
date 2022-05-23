/*
To detect a cycle in a graph mean - If BFS/DFS traversal to a node which is already visited then it may be due to presence of a cycle in the graph.
To know whether a cycle is present we use a parent pointer which shows parent connection.
In Adjcancy list we can store the next connection and the parent connection in a pair
*/
#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> g)
{
    //Everything similar to BFS traversal
    int n = g.size();
    int visited[n];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<pair<int, int>> q;//Instead of int take pair<int,int> which will store the next connection and the parent connection for a node
            q.push({i, -1});//For the initital node set the parent to -1
            while (!q.empty())
            {
                int node = q.front().first;
                int par = q.front().second;
                visited[node] = true;
                q.pop();
                for (auto j : g[node])
                {
                    if (!visited[j])
                    {
                        q.push({j, node});
                        visited[j] = true;
                    }
                    else if (par != j)//If the curr node is visited and it's the visited node's parent is not same as the current node parent return true i.e. cycle is present
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> g = {
        {1, 5},
        {0, 2, 5, 3},
        {1, 3},
        {1, 2, 4},
        {3, 5},
        {0, 1, 4}};
    cout << bfs(g);
    return 0;
}