/*
Problem Statement - https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
Given -  A wt/height array which in which the ith element gives the information about the height frog needs to jump from it's current building. Frog can jump from a building i to i + 1 or i + 2.
The difference of two buildng is the height that frog need to jump.
Your task is to return the minimum height frog need to jump?

Approach - As we can read and understand from the solution i + 1 and i + 2 it's kind of same as fibonacci, but the twist is we need not to find the number of way's here we need the minimum result.

So why not use gready approach here?
Eg - 30  10  60  10  60  50
     0   20  50  50  50  10 (iff all are i-1 jump(only one case))(If frog jump from 2->4 height will be 0)
     0   1   2   3   4   5
If we apply gready algo here the path will be :- 0->1->3->5 and the result is 0+10+0+40 = 50
But the real minimum path is:- 0->2->4->5 and the result is 0+30+0+10 = 40
So we can't go gready here, i.e. we have to visit all the path therefor we can do recursion and in this problem there are overlapping subproblem therefor, after we will apply memoization and  then tabulation then space optimization if it's possible.
*/
#include <bits/stdc++.h>

using namespace std;

int frogJumpRecursion(int n, vector<int> &wt)//Simple recursion code
{
    if (n == 0)//Base case, if n is zero i.e. we are at the starting position therefore no need to jump hence 0 height to jump
        return 0;
    int left = frogJumpRecursion(n - 1, wt) + abs(wt[n] - wt[n - 1]);
    int right = INT_MAX;//If n == 1 or less that 1, as 0 is already checked
    if (n > 1)
        right = frogJumpRecursion(n - 2, wt) + abs(wt[n] - wt[n - 2]);//If n is greater than one then go further deep in the recursion tree.
    return min(left, right);//Return minimum of the left and right path **Here left path is of next(i+1) building and the right path is of next to next(i+2) building.
}

int frogJumpDPMemoization(int n, vector<int> &wt, vector<int> &dp)
{
    if (n == 0)
        return dp[n] = 0;//Store the base case in dp[0]~dp[n] as n is zero in this call
    if (dp[n] != -1)//If we have already calculated the dp[n] no need to recall it, we can used the calculated data from dp vector
        return dp[n];
    int left = frogJumpDPMemoization(n - 1, wt, dp) + abs(wt[n] - wt[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = frogJumpDPMemoization(n - 2, wt, dp) + abs(wt[n] - wt[n - 2]);
    return dp[n] = min(left, right);//For the nth call store the result in dp[n]
}

int frogJumpDPTabulation(int n, vector<int> &wt, vector<int> &dp)
{
    //Instead of recursion convert the above recursive function to iterative, so no stack memory is used
    dp[0] = 0;
    // dp[1] = dp[0] + abs(wt[1] - wt[0]);//Or write the ternary condition//Using this is much better for TC as in for loop we need to check the condition for n times!!!
    for (int i = 1; i < n; ++i)
    {
        dp[i] = min(dp[i - 1] + abs(wt[i] - wt[i - 1]), i == 1 ? INT_MAX : dp[i - 2] + abs(wt[i] - wt[i - 2]));
    }
    return dp[n - 1];//Finally return dp[n-1].
}

int frogJumpDPTabulationSpaceOptmization(int n, vector<int> &wt)
{
    //From all the were to here, we can observe that we need only the information about the last two building height therefore we need not to have a full n size dp array
    int prev2 = 0;//Set the height of the current building to 0 as the frog is currently standing on it
    int prev1 = abs(wt[1] - wt[0]);//The next height will be the diff of height of the first and the current building
    for (int i = 2; i < n; ++i)
    {
        int curr = min(prev1 + abs(wt[i] - wt[i - 1]), prev2 + abs(wt[i] - wt[i - 2]));//Find which is minimum among 
        prev2 = prev1;//Set the prev2 to prev1
        prev1 = curr;//And the prev1 toc curr
    }
    return prev1;//As prev1 will be curr and it's for n-1 therefore return prev1
}

int main()
{
    vector<int> wt = {30, 10, 60, 10, 60, 50};//Weight/Height of building
    int n = wt.size();
    vector<int> dp(n, -1);//Here we do not need n+1 size dp -> as in fibonacci we need to find the nth fibo num but here the size of wt vector in n-1 therefor need not to create an extra space.
    cout << frogJumpRecursion(n - 1, wt) << "\n";//TC - O(2^n), SC - O(N)[Stack space]
    cout << frogJumpDPMemoization(n - 1, wt, dp) << "\n";//TC - O(n), SC - O(n)[DP vector size] + O(N)[Stack space]
    dp.resize(n, -1);//As dp vector is filled from last function call due to reference call, therefor we need to empty and resize the dp to n and values to -1
    cout << frogJumpDPTabulation(n, wt, dp) << "\n";//TC - O(n), SC - O(n)[DP vector size]
    cout << frogJumpDPTabulationSpaceOptmization(n, wt) << "\n";//TC - O(n), SC - O(1)
    return 0;
}