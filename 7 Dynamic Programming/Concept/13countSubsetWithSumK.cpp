/*
Problem Link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

*/

#include <bits/stdc++.h>

using namespace std;

int subSetSumKRecursion(int i, int n, int t, vector<int> &v)
{
    if (t == 0)
        return 1;
    if (i == 0)
    {
        if (v[i] == t)
        {
            return 1;
        }
        return 0;
    }

    int take = subSetSumKRecursion(i - 1, n, t - v[i], v);
    int notTake = subSetSumKRecursion(i - 1, n, t, v);

    return take + notTake;
}

int subSetSumKRecursionDP(int i, int n, int t, vector<int> &v, vector<vector<int>> &dp)
{
    if (t == 0)
        return 1;
    if (i == 0)
    {
        if (v[i] == t)
        {
            return 1;
        }
        return 0;
    }

    if (dp[i][t] != -1)
        return dp[i][t];

    int take = subSetSumKRecursionDP(i - 1, n, t - v[i], v, dp);
    int notTake = subSetSumKRecursionDP(i - 1, n, t, v, dp);

    return dp[i][t] = take + notTake;
}

int subSetSumKTabulationDP(int n, int t, vector<int> &v)
{
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 1;
    }

    if (v[0] <= t)
        dp[0][v[0]] = 1;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= t; ++j)
        {
            int take = v[i] <= j ? take = dp[i - 1][j - v[i]] : 0;
            int notTake = dp[i - 1][j];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][t];
}

int subSetSunkTabulationSpaceOptimization(int n, int t, vector<int> &v)
{
    vector<int> prev(t + 1, 0);
    vector<int> curr(t + 1, 0);
    prev[0] = 1;
    if (v[0] <= t)
        prev[v[0]] = 1;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= t; ++j)
        {
            int take = v[i] <= j ? take = prev[j - v[i]] : 0;
            int notTake = prev[j];
            curr[j] = take + notTake;
        }
        prev = curr;
    }
    return prev[t];
}

int main()
{
    vector<int> v = {1, 2, 2, 3};
    int n = v.size();
    int t = 3;

    cout << subSetSumKRecursion(n - 1, n, t, v) << "\n";

    vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    cout << subSetSumKRecursionDP(n - 1, n, t, v, dp) << "\n";

    cout << subSetSumKTabulationDP(n, t, v) << "\n";

    cout << subSetSunkTabulationSpaceOptimization(n, t, v) << "\n";

    return 0;
}