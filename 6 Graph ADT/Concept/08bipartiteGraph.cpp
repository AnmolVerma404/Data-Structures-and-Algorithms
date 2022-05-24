/*
In simple words bipartite mean divided into two parts.
This problem can be easily understand and solve by assuming that each node is a graph can be colored as blue(1) ,red(0), none(-1). If after traversal we found that a single node have different color then the graph is not a bipartite graph
Or we can say that a graph whose vertices can be divided into two disjoint and independent set U and V .Equivalently, a bipartite graph is a graph that does not contain any odd-length cycles.
*/
#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<vector<int>> g)
{
    int n = g.size();
    vector<int> color(n, -1); // visited color:- 0->red, 1->blue
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)//If the node is not visited then only it will have color none(-1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;//visited node put 1
            while (!q.empty())
            {
                int top = q.front();
                q.pop();
                for (auto j : g[top])
                {
                    if (color[j] == -1)//If the node is not visited then only it will have color none(-1)
                    {
                        q.push(j);//Add the connection to the queue
                        color[j] = 1 - color[top];//if 1->0 || 0->1 this is how every next node will have different color
                    }
                    else if (color[j] == color[top])//If the color of the next node and the current node are same i.e. two different color on the same node return false
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;//Finally after bfs traversal return true 
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
    cout << isBipartite(g);
    return 0;
}