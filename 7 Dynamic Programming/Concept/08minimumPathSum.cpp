/*
This is similar to previous problem, in here just take the minimum of left and up to get the minimum path sum.
Start from 0,0 to m-1,n-1 find the minimum cost path?
*/
#include <bits/stdc++.h>

using namespace std;

int minimumPathSumRecursion(int n, int m, vector<vector<int>> &v)
{
    if (n == 0 && m == 0)
    {
        return v[n][m];
    }
    if (n < 0 || m < 0)
        return 1e6;
    int up = minimumPathSumRecursion(n - 1, m, v) + v[n][m];   
    int left = minimumPathSumRecursion(n, m - 1, v) + v[n][m]; 
    return min(up, left);                                      
}

int minimumPathSumMamoizationDP(int n, int m, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
    {
        return v[n][m]; 
    }
    if (n < 0 || m < 0)
        return 1e6;
    if (dp[n][m] != -1) 
        return dp[n][m];
    int left = minimumPathSumMamoizationDP(n, m - 1, v, dp) + v[n][m];
    int up = minimumPathSumMamoizationDP(n - 1, m, v, dp) + v[n][m];
    return dp[n][m] = min(left, up); 
}

int main()
{
    vector<vector<int>> v = {
        {1, 3, 100},
        {10, 1, 1}};
    int n = v.size();
    int m = v[0].size();

    cout << minimumPathSumRecursion(n - 1, m - 1, v) << "\n";

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << minimumPathSumMamoizationDP(n - 1, m - 1, v, dp) << "\n";

    return 0;
}