/*

*/
#include <bits/stdc++.h>

using namespace std;

int targetSumRec(int i, int t, vector<int> &v)
{
    if (t == 0) // If target is 0 then we can say, there is a subsequence is the vector v, that will reach target
        return 1;
    // Base case
    if (i == 0) // If index is 0, -ve idx will give out of bound error, therefore check if v[i] == t if not return the bool exp
        return v[i] == t;

    bool notTake = targetSumRec(i - 1, t, v); // Skip the target and decrement index
    bool take = 0;
    if (t >= v[i]) // If target is greater than v[i], then take the recursion in consideration
    {
        take = targetSumRec(i - 1, t - v[i], v);
    }
    return notTake || take; // Return if any of the recursion is giving result
}

int targetSumRecMemoizationDP(int i, int t, vector<int> &v, vector<vector<int>> &dp)
{
    if (t == 0)
        return 1;
    if (i == 0)
        return v[i] == t;
    if (dp[i][t] != -1) // If already calculated return the result.
        return dp[i][t];
    bool notTake = targetSumRecMemoizationDP(i - 1, t, v, dp);
    bool take = 0;
    if (t >= v[i])
    {
        take = targetSumRecMemoizationDP(i - 1, t - v[i], v, dp);
    }
    return dp[i][t] = notTake || take; // Otherwise save it in the dp vector
}

int targetSumTabulationDP(int n, int t, vector<int> &v)
{
    vector<vector<bool>> dp(n, vector<bool>(t + 1, false));
    // In the recursion for every t == 0 we were returning true
    //Therefore set dp for every i and t=0 to true
    for (int i = 0; i < n; ++i)
        dp[i][0] = true;
    //Also if i == 0, we were returning if v[i] == t, therefore assign true for dp[0][v[0]]
    //This will be true set true when v[0](i.e.  dp[0][2] to true, for current vector in main function)
    dp[0][v[0]] = true;
    for (int i = 1; i < n; ++i)//Iterate from 1 as base case is calculated
    {
        for (int j = 1; j <= t; ++j)//Iterate from 1 as base case for t also have been taken care of.
        {
            //Same as recursion take and don't take the current jth value 
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (j >= v[i])
            {
                take = dp[i - 1][j - v[i]];
            }
            dp[i][j] = notTake || take;//Save for next ith iteration
        }
    }
    return dp[n - 1][t];//Return the result which was stored in the end because of bottom up approach
}

int targetSumTabulationSpaceOptimizationDP(int n, int t, vector<int> &v)
{
    //In the previous iteration code we can see, we were only accessing the (i-1)th row
    //Therefore we do not need a 2D vector
    //Just define two 1D vector the store the current and the precious calculated elements
    vector<bool> prev(t + 1, false);
    vector<bool> curr(t + 1, false);
    prev[0] = true, curr[0] = true;//Base case for t
    prev[v[0]] = true;//Base case for i
    //As loops are starting from 1, base case value will not be disturbed
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= t; ++j)
        {
            //Use the previous result
            bool notTake = prev[j];
            bool take = false;
            if (j >= v[i])
            {
                take = prev[j - v[i]];
            }
            //Store the calculated result in the current vector
            curr[j] = notTake || take;
        }
        //Set curr to prev, so it can be used in the next iteration
        prev = curr;
    }
    return prev[t];
}

int main()
{
    vector<int> v = {2, 3, 1, 1};
    int t = 4; // Target
    int n = v.size();

    cout << targetSumRec(n - 1, t, v) << "\n"; // TC - O(2^(n*t)) SC - O(n+t-1)[Stack space]

    // How to know that we have to use 2D dp vector
    // As we know in every iteration that variable that is changing is i and t, therefore
    // We need to store every (i,t)th result in some vector, and the only possibility is to use 2D vector
    vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    cout << targetSumRecMemoizationDP(n - 1, t, v, dp) << "\n"; // TC - O(n*t) SC - O(n+t-1)[Stack space] O(n*t)[2D DP vector space]

    cout << targetSumTabulationDP(n, t, v) << "\n"; // TC - O(n*t) SC - O(n*t)[2D DP vector space]

    cout << targetSumTabulationSpaceOptimizationDP(n, t, v) << "\n"; // TC - O(n*t) SC - O(t)[1D DP vector]

    return 0;
}