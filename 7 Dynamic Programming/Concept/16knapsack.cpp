/*
0 1 Knapsack is a very popular problem
In this we be given weight and value array which will contain weight and value of ith item, to be placed in the bag.
We are given a max weight W, the bag can only store W weight object
Your task is to maximise the value while also not carrying more weight that max weight

Approach
Greedy will not work here.
We can observe and get an idea that, in recursion we need to take and not take a ith value
*/
#include <bits/stdc++.h>

using namespace std;

int knapsackRecursion(int ind, int n, int W, vector<int> &wt, vector<int> &val)
{
    if (ind == 0) // At index 0 we will have our base case
    {
        if (wt[0] <= W)    // If it's not overweight
            return val[0]; // Return current calue
        else
            return 0; // ELse return 0
    }
    int notTaken = knapsackRecursion(ind - 1, n, W, wt, val); // Don't take the ith value
    int taken = INT_MIN;
    if (wt[ind] <= W)                                                           // Check if putting the ith value will overload your bag
        taken = val[ind] + knapsackRecursion(ind - 1, n, W - wt[ind], wt, val); // Take the ith value

    return max(notTaken, taken); // Find the max out of both
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
    if (dp[ind][W] != -1)  // If already calculated
        return dp[ind][W]; // Return dp[ind][W]
    int notTaken = knapsackMemoizationDP(ind - 1, n, W, wt, val, dp);
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackMemoizationDP(ind - 1, n, W - wt[ind], wt, val, dp);

    return dp[ind][W] = max(notTaken, taken); // Store the calculated ind and W in dp, so it can be used later
}

int knapsackTabulationDP(int n, int W, vector<int> &wt, vector<int> &val)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int i = wt[0]; i <= W; ++i)
    {
        dp[0][i] = val[0];//Base case was wt[0] <= W, therefore iterate from wt[0] to W and set them to val[0]
    }

    for (int i = 1; i < n; ++i)//From 1 because base already calculated
    {
        for (int j = 0; j <= W; ++j)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (wt[i] <= j)
                take = val[i] + dp[i - 1][j - wt[i]];
            dp[i][j] = max(take, notTake);//Find the max among take and not take
        }
    }

    return dp[n - 1][W];//Return the result
}
int knapsackTabulationSpaceOptimizationDP(int n, int W, vector<int> &wt, vector<int> &val)
{
    //We were only using last row, therefore we need not to store the complete DP
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);
    for (int i = wt[0]; i <= W; ++i)
    {
        prev[i] = val[0];//Base case
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            int notTake = prev[j];//Calculate them from the previous vector
            int take = INT_MIN;
            if (wt[i] <= j)
                take = val[i] + prev[j - wt[i]];//Calculate them from the previous vector
            curr[j] = max(take, notTake);//Set the max result to the current vector
        }
        prev = curr;//After the wt iteration set prev = current, so it can be used in next iteration
    }

    return prev[W];//Finally return the result
}

int main()
{
    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};
    int W = 6;
    int n = wt.size();

    cout << knapsackRecursion(n - 1, n, W, wt, val) << "\n"; // TC - O(2^(n*W))  SC - O(1)[Auxiliary Space] + O(n+W)[Stack Space]

    // As in every recrusive call, the value changing is i and W, therefore we have to defind a DP array to store dp[i][W] fore storing calculated stuff, and overlapping problems
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << knapsackMemoizationDP(n - 1, n, W, wt, val, dp) << "\n"; // TC - O(n*W) SC - O(n*W)[DP vector Space] + O(n+W)[Stack Space]

    cout << knapsackTabulationDP(n, W, wt, val) << "\n";

    cout << knapsackTabulationSpaceOptimizationDP(n, W, wt, val) << "\n";

    return 0;
}