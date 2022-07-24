/*

*/
#include <bits/stdc++.h>

using namespace std;

int knapsackRecursion(int ind, int n, int W, vector<int> &wt, vector<int> &val)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    int notTaken = 0 + knapsackRecursion(ind - 1, n, W, wt, val);
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackRecursion(ind - 1, n, W - wt[ind], wt, val);

    return max(notTaken, taken);
}

int knapsackMemoizationDP(int ind, int n, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];
    int notTaken = 0 + knapsackMemoizationDP(ind - 1, n, W, wt, val, dp);
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackMemoizationDP(ind - 1, n, W - wt[ind], wt, val, dp);

    return dp[ind][W] = max(notTaken, taken);
}

int main()
{
    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};
    int W = 6;
    int n = wt.size();

    cout << knapsackRecursion(n - 1, n, W, wt, val) << "\n"; // TC - O(2^(n*W))  SC - O(1)[Auxiliary Space] + O(n+W)[Stack Space]

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << knapsackMemoizationDP(n - 1, n, W, wt, val, dp) << "\n"; // TC - O(n*W) SC - O(n*W)[DP vector Space] + O(n+W)[Stack Space]

    return 0;
}