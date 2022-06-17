/*
Kruskals Algorithm is used to find the MST in a graph. We will be using disjoint set data structure in this algorithm.
In this algorithm we sort the vertices of graph with it's weights, and add it in using union in disjoint set, we can easily detect cycle if it's there by comparing their parents
Time Complexity - O(Nlog(N))
Space Complexity - O(N)
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

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n = 5, m = 6;
    vector<node> edges;
    edges.push_back(node(0, 1, 2));
    edges.push_back(node(0, 3, 6));
    edges.push_back(node(1, 0, 2));
    edges.push_back(node(1, 2, 3));
    edges.push_back(node(1, 3, 8));
    edges.push_back(node(1, 4, 5));
    edges.push_back(node(2, 1, 3));
    edges.push_back(node(2, 4, 7));
    edges.push_back(node(3, 0, 6));
    edges.push_back(node(3, 1, 8));
    edges.push_back(node(4, 1, 5));
    edges.push_back(node(4, 2, 7));
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    vector<int> rank(n, 0);
    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findParent(it.v, parent) != findParent(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << cost << "\n";
    for (auto it : mst)
        cout << it.first << "-" << it.second << "\n";

    return 0;
}