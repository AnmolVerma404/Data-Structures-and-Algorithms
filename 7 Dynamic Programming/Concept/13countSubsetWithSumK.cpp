/*
Problem Link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

Find all the possible subset of an array v and print the number of subsets those are having sum equals to target


Approach - To find all the possible subsets we need to go for recursion, greedy will not be applicable 
is this scenario...

This is similar to the questions we have done before and the logic is same, to take and not take elements
from the given array
*/

#include <bits/stdc++.h>

using namespace std;

int subSetSumKRecursion(int i, int n, int t, vector<int> &v)
{
    if (t == 0)// If the target is zero at any point no need to go further anymore
        return 1;//Just return 1, as this is the correct way
    if (i == 0)//Base case: If we are at the index 0, we have to stop
    {
        if (v[i] == t)//If the 0th index is equal to the target
        // i.e. v[0] - t is zero, therefore return 1
        {
            return 1;
        }
        return 0;//else return 0
    }
    //As we need to find all the subset, we can do that by keeping track of target 't'
    //As a point take and dont take the value present at the current index i.e. 'i'
    int take = subSetSumKRecursion(i - 1, n, t - v[i], v);
    int notTake = subSetSumKRecursion(i - 1, n, t, v);

    return take + notTake;//Finally return the take and notTake as they will contain the number of possible way
}

int subSetSumKRecursionDP(int i, int n, int t, vector<int> &v, vector<vector<int>> &dp)
{
    if (t == 0)
        return 1;
    if (i == 0)
    {
        if (v[i] == t)
        {
            return 1;
        }
        return 0;
    }

    if (dp[i][t] != -1)// If already calculated, no need to recompute this overlapping subproblem again
        return dp[i][t];

    int take = subSetSumKRecursionDP(i - 1, n, t - v[i], v, dp);
    int notTake = subSetSumKRecursionDP(i - 1, n, t, v, dp);

    return dp[i][t] = take + notTake;// Save the calculated result in the dp arrray
}

int subSetSumKTabulationDP(int n, int t, vector<int> &v)
{
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));//As we will be adding up, default value of DP vector should be 0
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 1;//Base case one: And any index return 1 if t is zero
        //As dp[i][j] i is the index of v and j is the sum, and here the sum is 0
    }

    if (v[0] <= t)//2nd Base case
        dp[0][v[0]] = 1;//If at index 0, set the value equal to the target to zero

    for (int i = 1; i < n; ++i)//from 1 to n, as base case already calculated
    {
        for (int j = 0; j <= t; ++j)//from 0 to t, as dp[i].size == k+1 and 0 because, we will be using 
        //Previous index value, so for current it will always be one, dp[i][0]
        //Difference can be seen in the space optimization code
        {
            int take = v[i] <= j ? take = dp[i - 1][j - v[i]] : 0;//Out of bound case
            int notTake = dp[i - 1][j];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][t];//Finallt return the result
}

int subSetSunkTabulationSpaceOptimization(int n, int t, vector<int> &v)
{
    //As we saw from previous code, in iteration we only need the last row information
    // Therefore we can store data in a previous and current array
    vector<int> prev(t + 1, 0);
    vector<int> curr(t + 1, 0);
    prev[0] = 1;//Base case
    if (v[0] <= t)//Edge case:
        prev[v[0]] = 1;//At 0th index set 1 if v[0] is <= target

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= t; ++j)
        {
            int take = v[i] <= j ? take = prev[j - v[i]] : 0;
            int notTake = prev[j];
            curr[j] = take + notTake;
        }
        prev = curr;//After every iteration set the prev to curr
    }
    return prev[t];//Finally return the result
}

int main()
{
    vector<int> v = {1, 2, 2, 3};//+ve index vector, if negative given in question recursive will work, and for dp use map
    //As the 2nd dimention of DP array is of size k+1, where k is sum, and in some problems sum can be given negative
    //Therefore use map in that case for storing -ve value as a key
    int n = v.size();
    int t = 3;//Target

    cout << subSetSumKRecursion(n - 1, n, t, v) << "\n";//TC - O(2^n) SC - O(n)[Input space] + O(1)[Auxilliary space] + O(n)[stack space]

    //How to know what should be the dimention of the array/vector DP
    // There is a simple trick, or more of an logical answer
    // As we are recusively calling function there are only two of the variable that are changing
    // And the are the index i and the target t
    // For any index there can be multiple target value
    //Therefore we cant store it in a 1D dp
    //As for a index i, there may be k+1 possible values
    // So we come to the conlusion to use 2D DP vector, of size n*(t+1)
    vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    cout << subSetSumKRecursionDP(n - 1, n, t, v, dp) << "\n";//TC - O(n*t) SC - O(n)[Input space] + O(1)[Auxilliary space] + O(n)[stack space]

    cout << subSetSumKTabulationDP(n, t, v) << "\n";//TC - O(n*t) SC - O(n)[Input space] + O(n*t)[Auxilliary space]

    cout << subSetSunkTabulationSpaceOptimization(n, t, v) << "\n";//TC - O(n*t) SC - O(n)[Input space] + O(t)[Auxilliary space]

    return 0;
}