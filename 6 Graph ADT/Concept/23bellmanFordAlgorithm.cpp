/*

*/
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int u;
    int v;
    int wt;
    node(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(vector<node> &g, int n)
{
    int inf = 10000000;
    vector<int> dist(n, inf);//Set the dist list
    dist[0] = 0;//Set the source dist to 0
    for (int i = 1; i < n; i++)//Iterate through n node
    {
        for (auto it : g)//For every iteration iterate in graph also
        {
            if (dist[it.u] + it.wt < dist[it.v])//Update dist
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    int fl = 0;
    for (auto it : g)//As for n node n iteration are enough for getting the shortest path, if we do another iteration and if we again get even shorter weight, we can say our graph include negative cycle
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }
    if (!fl)//If node print all the distance
    {
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }
    }
}

int main()
{
    int n = 6;
    vector<node> g;
    g.push_back(node(3, 2, 6));
    g.push_back(node(5, 3, 1));
    g.push_back(node(0, 1, 5));
    g.push_back(node(1, 5, -3));
    g.push_back(node(1, 2, -2));
    g.push_back(node(3, 4, -2));
    g.push_back(node(2, 4, 3));
    bellmanFord(g, n);

    return 0;
}