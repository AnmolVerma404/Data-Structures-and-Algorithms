/*
This is similar to previous previous problems we solved, i.e. we will be given a 2D matrix and we need to find the minimum path sum from the 0th row to nth row and we can only travell in three direction down, down-right, and down-left and we can't choose more than one element from a row!!!

Approach
We need to visit all the path and find the minimum of them, therefore recursion solution must be there.
*/
#include <bits/stdc++.h>

using namespace std;

int minimumFallingPathSumRec(int i, int j, int n, vector<vector<int>> &v)
{
    if (j < 0 || j >= n)//Base case when index is out of bound
        return 1e6;

    if (i == 0)//If i is on zero that mean, we have to chose the jth column and return it
        return v[i][j];

    //Three direction recursion call therefore the time complexity is O(3^n)
    int up = v[i][j] + minimumFallingPathSumRec(i - 1, j, n, v);//For moving up call a recursion
    int upLeft = v[i][j] + minimumFallingPathSumRec(i - 1, j - 1, n, v);//For moving up left
    int upRight = v[i][j] + minimumFallingPathSumRec(i - 1, j + 1, n, v);//For moving up right

    return min(up, min(upLeft, upRight));//Find the minimum among the three direction we recursively call
}

int minimumFallingPathSumRecDP(int i, int j, int n, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
        return 1e6;

    if (i == 0)
        return v[i][j];

    if (dp[i][j] != -1)//If already calculated return the stored result
        return dp[i][j];

    int up = v[i][j] + minimumFallingPathSumRecDP(i - 1, j, n, v, dp);
    int upLeft = v[i][j] + minimumFallingPathSumRecDP(i - 1, j - 1, n, v, dp);
    int upRight = v[i][j] + minimumFallingPathSumRecDP(i - 1, j + 1, n, v, dp);

    return dp[i][j] = min(up, min(upLeft, upRight));//Store the calculated value, so it can in future
}

int minimumFallingPathSumTabulationDP(int n, vector<vector<int>> &v)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int j = 0; j < n; ++j)
    {
        //Base case, as we were returning the jth column when reaching 0th index
        //Therefore we need to do the same here, store it in dp[0]th row
        dp[0][j] = v[0][j];
    }

    for (int i = 1; i < n; ++i)//Start from the first row, as base case already solved
    {
        for (int j = 0; j < n; ++j)
        {
            //Calculate all the three direction, this is tabulation case therefore we don't need to recursively call
            //the function. Also take care of edge case, if upLeft and upRight are out of bound set there value to a big integer.
            int up = v[i][j] + dp[i - 1][j];
            int upLeft = 1e6, upRight = 1e6;

            if (j - 1 >= 0)
            {
                upLeft = v[i][j] + dp[i - 1][j - 1];
            }
            if (j + 1 < n)
            {
                upRight = v[i][j] + dp[i - 1][j + 1];
            }

            dp[i][j] = min(up, min(upLeft, upRight));//Find which direction gives the minimum for the jth column in the ith row
        }
    }

    int mn = INT_MAX;//Now the last row of DP vector store the minimum value from there reach, find out the minimum...
    for (auto &it : dp[n - 1])
    {
        mn = min(mn, it);
    }
    return mn;//Finally return the minimum value
}

int minimumFallingPathSumTabulationDPSpaceOptimization(int n, vector<vector<int>> &v)
{
    //If we observe the tabulation, we can see only last row in every iteration of column in being use.
    //So we just store that instead of storing in 2D DP
    vector<int> prev(n, 0);

    for (int j = 0; j < n; ++j)
    {
        prev[j] = v[0][j];
    }

    for (int i = 1; i < n; ++i)
    {
        vector<int> curr(n, 0);//For current row, so they can be interchanged later for the next row
        for (int j = 0; j < n; ++j)
        {
            int up = v[i][j] + prev[j];
            int upLeft = 1e6, upRight = 1e6;

            if (j - 1 >= 0)
            {
                upLeft = v[i][j] + prev[j - 1];
            }
            if (j + 1 < n)
            {
                upRight = v[i][j] + prev[j + 1];
            }

            curr[j] = min(up, min(upLeft, upRight));//Store the current row result in the curr vector
        }
        prev = curr;//set prev to curr, so in the next iteration prev can be used to calculate the next to the next row...
    }

    int mn = INT_MAX;
    for (auto &it : prev)
    {
        mn = min(mn, it);
    }
    return mn;//Return the minimum result
}

int main()
{
    vector<vector<int>> v = {{2, 1, 3},//Define a n*m matrix
                             {6, 5, 4},
                             {7, 8, 9}};
    int n = v.size();

    // Recursion TC - O(3^n) SC - O(n) + O(2n-2)[Stack Space]
    //As we need to find smallest one from a row, therefore we need to recursively call the function,
    //so we get the minimum for that jth element and compare it with previous minimum elements
    int mnRec = INT_MAX;
    for (int j = 0; j < n; ++j)
    {
        mnRec = min(mnRec, minimumFallingPathSumRec(n - 1, j, n, v));
    }
    cout << mnRec << "\n";//Print the minimum path sum

    // Recursion + DP i.e. Mamoization TC - O(n) SC - O(n*n) + O(2n-2)[Stack Space]
    int mnRecDP = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));//Create a 2D vector to store overlapping sub problems
    for (int j = 0; j < n; ++j)
    {
        //Similar to recursive to the same just make use DP vector also
        mnRecDP = min(mnRecDP, minimumFallingPathSumRecDP(n - 1, j, n, v, dp));
    }
    cout << mnRecDP << "\n";

    // Tabulation DP TC - O(n) SC - O(n*n) + O(2n-2)[Stack Space]
    cout << minimumFallingPathSumTabulationDP(n, v) << "\n";

    // Tabulation DP TC - O(n) SC - O(n*n) + O(2n-2)[Stack Space]
    cout << minimumFallingPathSumTabulationDPSpaceOptimization(n, v) << "\n";

    return 0;
}