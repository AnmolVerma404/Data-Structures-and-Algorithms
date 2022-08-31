/*
In this type of peoblem we have a target and a value array, in which we have to find the minimum number of value in array add up to target and a value can be used multiple times

First of all, this might be solved using heap but to find minimum we must check all the possibilities
*/
#include <bits/stdc++.h>

using namespace std;

int minimumCoins(int i, int t, int n, vector<int> &v)
{
    if (i < 0)//Base case
    {
        if (t % v[i] == 0)//Check if the value is divisible be current target or not
            return t / v[i];//If it's divisibe then return the quotient
        else
            return 1e9;//Else return big int, as it's not possible
    }
    int notTake = minimumCoins(i - 1, t, n, v);//If not taking reduce the index
    int take = INT_MAX;
    if (v[i] <= t)//Check if the difference is +ve or not
    {
        take = 1 + minimumCoins(i, t - v[i], n, v);//Add 1 and recurse again with new t = t-v[i]
    }
    return min(take, notTake);//Return the minimum out of the take and not take
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
    if (dp[i][t] != -1)//If already calculated
        return dp[i][t];//Return the precalculated result
    int notTake = minimumCoins(i - 1, t, n, v);
    int take = INT_MAX;
    if (v[i] <= t)
    {
        take = 1 + minimumCoins(i, t - v[i], n, v);
    }
    return dp[i][t] = min(take, notTake);//Store the minimum in dp[i][t] for future use
}

int minimumCoinsTabulationDP(int n, int t, vector<int> &v)
{
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    //Base case
    //For index = 0, there were 0 .... t target value
    //Therefore store all of them in 2D dp vector
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
            dp[i][j] = min(notTake, take);//Store in dp vector, so that it can be used in next iteration
        }
    }
    return dp[n - 1][t];//Finally return the computed result
}

int minimumCoinsTabulationSpaceOptDP(int n, int t, vector<int> &v)
{
    //From the tabulation approch, you can see that only last i.e. (i-1)th dp vector was used in every step
    //It was not necessary to store all the n*t computed results
    vector<int> curr(t + 1, 0), prev(t + 1, 0);
    for (int i = 0; i <= t; ++i)
    {
        if (i % v[0] == 0)
            prev[i] = i / v[0];//Store base case in prev, so it can be used to calculate current vector
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= t; ++j)
        {
            int notTake = prev[j];//i-1,therefore use the prev vector
            int take = 1e9;
            if (v[i] <= j)
            {
                take = 1 + curr[j - v[i]];//No need of i-1, the computation was of current vector only
            }
            curr[j] = min(notTake, take);//Store the result in the current vector
        }
        prev = curr;//After the target iteration assign the prev to curr, so that prev can be used in next iteration
    }
    return prev[t];//Finally return prev[t]
}

int main()
{
    vector<int> v = {1, 2, 3};
    int t = 7, n = v.size();

    //In this we can't simply write the TC and SC as at current target we can either stay or move
    //Therefore it's not O(2^n) but much greater than that.
    cout << minimumCoins(n - 1, t, n, v) << "\n";//TC - Exponential SC - [Stack space call dependent on target]

    //Why 2D vector, as in last recursion there were index and target changing.
    //Therefore we need 2D dp vector to keep track of them in different possible combinations
    vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    cout << minimumCoinsMemoizationDP(n - 1, t, n, v, dp) << "\n";//TC - O(n*t) SC - O(n*t) + O(n)[Stack Space]

    cout << minimumCoinsTabulationDP(n, t, v) << "\n";//TC - O(n*t) SC - O(n*t)

    cout << minimumCoinsTabulationSpaceOptDP(n, t, v) << "\n";//TC - O(n*t) SC - O(t)

    return 0;
}