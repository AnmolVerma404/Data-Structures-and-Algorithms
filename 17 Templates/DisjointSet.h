#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    /*
     * @param n number of nodes in the graph
     */
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    /*
     * @param node find the ultimate parent for the node
     * @brief Time Complexity - O(1)
     * @return ultimate parent of node
     */
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    /*
     * @param u The first node
     * @param v The second node
     * @brief Time Complexity - O(1), u and v are combined in the union set
     * @return void
     */
    void unionByRank(int u, int v)
    {
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);
        if (ultimateParentU == ultimateParentV)
            return;

        if (rank[ultimateParentU] < rank[ultimateParentV])
        {
            parent[ultimateParentU] = ultimateParentV;
        }
        else if (rank[ultimateParentV] < rank[ultimateParentU])
        {
            parent[ultimateParentV] = ultimateParentU;
        }
        else
        {
            parent[ultimateParentV] = ultimateParentU;
            rank[ultimateParentU]++;
        }
    }
};