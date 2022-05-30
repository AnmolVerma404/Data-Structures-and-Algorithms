/*
DFS is already previously explained only logic behind Cycle checking in Directed Graph is present here!!!
In an Undirected graph, if we find a node that is already visited we can say there is a cycle, but that's not the case in Directed Graph
Eg -
Undirected    2 🔁  1    Directed  2 ➡️ 1
              🔃 🔃               ↘️  ⬆️
                0                     0
In case of undirected traversal start from 0 -> 1 -> 2 -> 0 and we detect a cycle
And in Directed traversal it start from 0 -> 1; 2->0 already visited() ; 2->1 already visited
In the directed example and the previous way cycle will be detected.
Therefor we have to take an additional boolean array which will also store whether a vertex is visited of not, but will go from the state of true to false when backtracking i.e. in the Directed traversal example
            0 1 2                         0 1 2
 visited -  0 0 0            dfsVisited - 0 0 0
            1 1 0                         1 1 0
            1 1 0                         1 0 0
            1 1 0                         0 0 0
            1 1 1                         0 0 1
            1 1 1                         0 0 1(2->0 already visited no need to call dfsCycle function)
            1 1 1                         0 0 1(2->1 already visited no need to call dfsCycle function)
            1 1 1                         0 0 0
            -----------------------------------
Here look at the dfsVisited bool array when 0 visits 1 both of them are true and there is no other node to be visited therefore we again change dfsVisited[node] = false similarly at 0 also, now 1 is already visited in the visited array therefor no need to traverse, we will mark node 2 true in both visited and dfsVisited, then we traverse and get 0 which is true in visited but false in dfsVisited therefor no cycle and the same case with 1 i.e. true in visited array but false in dfsVisited therefor no cycle detected.
And at the end due to backtracking dfsVisited of 2 will again be false.
*/
#include <bits/stdc++.h>

using namespace std;

bool dfsCycle(vector<vector<int>> &g, vector<bool> &visited, vector<bool> &dfsVisited, int i)
{
    visited[i] = true;
    dfsVisited[i] = true;
    for (auto j : g[i])
    {
        if (visited[j] == false)
        {
            if (dfsCycle(g, visited, dfsVisited, j))
            {
                return true;
            }
        }
        else if (dfsVisited[j] == true)
        {
            return true;
        }
    }
    dfsVisited[i] = false;
    return false;
}

bool dfs(vector<vector<int>> g, int n)
{
    vector<bool> visited(n, false);
    vector<bool> dfsVisited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            if (dfsCycle(g, visited, dfsVisited, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> g = {// Directed Valid Graph
                             {1},
                             {2},
                             {3},
                             {4, 6},
                             {5},
                             {},
                             {5},
                             {2, 8},
                             {9},
                             {7}};
    // vector<vector<int>> g = {{1},//Directed Valid Graph from example
    //                          {},
    //                          {0,1}};
    int n = g.size();
    cout << dfs(g, n); // Call DFS
    return 0;
}