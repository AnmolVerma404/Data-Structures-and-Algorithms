/*
This data structure is mostly used in other algorithms like Kruskal's algorithm and in CP.
The use of Disjoint Set(DS) is if we were given two-node and we have to tell whether they belong in the same set or not? How we will find it and the answer is by using DS, which help's to get the answer in constant time.
DS provides us with two different operations - 1) Find Parent Operation and 2) Union Operation
What do these operations do?
Union Operation - As the name gives the hint it joins two-node into a new group or adds them into an already existing group.
Ex - union(0,1) at start 0 and 1 was the parent of themself but after there union, they will form a group and the parent will be decided(Whom parent node is decided? It will be answered below when I will be talking about rank) then 0 will be the parent of this new group.
Find Parent Operation - From the previous example we can easily figure out this operation, it will take a node as an argument and return its parent Ex - find parent(1) will give 0 as a result
While implementing this we use a rank array of size equal to a number of vertices in the graph which will initially store 0, it will increase when union operation is to be performed, suppose union(0,1) rank is 0 and 0 as both are same **The important rule is we always join the lower rank node to the higher rank node (0<-1) now increase the rank of parent node i.e. 0 by 1.
Rank of a node will only increase of the rank of nodes are same during union
if we try union(0,2) it will be rank of 0 is 1 and 2 is 0, therefore add 2 in 0.Now, findParent(2) is also 0, and the rank of 0 is still 1.
If there is another set that has height 1 and we add it to 0, 0's rank will be 3(assuming 0 as parent node height)
To find the parent we need to traverse all the way up to the main parent node, instead of doing that we can do path compression, don't change the rank just point all the depth nodes to the main parent node, now findParent operation can be performed in constant time
Time Complexity - O(m) where m is the number of operations and otherwise both the union and find parent operation take an O(1) time
Space Complexity - O(n) we are using a rank and a parent array.
*/
#include <bits/stdc++.h>

using namespace std;

int n = 10000;
int parent[10000];
int ranks[10000];

void makeSet()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = 1;
        ranks[i] = 0;
    }
}

int findParent(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionOperation(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (ranks[u] < ranks[v])
    {
        parent[u] = v;
    }
    else if (ranks[v] < ranks[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        ranks[u]++;
    }
}

int main()
{
    makeSet();
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        unionOperation(u, v);
    }
    if (findParent(3) == findParent(7))
    {
        cout << "Same Parent\n";
    }
    else
    {
        cout << "Different Parent\n";
    }
    return 0;
}