#include <bits/stdc++.h>

using namespace std;
#define V 5
/*
Prims Algoritms to find Minimum Spanning Tree
    - It is a gready algorithm
    - The number of edges  = V-1 ; V = vertices
    - For prims algorithm we need a parent array which will store MST
*/
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int g[V][V])
{
    //This is a simple MST print, here the final and complete parent array is avalible of the integers/path and the g[i][parrent[i]] will give the weight of the path
    cout<<"The sortest path via Prims Algorithm is:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t" << g[i][parent[i]] << " \n";
        totalWeight+=g[i][parent[i]];
    }
    cout<<"Total Weight: "<<totalWeight<<"\n";
}

void primsMST(int g[V][V])
{
    //This array will contain all the index of element in the graph which are satisfying MST conditions
    int parent[V];
    //The key array will contain the minimum weight vertices and the V element in the key == INT_MAX as to find minimum the comparable value should be the maximum
    int key[V];

    // As one of the property of MST is no vertices should be visited more than one time, so minset will contain wether a vertice is visited or not. All value of minset is set to false as till now none of the vertice is visited, in simple words it is the weight upto ith term in V

    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    //The key[0] == 0 as the weight at the first vertices is == 0
    key[0] = 0;
    //The parent of the first vertices is -1, that show the MST will start from 1 and parent[1] will be the first vetices in the MST and it will end at less that V (property of MST i.e. total conneted node == V-1)
    parent[0] = -1;
    // The loop start from 1 and end at "< V" as the matrix have only 5 row/vertices and to be MST the path much only include 4 vertices therefore 0,1,2,3 will be the value of i in the for loop
    for (int i = 0; i < V - 1; i++)
    {
        int u = minKey(key, mstSet);
        // As the uth index in Graph is visited in the MST and is the minimum and following all the MST conditions
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            // In the below conditional statement we check if the vertices connection is avalable and it is now visited and the RHS will check if the the other connection have less weight and they both must be satisfied
            if (g[u][v] && mstSet[v] == false && g[u][v]<key[v])
            {
                parent[v] = u;
                key[v] = g[u][v];
            }
        }
    }
    printMST(parent, g);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    primsMST(graph);

    return 0;
}