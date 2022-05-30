#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &g, int n)
{
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int top = q.front();
                q.pop();
                for (auto j : g[i])
                {
                    if (!visited[j])
                    {
                        q.push(j);
                        visited[j] = true;
                    }
                }
                st.push(top);
            }
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
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
    bfs(g, n);
    return 0;
}