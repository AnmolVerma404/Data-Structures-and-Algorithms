/*
Time Complexity - O(N+E)*2
Space Complexity - O(2N)
We are going to need the help of topoligical sorting and also an distance array which will store the distance of each and every node.
So way do we need topological sorting?
As we know in topolocal sorting we get the final result from which we can say that every node in a graph which has an edge from vertices u to v where u will come before v in the topological sort.
So using that result we can find the shortest path and we need not to care about conditions like if the uth node dist will be infinity at the point when it's passed the vth vertex.
*/
#include <bits/stdc++.h>

using namespace std;

void topo(int i, stack<int> &st, vector<bool> &visited, vector<vector<pair<int, int>>> &g)
{
    visited[i] = true;
    for (pair<int, int> j : g[i])
    {
        if (!visited[j.first])
        {
            topo(j.first, st, visited, g);
        }
    }
    st.push(i);
}

void shortestPath(int n, vector<vector<pair<int, int>>> g)
{
    //Define stack and the visited array, do topological sort
    //You can find topo sort explanation in DFS and BFS in there respective files
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topo(i, st, visited, g);
        }
    }
    //Defina a distance vector of size equal to the number of vertices in the given graph and set all the value to INT_MAX that is equivalent to infinity.
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;//Set the distance for the node 0 to 0, as it's the starting node
    while (!st.empty())//stack contain the topo sort so empty the stack to set the distance
    {
        int top = st.top();//Get the top most element in the stack
        st.pop();
        if (dist[top] != INT_MAX)//Check if the top is euqal not to INT_MAX as this is topo sort, this condition will only help if the starting node from finding the shortest distance from is not 0
        {
            for (auto i : g[top])//Find all the adjacent node to the current node
            {
                if (dist[top] + i.second < dist[i.first])//If the distance of adjacent node is smaller that the complete path weight the update the adjacent node distance in the array
                {
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)//Traverse through the distance array and print the output.
    {
        if (dist[i] == INT_MAX)
            cout << i << " "
                 << "INF\n";
        else
            cout << i << " " << dist[i] << "\n";
    }
}

int main()
{
    //{a,b} -> a is the vertex and b is the weight
    vector<vector<pair<int, int>>> g = {//A valid Directed graph with weight
        {{1, 2}, {4, 1}},
        {{2, 3}},
        {{3, 6}},
        {},
        {{2, 2}, {5, 4}},
        {{3, 1}}};
    int n = g.size();//Get the size of the 
    shortestPath(n, g);
    return 0;
}