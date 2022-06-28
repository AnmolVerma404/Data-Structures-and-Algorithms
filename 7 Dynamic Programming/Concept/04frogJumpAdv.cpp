/*
This is follow up of the last problem, only thing change is the frog can jump k building, and you need to find out the total minimum height the frog should jump to reach nth building.
Time Complexity - O(N*K) Space Complexity - O(N)[DP array size] + O(N)[Stack Space] 
*/
#include <bits/stdc++.h>

using namespace std;

int KfrogJumpDPMemoization(int n, int k, vector<int> &wt, vector<int> &dp)
{
    if (n == 0)//Base case, if n is zero i.e. we are at the starting position therefore no need to jump hence 0 height to jump
        return dp[n] = 0;
    if (dp[n] != -1)
        return dp[n];
    int mn = INT_MAX;//We have taken the minimum variable to INT_MAX as we need to find the minimum among k steps
    for (int j = 1; j <= k; ++j)
    {
        if (n - j < 0)//If n-j is less than zero, as it's not possible so break the for loop, as going further is of no use.
            break;
        int jump = KfrogJumpDPMemoization(n - j, k, wt, dp) + abs(wt[n] - wt[n - j]);//Recursively call function and add the absolute height in it
        mn = min(mn, jump);//Also keep the track of the minimum element
    }
    return dp[n] = mn;//Finally return the minimum of the element and store it in dp[n]
}

int main()
{
    vector<int> wt = {30, 10, 60, 10, 60, 50}; // Weight/Height of building
    int n = wt.size();
    int k = 2;
    vector<int> dp(n, -1);                                   // Here we do not need n+1 size dp -> as in fibonacci we need to find the nth fibo num but here the size of wt vector in n-1 therefor need not to create an extra space.
    cout << KfrogJumpDPMemoization(n - 1, k, wt, dp) << "\n";//Time Complexity - O(N*K) Space Complexity - O(N)[DP array size] + O(N)[Stack Space] 

    return 0;
}