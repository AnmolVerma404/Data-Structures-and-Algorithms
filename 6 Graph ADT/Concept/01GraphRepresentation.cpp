/*
Graphs can be stored in two ways i.e. using an adjacency matrix or an adjacency list
In simple words, the adjacency matrix is a way of storing graphs node/connection/weight into an array that is immutable. And the space complexity is n*n where n is the number of nodes/vertex if the vertex is numbered from 1 to n. This way is not the optimal way of storing a graph, therefore we use Adjacency List.
Adjacency List stores a graph into a list that is mutable therefore we need not create extra space for nodes that don't even exist.

  adjacency matrix               adjacency list
    0 1 2 3
  0 0 0 0 0               0
  1 0 0 1 1               1 (2,3)
  2 0 1 1 0               2 (1,2)
  3 0 1 0 0               3 (1)

From the above example, we can easily see an n*n size matrix with soo much extra space whereas the list only consists of nodes which is actually present in the graph.
The value in the list/matrix can be the weight of edges or a boolean value or different things.
Time complexity when Adj. Matrix is used is - O(V^2) and when Adj. List is used is O(V+E) where V is vertex and E is Edge
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Adjacency Matrix
    int graph[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
    };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    /*
    Output - 
    0 1 0 0 0 
    0 1 0 0 0 
    0 0 1 0 0 
    0 1 0 0 0 
    0 0 0 0 0
    */
    // Adjacency List
    // (i)
    vector<vector<int>> g = {
        {2, 3},
        {4, 5},
        {1, 2}
    };
    cout<<"\n";
    for(int i = 0;i<g.size();i++){
        for(int j = 0;j<g[i].size();j++){
            cout<<g[i][j]<<" "; 
        }
        cout<<"\n";
    }
    cout<<"\n";
    /*
    Output - 
    2 3 
    4 5 
    1 2 
    */
    // (ii)
    vector<int>gm[5]={
        {2,3},
        {1,4},
        {1,3},
        {0,0},
        {1,0},
    };
    for(int i = 0;i<5;i++){
        for(int j = 0;j<gm[i].size();j++){
            cout<<gm[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    /*
    Output - 
    2 3
    1 4
    1 3
    0 0
    1 0
    */
    // If we want to store the weight and the other property of graph we can use pair in vector
    vector<vector<pair<int,int>>>gp={
        {{1,2},{234,3}},
        {{123,4},{134,6}},
        {{231,6},{678,7}},
        {{1,1},{55,2}},
        {{155,7},{3498,1}}
    };
    for(int i = 0;i<gp.size();i++){
        for(int j = 0;j<gp[i].size();j++){
            cout<<gp[i][j].first<<":"<<gp[i][j].second<<"  ";
        }
        cout<<"\n";
    }
    /*
    Output - 
    1:2  234:3
    123:4  134:6
    231:6  678:7
    1:1  55:2
    155:7  3498:1
    */
    return 0;
}