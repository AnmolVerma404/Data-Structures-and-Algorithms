/*
In this type of peoblem we have a target and a value array, in which we have to find the minimum number of value in array add up to target and a value can be used multiple times

First of all, this might be solved using heap but to find minimum we must check all the possibilities
*/
#include <bits/stdc++.h>

using namespace std;

int minimumCoins(int i, int t, int n, vector<int> &v)
{
    if (i < 0)
    {
        if (t % v[i] == 0)
            return t / v[i];
        else
            return 1e9;
    }
    int notTake = minimumCoins(i - 1, t, n, v);
    int take = INT_MAX;
    if (v[i] <= t)
    {
        take = 1 + minimumCoins(i, t - v[i], n, v);
    }
    return min(take, notTake);
}

int minimumCoinsMemoizationDP(int i, int t, int n, vector<int> &v, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        if (t % v[i] == 0)
            return t / v[i];
        else
            return 1e9;
    }
    if (dp[i][t] != -1)
        return dp[i][t];
    int notTake = minimumCoins(i - 1, t, n, v);
    int take = INT_MAX;
    if (v[i] <= t)
    {
        take = 1 + minimumCoins(i, t - v[i], n, v);
    }
    return dp[i][t] = min(take, notTake);
}

int minimumCoinsTabulationDP(int n, int t, vector<int> &v)
{
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    for (int i = 0; i <= t; ++i)
    {
        if (i % v[0] == 0)
            dp[0][i] = i / v[0];
        else
            dp[0][i] = 1e9;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= t; ++j)
        {
            int notTake = dp[i - 1][j];
            int take = 1e9;
            if (v[i] <= j)
            {
                take = 1 + dp[i][j - v[i]];
            }
            dp[i][j] = min(notTake, take);
        }
    }
    return dp[n - 1][t];
}

int minimumCoinsTabulationSpaceOptDP(int n, int t, vector<int> &v)
{
    vector<int> curr(t + 1, 0), prev(t + 1, 0);
    for (int i = 0; i <= t; ++i)
    {
        if (i % v[0] == 0)
            prev[i] = i / v[0];
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= t; ++j)
        {
            int notTake = prev[j];
            int take = 1e9;
            if (v[i] <= j)
            {
                take = 1 + curr[j - v[i]];
            }
            curr[j] = min(notTake, take);
        }
        prev = curr;
    }
    return prev[t];
}

int main()
{
    vector<int> v = {1, 2, 3};
    int t = 7, n = v.size();

    cout << minimumCoins(n - 1, t, n, v) << "\n";

    vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    cout << minimumCoinsMemoizationDP(n - 1, t, n, v, dp) << "\n";

    cout << minimumCoinsTabulationDP(n, t, v) << "\n";

    cout << minimumCoinsTabulationSpaceOptDP(n, t, v) << "\n";

    return 0;
}