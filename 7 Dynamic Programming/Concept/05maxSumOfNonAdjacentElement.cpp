/*
This this problem you are given an array of numbers you have to print the maximum sum when the condition is it's can't be an Adjacent Element!!!

The Approach is really straight forward instead of adding up the last element add the last second element, so there will be no case of being an Adjacent Element. Also during the step add the current element to the result
And while doing so, also call the function for the last element but this time dont add the current nth index to it.
The left recursion tree will contain not picked and the right will contain picked element.
*/
#include <bits/stdc++.h>

using namespace std;

int maxSumOfNonAdjElRecursion(int n, vector<int> &v)
{
    if (n == 0) // Base case
        return v[n];
    if (n < 0) // If n is -1 due to n-2 call(left call) return 0
        return 0;
    int left = v[n] + maxSumOfNonAdjElRecursion(n - 2, v); // Pick current element for the max sum
    int right = maxSumOfNonAdjElRecursion(n - 1, v);       // Do not pick current element for the max sum
    return max(left, right);                               // Find which one is maximum amont pick and not pick
}

int maxSumOfNonAdjElMemoizationDP(int n, vector<int> &v, vector<int> &dp)
{
    // DP is completely same, and instead of returning save the output in the dp vector
    if (n == 0)
        return dp[n] = v[n];
    if (n < 0)
        return 0;
    if (dp[n] != -1) // If already calculated just return the calculated result.
        return dp[n];
    int left = v[n] + maxSumOfNonAdjElMemoizationDP(n - 2, v, dp);
    int right = maxSumOfNonAdjElMemoizationDP(n - 1, v, dp);
    return dp[n] = max(left, right);//Set 
}

int maxSumOfNonAdjElTabulationDP(int n, vector<int> &v, vector<int> &dp)
{
    dp[0] = v[0];//Base condition
    for (int i = 1; i < n; ++i)
    {
        dp[i] = max(v[i] + (i > 1 ? dp[i - 2] : 0), dp[i - 1]);//Left and right store it in dp[i]
    }
    return dp[n - 1];//Return the last element from dp
}

int maxSumOfNonAdjElTabulationSpaceOptDP(int n, vector<int> &v)
{
    int prev1  = v[0];//Base condition
    int prev2 = 0;//Condition if n < 0 so store 0
    for (int i = 1; i < n; ++i)
    {
        int curr = max(v[i] + prev2,prev1);//find max among left and right//Left and right are from recursion and will help to understand this logic better
        prev2 = prev1;//Update prev2 to prev1 as we are moving one index forward
        prev1 = curr;//prev1 to curr
    }
    return prev1;//As prev1 is curr of last iteration return it
}

int main()
{
    vector<int> v = {1, 2, 4, 9};
    int n = v.size();
    vector<int> dp(n, -1);//Here we do not need n+1 size dp -> as in fibonacci we need to find the nth fibo num but here the size of v vector in n-1 therefor need not to create an extra space.
    cout << maxSumOfNonAdjElRecursion(n - 1, v) << "\n";//TC - O(2^n), SC - O(N)[Stack space]
    cout << maxSumOfNonAdjElMemoizationDP(n - 1, v, dp) << "\n";//TC - O(n), SC - O(n)[DP vector size] + O(N)[Stack space]
    dp.resize(n, -1);//As dp vector is filled from last function call due to reference call, therefor we need to empty and resize the dp to n and values to -1
    cout << maxSumOfNonAdjElTabulationDP(n, v, dp) << "\n";//TC - O(n), SC - O(n)[DP vector size]
    cout << maxSumOfNonAdjElTabulationSpaceOptDP(n, v) << "\n";//TC - O(n), SC - O(1)
    return 0;
}