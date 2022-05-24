#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<vector<int>> g)
{
    int n = g.size();
    vector<int> color(n, -1); // visited color:- 0->red, 1->blue
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int top = q.front();
                q.pop();
                for (auto j : g[top])
                {
                    if (color[j] == -1)
                    {
                        q.push(j);
                        color[j] = 1 - color[top];
                    }
                    else if (color[j] == color[top])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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
    // vector<vector<int>> g = {
    //     {1},
    //     {2, 3},
    //     {1, 4},
    //     {1, 4}};
    cout << isBipartite(g);
    return 0;
}