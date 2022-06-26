/*
Problem Link https://leetcode.com/problems/climbing-stairs/
In this problem we are told to find the number or ways in which we can climb n stairs.
The condition is we can either climb 1 stair or 2 at a time.
Print the number or ways?

🔴 Approach for recursion solution
As we can see from the problem we need to find the all ways, and this can be done using recursion
For n let n = 3 : left is always one step and right is two step
                        3
                      /  \
                     2    1
                   /  \  /  \
                  1   0 0   -1
                /  \
               0   -1
We can see number of 0 are 3 there only 3 way's in which we can reach to the nth stair

From the recursion tree above(after drawing by yourself!!!) we can figure out the the base case is when n hit's 0, if it does we can say this is a correct way, as we have moved to all the n steps.
Therefor if n hit's 0 return 1, i.e. 1 way

Also if n < 0 that mean it's not a corrent way as we can't reach the nth stair by goint in the same way, therefor if n<0 return 0, i.e. 0 way.

Not how to sum up the way's as n == 1 will return 1 from left and 0 from right therefor if we sum left and right we will get the total number of ways if n was 1, similarly for 2 left will return 1 and right will also return 1 then sum up them we got 2 as the result.

Complexity Analysis
Time - As every recursion will call 2 sub recursion for n times therefore TC : O(2^N)
Space - Auxilary will be O(1) and input space will be O(1) but stack space will be O(n) therefor : SC - O(N)

🔴 Approach DP + memoization + Tabulation + Space Optimization(Same as fibonacci with an extra edge case!!!)
From the recursion tree we can see 0 return one way, therefor 1 return one way and 2 return 2 way because of left and right, and 1 also appears in 3's right step and there we recalculate it, and this type of problem is an overlapping subproblem.
So we can store the resuly
How to store?
We can take a array of size n+1(as it's 0 base indexing) and store the result. Afcourse we have to define some base case i.e. if n == 0 return 1 and if n < 0 return 0(previously discussed).
We can see it's looking as same as fibonacci Number problem and that's right!!!

Time Complixity of DP approach is O(N) as we are not recalculating overlaping subproblems
Space Compixity O(N) from DP array and O(N) from stack space
*/
#include <bits/stdc++.h>

using namespace std;

int climbStairRecursion(int n)//TC : O(2^N) ; SC - O(N)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    // OR
    //  int left = climbStair(n-1);//Left mean going 1 step
    //  int right = climbStair(n-2);//Right mean going 2 steps
    return climbStairRecursion(n - 1) + climbStairRecursion(n - 2); // OR return left + right//At the end sum up the left and right
}

int climbStairDP(int n, vector<int> &dp)//TC : O(N) ; SC - O(N)
{
    if (n == 0)//Iff 0 i.e. we have reached 0th step therefor are way is correct
        return dp[n] = 1;//Return 1 as it'a a corrent way and store it in dp array
    if (n < 0)//If n < 0 i.e. not a correct way, therefor return 0
        return 0;
    if (dp[n] != -1)// Already calculated//Overlapping subproblem
        return dp[n];//Return dp[n] which is already calculated
    return dp[n] = climbStairDP(n - 1, dp) + climbStairDP(n - 2, dp);//same as fibonacci code
}

int main()
{
    int n = 3;//define step
    vector<int> dp(n + 1, -1);//DP array(vector more formally)

    cout << climbStairRecursion(n) << "\n";

    cout << climbStairDP(n, dp) << "\n";

    return 0;
}