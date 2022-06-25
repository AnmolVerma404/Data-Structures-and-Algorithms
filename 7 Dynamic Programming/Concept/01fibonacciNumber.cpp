/*
Fibonacci Number Solved using 4 ways
    1. Brute Force : TC - O(2^n), SC - O(1) + Stack Space - O(n) 
    As recursion call will hold upto they get over and this process will take space in stack memory
    2. DP Memoization : TC - O(N), SC - O(N) + Stack Space - O(n)
    3. DP Tabulation : TC - O(N), SC - O(N)
    4. DP Tabulation + Space Optimization : TC - O(N), SC - O(1)
*/
#include <bits/stdc++.h>

using namespace std;

int fibbo(int n)
{
    if (n <= 1)
        return n;
    return fibbo(n - 1) + fibbo(n - 2);
}
int fibboDpMemoization(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibboDpMemoization(n - 1, dp) + fibboDpMemoization(n - 2, dp);
}
int fibboDpTabulation(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibboDpTabulationSpaceOptmization(int n)
{
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; ++i)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << fibbo(n) << "\n";
    cout << fibboDpMemoization(n, dp) << "\n";
    cout << fibboDpTabulation(n, dp) << "\n";
    cout << fibboDpTabulationSpaceOptmization(n) << "\n";
    return 0;
}