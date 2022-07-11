/*

*/
#include <bits/stdc++.h>

using namespace std;

int targetSumRec(int i, int t, vector<int> &v)
{
    if (t == 0)
        return 1;
    if (i == 0)
        return v[i] == t;

    bool notTake = targetSumRec(i - 1, t, v);
    bool take = 0;
    if (t >= v[i])
    {
        take = targetSumRec(i - 1, t - v[i], v);
    }
    return notTake || take;
}

int targetSumRecMemoizationDP(int i, int t, vector<int> &v, vector<vector<int>> &dp)
{
    if (t == 0)
        return 1;
    if (i == 0)
        return v[i] == t;
    if (dp[i][t] != -1)
        return dp[i][t];
    bool notTake = targetSumRecMemoizationDP(i - 1, t, v, dp);
    bool take = 0;
    if (t >= v[i])
    {
        take = targetSumRecMemoizationDP(i - 1, t - v[i], v, dp);
    }
    return dp[i][t] = notTake || take;
}

int targetSumTabulationDP(int n, int t, vector<int> &v)
{
    vector<vector<bool>> dp(n, vector<bool>(t + 1, false));
    for (int i = 0; i < n; ++i)
        dp[i][0] = true;
    dp[0][v[0]] = true;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= t; ++j)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (j >= v[i])
            {
                take = dp[i - 1][j - v[i]];
            }
            dp[i][j] = notTake || take;
        }
    }
    return dp[n - 1][t];
}

int targetSumTabulationSpaceOptimizationDP(int n, int t, vector<int> &v)
{
    vector<bool> prev(t + 1, false);
    vector<bool> curr(t + 1, false);
    prev[0] = true, curr[0] = true;
    prev[v[0]] = true;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= t; ++j)
        {
            bool notTake = prev[j];
            bool take = false;
            if (j >= v[i])
            {
                take = prev[j - v[i]];
            }
            curr[j] = notTake || take;
        }
        prev = curr;
    }
    return prev[t];
}

int main()
{
    vector<int> v = {2, 3, 1, 1};
    int t = 4;
    int n = v.size();

    cout << targetSumRec(n - 1, t, v) << "\n";

    vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    cout << targetSumRecMemoizationDP(n - 1, t, v, dp) << "\n";

    cout << targetSumTabulationDP(n, t, v) << "\n";

    cout << targetSumTabulationSpaceOptimizationDP(n, t, v) << "\n";

    return 0;
}