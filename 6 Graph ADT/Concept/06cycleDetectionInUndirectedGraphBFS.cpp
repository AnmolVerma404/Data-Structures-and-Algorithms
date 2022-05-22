#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> g)
{
    int n = g.size();
    int visited[n];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1});
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
                    else if (par != j)
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
    vector<vector<int>> g = {{1},
                             {2},
                             {1}};
    cout << bfs(g);
    return 0;
}