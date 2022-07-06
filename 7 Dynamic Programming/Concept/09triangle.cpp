/*
In this problem we will be given a trangular 2D vector, and we have to find the minimum path from 0th row to last(nth) row?
Also it's given at a point (i,j) we can only go to the (i+1,j) and (i+1,j+1) index.

Approach
We can observe that every path will include the 0th row but we have choice here to chose between any jth index in last(ith row).
So instead of going from nth index we will start from 0 and find all the possible paths from recursion.
*/
#include <bits/stdc++.h>

using namespace std;

int triangleRec(int i, int j, int n, vector<vector<int>> &v)
{
    if (i == n - 1)
        return v[i][j];
    int down = v[i][j] + triangleRec(i + 1, j, n, v);
    int downRight = v[i][j] + triangleRec(i + 1, j + 1, n, v);
    return min(down, downRight);
}

int triangleMemoizationDP(int i, int j, int n, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return v[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = v[i][j] + triangleMemoizationDP(i + 1, j, n, v, dp);
    int downRight = v[i][j] + triangleMemoizationDP(i + 1, j + 1, n, v, dp);
    return dp[i][j] = min(down, downRight);
}

int triangleTabulationDP(int i, int j, int n, vector<vector<int>> &v)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // As in the recursive solution we traverse from 0th row to nth row, therefor in here we will go from nth to 0th
    for (int i = 0; i < n; ++i)
    {
        dp[n - 1][i] = v[n - 1][i];
    }
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i; j >= 0; --j)
        {
            int down = v[i][j] + dp[i + 1][j];
            int downRight = v[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, downRight);
        }
    }
    return dp[0][0];
}
int triangleTabulationSpaceOptimizationDP(int i, int j, int n, vector<vector<int>> &v)
{
    vector<int> prev(n, 0), curr(n, 0);
    // As in the recursive solution we traverse from 0th row to nth row, therefor in here we will go from nth to 0th
    for (int i = 0; i < n; ++i)
    {
        prev[i] = v[n - 1][i];
    }
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i; j >= 0; --j)
        {
            int down = v[i][j] + prev[j];
            int downRight = v[i][j] + prev[j + 1];
            curr[j] = min(down, downRight);
        }
        prev = curr;
    }
    return prev[0];
}

int main()
{
    vector<vector<int>> v = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}};
    int n = v.size();

    cout << triangleRec(0, 0, n, v) << "\n";

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << triangleMemoizationDP(0, 0, n, v, dp) << "\n";

    cout << triangleTabulationDP(0, 0, n, v) << "\n";
    cout << triangleTabulationSpaceOptimizationDP(0, 0, n, v) << "\n";

    return 0;
}