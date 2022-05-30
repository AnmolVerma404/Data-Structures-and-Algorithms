/*
Everything similar to BFS bipartite onlt difference is this is implimented using DFS.
*/
#include <bits/stdc++.h>

using namespace std;

bool bipartiteDFS(vector<vector<int>> &g, vector<int> &color, int i)
{
    //Below we have an additional conditional statement, it's for cheking if graph is already visited do not update it's color to 1 as it's will be used later for checking if color[j] == color[i]
    if(color[i] == -1) color[i] = 1;//Set the current node color to 1
    for (auto j : g[i])
    {
        if (color[j] == -1)//If the next node is not visited
        {
            color[j] = 1 - color[i];//Set the next node color to opposite of parent node i.e. 0 if 1 or 1 if 0
            if(!bipartiteDFS(g,color,j)){
                return false;
            }
        }
        else if (color[j] == color[i])//If next node is already visited check if the next node and the current node color are the same. If they are return false. Which implies the graph is not bipartite
        {
            return false;
        }
    }
    return true;//Finally return true
}

bool isBipartite(vector<vector<int>> &g, int n)
{
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteDFS(g, color, i))//Check if DFS is resulting true if not if's not a bipartite graph
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> g = {{1, 2, 3},
                             {0, 2},
                             {0, 1, 3},
                             {0, 2}};
    int n = g.size();
    cout << isBipartite(g, n);
    return 0;
}