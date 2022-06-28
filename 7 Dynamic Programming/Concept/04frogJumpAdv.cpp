/*

*/
#include <bits/stdc++.h>

using namespace std;

int frogJumpDPMemoization(int n, int k, vector<int> &wt, vector<int> &dp)
{
    if (n == 0)
        return dp[n] = 0;
    if (dp[n] != -1)
        return dp[n];
    int mn = INT_MAX;
    for (int j = 1; j <= k; ++j)
    {
        if (n - j < 0)
            break;
        int jump = frogJumpDPMemoization(n - j, k, wt, dp) + abs(wt[n] - wt[n - j]);
        mn = min(mn, jump);
    }
    return dp[n] = mn;
}

int main()
{
    vector<int> wt = {30, 10, 60, 10, 60, 50}; // Weight/Height of building
    int n = wt.size();
    int k = 2;
    vector<int> dp(n, -1);                                   // Here we do not need n+1 size dp -> as in fibonacci we need to find the nth fibo num but here the size of wt vector in n-1 therefor need not to create an extra space.
    cout << frogJumpDPMemoization(n - 1, k, wt, dp) << "\n"; // TC - O(n), SC - O(n)[DP vector size] + O(N)[Stack space]

    return 0;
}