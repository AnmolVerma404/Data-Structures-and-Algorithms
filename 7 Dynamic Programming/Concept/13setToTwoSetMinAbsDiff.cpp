#include <bits/stdc++.h>

using namespace std;

void targetSumTabulationDP(int n, int t, vector<int> &v, vector<vector<int>> &dp)
{

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
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    int n = v.size();
    int totalSun = 0;
    for (auto &it : v)
        totalSun += it;
    int t = totalSun;

    vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    targetSumTabulationDP(n, t, v, dp);

    int mn = 1e9;
    for (int s1 = 0; s1 < totalSun; ++s1)
    {
        if (dp[n - 1][s1] == true)
        {
            mn = min(mn, abs((totalSun - s1) - s1));
        }
    }

    cout << mn << "\n";

    return 0;
}