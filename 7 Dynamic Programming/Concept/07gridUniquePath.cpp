/*
In this problem we will be given 2 integer input n and m, here n is the lenght of row, and m is the length of column of a 2D matrix we need to find all the unique path that are available from starting position i.e. 0,0 to the end position i.e. n-1,m-1. Also it's given that you can only move down and right!!!

Approach 
As we need to find all the possible path, therefore first thing in our mind should be recursion.
Now followed in the code!!!
*/
#include <bits/stdc++.h>

using namespace std;

int gridUniquePathRecursion(int n, int m)
{
    /*
    This is the base condition after recursion calls if we were on right path, we will reach our 
    destination i.e. 0,0 so we can say it was a valid path and we will return 1, as one path is
    possible from the executed steps.
    */
    if (n == 0 && m == 0)
    {
        return 1;
    }
    if (n < 0 || m < 0)//If n or m goes less than zero that mean it's not a valid path, therefore retuern 0, so if it's either up or left it's sum will be only the valid path
        return 0;
    //As we can either move up or down therefore we will try both path from our current position in matrix
    int up = gridUniquePathRecursion(n - 1, m);//For up decrement the nth row index by 1, and make a recursion call for it
    int left = gridUniquePathRecursion(n, m - 1);//And the another direction is left, and for that we just need to move m index by one which is the column index
    return up + left;//Finally return the sum of up and left, as it will sum up all the possible paths
}

int gridUniquePathMamoizationDP(int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
    {
        return dp[n][m] = 1;
    }
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int up = gridUniquePathMamoizationDP(n - 1, m, dp);
    int left = gridUniquePathMamoizationDP(n, m - 1, dp);
    return dp[n][m] = up + left;
}

int gridUniquePathTabulationDP(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int up = 0, left = 0;
            if (i != 0)
                up = dp[i - 1][j];
            if (j != 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[n - 1][m - 1];
}

int gridUniquePathTabulationSpaceOptimizationDP(int n, int m)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0){
                temp[i] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
                up = prev[i - 1];
            if (j > 0)
                left = temp[j - 1];
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[m - 1];
}

int main()
{
    int n = 3, m = 3;//Input // n-> row, m -> column

    cout << gridUniquePathRecursion(n - 1, m - 1) << "\n";//TC - O(2^(n*m)) SC - O(n-1 + m-1)[stack space] + O(1)[Auxiliary space]

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << gridUniquePathMamoizationDP(n - 1, m - 1, dp) << "\n";

    cout << gridUniquePathTabulationDP(n, m) << "\n";

    cout << gridUniquePathTabulationSpaceOptimizationDP(n, m) << "\n";

    return 0;
}