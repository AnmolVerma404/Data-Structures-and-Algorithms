/*
Problem - https://leetcode.com/problems/cherry-pickup-ii/
In the problem statement we will be given a 2D array, and starting index of at two points,
your job is to travell from 0th row to the n-1th column and pick up cherry at a position.
Find out what is the maximum cherry both of them can pick up.
And the direction they can more are down,down left, and down right

Approach
Here also we need to find for all path i.e. in 9 direction(as for 1 direction by 1st person we will be having 3 different direction of the person 2)
From here we can observe the direction at j1th and j2th poition are 3x3 and j1,j2<m where m is the column length
And we will also having row index, as there will be overlapping subproblems, so we need a DP vector
But not 2D, we need 3D as there are m*m possibilities for m size row.
So dp size will by n*m*m

*/
#include <bits/stdc++.h>

using namespace std;

int cherryPickupRec(int i, int j1, int j2, int n, int m, vector<vector<int>> &v)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e7;
    if (i == n - 1)
    {
        if (j1 == j2)
            return v[i][j1];
        else
            return v[i][j1] + v[i][j2];
    }
    int mx = -1e7;
    for (int d1 = -1; d1 <= 1; ++d1)
    {
        for (int d2 = -1; d2 <= 1; ++d2)
        {
            int val = 0;
            if (j1 == j2)
            {
                val = v[i][j1];
            }
            else
            {
                val = v[i][j1] + v[i][j2];
            }
            val += cherryPickupRec(i + 1, j1 + d1, j2 + d2, n, m, v);
            mx = max(mx, val);
        }
    }
    return mx;
}

int cherryPickupMemoizationDP(int i, int j1, int j2, int n, int m, vector<vector<int>> &v, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e7;
    if (i == n - 1)
    {
        if (j1 == j2)
            return v[i][j1];
        else
            return v[i][j1] + v[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int mx = -1e7;
    for (int d1 = -1; d1 <= 1; ++d1)
    {
        for (int d2 = -1; d2 <= 1; ++d2)
        {
            int val = 0;
            if (j1 == j2)
            {
                val = v[i][j1];
            }
            else
            {
                val = v[i][j1] + v[i][j2];
            }
            val += cherryPickupMemoizationDP(i + 1, j1 + d1, j2 + d2, n, m, v, dp);
            mx = max(mx, val);
        }
    }
    return dp[i][j1][j2] = mx;
}

int cherryPickupTabulationDP(int n, int m, vector<vector<int>> &v)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; ++j1)
    {
        for (int j2 = 0; j2 < m; ++j2)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = v[n - 1][j1];
            else
                dp[n - 1][j1][j2] = v[n - 1][j1] + v[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j1 = 0; j1 < m; ++j1)
        {
            for (int j2 = 0; j2 < m; ++j2)
            {
                int mx = -1e7;
                for (int d1 = -1; d1 <= 1; ++d1)
                {
                    for (int d2 = -1; d2 <= 1; ++d2)
                    {
                        int val = 0;
                        if (j1 == j2)
                        {
                            val = v[i][j1];
                        }
                        else
                        {
                            val = v[i][j1] + v[i][j2];
                        }
                        if (j1 + d1 >= 0 && j1 + d1 < m && j2 + d2 >= 0 && j2 + d2 < m)
                        {
                            val += dp[i + 1][j1 + d1][j2 + d2];
                        }
                        else
                        {
                            val += -1e7;
                        }
                        mx = max(mx, val);
                    }
                }
                dp[i][j1][j2] = mx;
            }
        }
    }
    return dp[0][0][m - 1];
}

int cherryPickupTabulationSpaceOptimizationDP(int n, int m, vector<vector<int>> &v)
{
    vector<vector<int>> prev(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; ++j1)
    {
        for (int j2 = 0; j2 < m; ++j2)
        {
            if (j1 == j2)
                prev[j1][j2] = v[n - 1][j1];
            else
                prev[j1][j2] = v[n - 1][j1] + v[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j1 = 0; j1 < m; ++j1)
        {
            for (int j2 = 0; j2 < m; ++j2)
            {
                int mx = -1e7;
                for (int d1 = -1; d1 <= 1; ++d1)
                {
                    for (int d2 = -1; d2 <= 1; ++d2)
                    {
                        int val = 0;
                        if (j1 == j2)
                        {
                            val = v[i][j1];
                        }
                        else
                        {
                            val = v[i][j1] + v[i][j2];
                        }
                        if (j1 + d1 >= 0 && j1 + d1 < m && j2 + d2 >= 0 && j2 + d2 < m)
                        {
                            val += prev[j1 + d1][j2 + d2];
                        }
                        else
                        {
                            val += -1e7;
                        }
                        mx = max(mx, val);
                    }
                }
                curr[j1][j2] = mx;
            }
        }
        prev = curr;
    }
    return prev[0][m - 1];
}

int main()
{
    vector<vector<int>> v = {{3, 1, 1},
                             {2, 5, 1},
                             {1, 5, 5},
                             {2, 1, 1}};

    int n = v.size();
    int m = v[0].size();

    cout << cherryPickupRec(0, 0, m - 1, n, m, v) << "\n";

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << cherryPickupMemoizationDP(0, 0, m - 1, n, m, v, dp) << "\n";

    cout << cherryPickupTabulationDP(n, m, v) << "\n";

    cout << cherryPickupTabulationSpaceOptimizationDP(n, m, v) << "\n";

    return 0;
}