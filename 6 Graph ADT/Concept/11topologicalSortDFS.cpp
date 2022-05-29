/*
Topological Sort - In Directed Acyclic graph(DAC) every node from u to v where vertex u comes before v in ordering.
We are going to perform this with using a stack and whenever a dfs call for a node will be over we will push it into the stack.
*/
#include <bits/stdc++.h>

using namespace std;

void topoSort(vector<vector<int>> &g, vector<bool>&visited, stack<int> &st, int i)
{
    visited[i] = true;//Mark the current node as visited
    for (auto j : g[i])//Visit current node adjacent node
    {
        if (!visited[j])//If they are not visited make a dfs call
        {
            topoSort(g, visited, st, j);
        }
    }
    //Finally after all the current dfs call are over for the current node push current node in the stack
    st.push(i);
}

void dfs(vector<vector<int>> &g, int n)
{
    stack<int> st;//Define a stack
    vector<bool> visited(n, false);//Define a vector
    for (int i = 0; i < n; i++)
    {
        if (visited[i]!=true)//If not visited call topoSort
        {
            topoSort(g, visited, st, i);
        }
    }
    while (!st.empty())//At this point all dfs call's are done and we have a topological sort completed
    {
        cout << st.top() << " ";//Print out the popped element from the stack
        st.pop();
    }
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
    int n = g.size();
    dfs(g, n);//Call dfs
    return 0;
}