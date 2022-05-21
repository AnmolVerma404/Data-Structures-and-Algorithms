/*

*/
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>&v,int n){
    
}

int main()
{
    //Make sure to take a vaild graph
    vector<vector<int>> g = {
        {1, 5},
        {0, 2, 5, 3},
        {1, 3},
        {1, 2, 4},
        {3, 5},
        {0, 1, 4}};
    int size = g.size();
    dfs(g,size);
    return 0;
}