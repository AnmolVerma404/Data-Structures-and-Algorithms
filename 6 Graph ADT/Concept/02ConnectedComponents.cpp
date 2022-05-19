/*
A graph can be connected or it may not be fully connected.
Eg - 
        1-2         4  6
           \        | /
            3       5
Above you can see there's one graph in which there is not connection b/w Right and Left sub graph
We can traverse this graph via DFS or BFS but we need tp maintain a visited array of size = number of vertices
This visited array will help in reducing the time complexity and prevent us from revisiting the nodes.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size = 10;
    vector<vector<int>>graph(size);
    bool visited[size];
    memset(&visited,false,sizeof(visited));
    //If you want to know the number of vertices in the graph increment count inside the condition statement.
    int count = 0;
    for(int i = 0;i<size;i++){
        if(visited[i]!=true){
            count++;
            dfs();
            bfs();
        }
    }
    return 0;
}