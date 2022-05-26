/*
It's completely similar to DFS traversal and the logic of BFS cycle detection.
Same as in BFS we take the parent node and compare it to a current node if they are not the same and the current node is already visited we simply return true i.e. cycle present in the graph
*/
#include <bits/stdc++.h>

using namespace std;

bool cycleDetection(vector<vector<int>> &g, bool visited[], int i, int p)
{
    visited[i] = true;
    for (auto j : g[i])
    {
        if (!visited[j])
        {
            if (cycleDetection(g, visited, j, i))
            {
                return true;//If somewher cycle is present return true
            }
        }
        else if (j != p)//If parent is not equal to current node i.e. j return true
        {
            return true;
        }
    }
    return false;//else finally return false
}

bool dfs(vector<vector<int>> g)
{
    int n = g.size();
    bool visited[n];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (cycleDetection(g, visited, i, -1))
            {
                return true;//If cycle is detected return true
            }
        }
    }
    return false;//no cycle detected return false
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
    cout << dfs(g);
    return 0;
}