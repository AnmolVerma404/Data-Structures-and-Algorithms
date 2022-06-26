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

int fibbo(int n)//This is the brute force algorithm, where for n number 2^n calls are made, which is really bad for time
//Eg - 5 calls 4 and 3 then 3 -> 2 and 1 then 2 -> 1 and 0, then evaluate for 2, 3, when 4 calls it recalculate for 3 and 2 which is already been calculated. From this type of situation we can assume we can take help of DP here. And save the pre-computed value and reuse it.
{
    if (n <= 1)
        return n;
    return fibbo(n - 1) + fibbo(n - 2);
}
int fibboDpMemoization(int n, vector<int> &dp)//Therefor we use a dp array/list/vector of n+1 size number = n
//Now we will store computed value in a dp array.
//As this is memoization case therefore we will traverse from n to 1/0(not necessary always)
{
    if (n <= 1)
        return dp[n] = n;//Base case
    if (dp[n] != -1)//Check if dp[n] == -1 or not if it's -1 then we know we are calculating it for the first time, therefore make the recursion call
        return dp[n];
    return dp[n] = fibboDpMemoization(n - 1, dp) + fibboDpMemoization(n - 2, dp);//Same as the bruteforce recursion but here we are storing the result in dp array
}
int fibboDpTabulation(int n, vector<int> &dp)//In the Memoization we were following Top-Down approach here we will follow Bottom-Up Approach, in which we build our solution from the base case move our way up to the final solution
{
    //Base case
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];//Logic is same as the recursion, but here we are not using the stack memory
    }
    return dp[n];//Finally return dp[n]
}

int fibboDpTabulationSpaceOptmization(int n)//From above solution we can see, the only need is or dp[i-1] and dp[i-2].
//Which can be easily stored in two variable instead of using a array dp
{
    //Base case
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; ++i)
    {
        int curr = prev1 + prev2;//same as dp[i-1] + dp[i-2]
        prev2 = prev1;//Set the dp[i-2]/prev2 to dp[i-1]/prev1 so in next step it's can be used
        prev1 = curr;//Set the current dp[i] to dp[i-1] for future use
    }
    return prev1;//Finally retun prev1 as it will be updated to current in the last iteration call
}
int main()
{
    int n = 5;//n is the fibonacci number we need to find out
    vector<int> dp(n + 1, -1);//Define a vector dp of n+1 size and set it's value to -1.(-1 mean dp[i] is not calculated before)
    cout << fibbo(n) << "\n";
    cout << fibboDpMemoization(n, dp) << "\n";
    cout << fibboDpTabulation(n, dp) << "\n";
    cout << fibboDpTabulationSpaceOptmization(n) << "\n";
    return 0;
}