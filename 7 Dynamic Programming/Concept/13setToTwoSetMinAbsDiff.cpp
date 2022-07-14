/*
Problem Link - https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
Same as previous, new approach in main function
Only Tabulation Written
*/
#include <bits/stdc++.h>

using namespace std;

void targetSumTabulationDP(int n, int t, vector<int> &v, vector<vector<int>> &dp)
{

    for (int i = 0; i < n; ++i)
        dp[i][0] = true;

    dp[0][v[0]] = true;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= t; ++j)
        {

            bool notTake = dp[i - 1][j];
            bool take = false;
            if (j >= v[i])
            {
                take = dp[i - 1][j - v[i]];
            }
            dp[i][j] = notTake || take;
        }
    }
}

int main()
{
    //It's hard to observe that how this problem relate to last
    //In the last problem we were saving boolean value that if at a row i,t can be successful
    //We we know at a target if it's possible
    //Therefor if we sum up this problem array, and set the target to it
    //We will have n*(sum+1) size array, also at the (n-1)th index we will have if the sum is possible or not
    //And we can take the difference of totalSum and sum of ith from i = 0 to i<totalSum
    //And can get the minimum abs difference sum
    vector<int> v = {1, 2, 3, 4};
    int n = v.size();
    int totalSum = 0;
    for (auto &it : v)
        totalSum += it;//Sum up 
    int t = totalSum;//Set t = totalSum and the prev tabluation way is same

    vector<vector<int>> dp(n, vector<int>(t + 1, 0));//Set to t+1, where t = totalSum

    targetSumTabulationDP(n, t, v, dp);

    int mn = 1e9;
    for (int s1 = 0; s1 < totalSum; ++s1)
    {
        if (dp[n - 1][s1] == true)
        {
            mn = min(mn, abs((totalSum - s1) - s1));//Find the minimum
        }
    }

    cout << mn << "\n";//Print the minimum abs difference sum

    return 0;
}