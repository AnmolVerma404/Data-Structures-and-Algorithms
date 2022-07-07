/*
This is similar to previous previous problems we solved, i.e. we will be given a 2D matrix and we need to find the minimum path sum from the 0th row to nth row and we can only travell in three direction down, down-right, and down-left and we can't choose more than one element from a row!!!

Approach
We need to visit all the path and find the minimum of them, therefore recursion solution must be there.
*/
#include <bits/stdc++.h>

using namespace std;

int minimumFallingPathSumRec(int i, int j, int n, vector<vector<int>> &v)
{
    if (j < 0 || j >= n)
        return 1e6;

    if (i == 0)
        return v[i][j];

    int up = v[i][j] + minimumFallingPathSumRec(i - 1, j, n, v);
    int upLeft = v[i][j] + minimumFallingPathSumRec(i - 1, j - 1, n, v);
    int upRight = v[i][j] + minimumFallingPathSumRec(i - 1, j + 1, n, v);

    return min(up, min(upLeft, upRight));
}

int minimumFallingPathSumRecDP(int i, int j, int n, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
        return 1e6;

    if (i == 0)
        return v[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = v[i][j] + minimumFallingPathSumRecDP(i - 1, j, n, v, dp);
    int upLeft = v[i][j] + minimumFallingPathSumRecDP(i - 1, j - 1, n, v, dp);
    int upRight = v[i][j] + minimumFallingPathSumRecDP(i - 1, j + 1, n, v, dp);

    return dp[i][j] = min(up, min(upLeft, upRight));
}

int minimumFallingPathSumTabulationDP(int n, vector<vector<int>> &v)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = v[0][j];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int up = v[i][j] + dp[i - 1][j];
            int upLeft = 1e6, upRight = 1e6;

            if (j - 1 >= 0)
            {
                upLeft = v[i][j] + dp[i - 1][j - 1];
            }
            if (j + 1 < n)
            {
                upRight = v[i][j] + dp[i - 1][j + 1];
            }

            dp[i][j] = min(up, min(upLeft, upRight));
        }
    }

    int mn = INT_MAX;
    for (auto &it : dp[n - 1])
    {
        mn = min(mn, it);
    }
    return mn;
}

int minimumFallingPathSumTabulationDPSpaceOptimization(int n, vector<vector<int>> &v)
{
    vector<int> prev(n, 0);

    for (int j = 0; j < n; ++j)
    {
        prev[j] = v[0][j];
    }

    for (int i = 1; i < n; ++i)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; ++j)
        {
            int up = v[i][j] + prev[j];
            int upLeft = 1e6, upRight = 1e6;

            if (j - 1 >= 0)
            {
                upLeft = v[i][j] + prev[j - 1];
            }
            if (j + 1 < n)
            {
                upRight = v[i][j] + prev[j + 1];
            }

            curr[j] = min(up, min(upLeft, upRight));
        }
        prev = curr;
    }

    int mn = INT_MAX;
    for (auto &it : prev)
    {
        mn = min(mn, it);
    }
    return mn;
}

int main()
{
    vector<vector<int>> v = {{2, 1, 3},
                             {6, 5, 4},
                             {7, 8, 9}};
    int n = v.size();

    // Recursion TC - O(3^n) SC - O(n) + O(2n-2)[Stack Space]
    int mnRec = INT_MAX;
    for (int j = 0; j < n; ++j)
    {
        mnRec = min(mnRec, minimumFallingPathSumRec(n - 1, j, n, v));
    }
    cout << mnRec << "\n";

    // Recursion + DP i.e. Mamoization TC - O(n) SC - O(n*n) + O(2n-2)[Stack Space]
    int mnRecDP = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j = 0; j < n; ++j)
    {
        mnRecDP = min(mnRecDP, minimumFallingPathSumRecDP(n - 1, j, n, v, dp));
    }
    cout << mnRecDP << "\n";

    // Tabulation DP TC - O(n) SC - O(n*n) + O(2n-2)[Stack Space]
    cout << minimumFallingPathSumTabulationDP(n, v) << "\n";

    // Tabulation DP TC - O(n) SC - O(n*n) + O(2n-2)[Stack Space]
    cout << minimumFallingPathSumTabulationDPSpaceOptimization(n, v) << "\n";

    return 0;
}