/*

*/
#include <bits/stdc++.h>

using namespace std;

int frogJumpRecursion(int n, vector<int> &wt)
{
    if (n == 0)
        return 0;
    int left = frogJumpRecursion(n - 1, wt) + abs(wt[n] - wt[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = frogJumpRecursion(n - 2, wt) + abs(wt[n] - wt[n - 2]);
    return min(left, right);
}

int frogJumpDPMemoization(int n, vector<int> &wt, vector<int> &dp)
{
    if (n == 0)
        return dp[n] = 0;
    if (dp[n] != -1)
        return dp[n];
    int left = frogJumpDPMemoization(n - 1, wt, dp) + abs(wt[n] - wt[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = frogJumpDPMemoization(n - 2, wt, dp) + abs(wt[n] - wt[n - 2]);
    return dp[n] = min(left, right);
}

int frogJumpDPTabulation(int n, vector<int> &wt, vector<int> &dp)
{
    dp[0] = 0;
    // dp[1] = dp[0] + abs(wt[1] - wt[0]);//Or write the ternary condition
    for (int i = 1; i < n; ++i)
    {
        dp[i] = min(dp[i - 1] + abs(wt[i] - wt[i - 1]), i == 1 ? INT_MAX : dp[i - 2] + abs(wt[i] - wt[i - 2]));
    }
    return dp[n - 1];
}

int frogJumpDPTabulationSpaceOptmization(int n, vector<int> &wt)
{
    int prev2 = 0;
    int prev1 = abs(wt[1] - wt[0]);
    for (int i = 2; i < n; ++i)
    {
        int curr = min(prev1 + abs(wt[i] - wt[i - 1]), prev2 + abs(wt[i] - wt[i - 2]));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    vector<int> wt = {30, 10, 60, 10, 60, 50};
    int n = wt.size();
    vector<int> dp(n, -1);
    cout << frogJumpRecursion(n - 1, wt) << "\n";
    cout << frogJumpDPMemoization(n - 1, wt, dp) << "\n";
    dp.resize(n, -1);
    cout << frogJumpDPTabulation(n, wt, dp) << "\n";
    cout << frogJumpDPTabulationSpaceOptmization(n, wt) << "\n";
    return 0;
}