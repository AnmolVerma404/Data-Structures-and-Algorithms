/*
In this problem we will be given a trangular 2D vector, and we have to find the minimum path from 0th row to last(nth) row?
Also it's given at a point (i,j) we can only go to the (i+1,j) and (i+1,j+1) index.

Approach
We can observe that every path will include the 0th row but we have choice here to chose between any jth index in last(ith row).
So instead of going from nth index we will start from 0 and find all the possible paths from recursion.
*/
#include <bits/stdc++.h>

using namespace std;

int triangleRec(int i, int j, int n, vector<vector<int>> &v)
{
    if (i == n - 1) // This is the base case if index is on the last(n-1) row then return that row'th jth value
        return v[i][j];
    int down = v[i][j] + triangleRec(i + 1, j, n, v);          // As we can go down, therefore increase index be one
    int downRight = v[i][j] + triangleRec(i + 1, j + 1, n, v); // Also increase both index by 1 to go down right.
    // There will not be any edge case as downRight will always be there for a 'p' size row as the next row will be p+1 size
    return min(down, downRight); // Finally return the minimum of the down and downRight path
}

int triangleMemoizationDP(int i, int j, int n, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return v[i][j];
    if (dp[i][j] != -1) // If the current row and column is calculated, you can return it no need of recalculating it again
        return dp[i][j];
    int down = v[i][j] + triangleMemoizationDP(i + 1, j, n, v, dp);
    int downRight = v[i][j] + triangleMemoizationDP(i + 1, j + 1, n, v, dp);
    return dp[i][j] = min(down, downRight); // Store the minimum path in dp[i][j] for future use
}

int triangleTabulationDP(int n, vector<vector<int>> &v)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // As in the recursive solution we traverse from 0th row to nth row, therefor in here we will go from nth to 0th
    // Therefore we have to fill up the nth row in the dp and that will be equal to the input vector v, as it's the minimum at the nth row.
    for (int i = 0; i < n; ++i)
    {
        dp[n - 1][i] = v[n - 1][i];
    }
    for (int i = n - 2; i >= 0; --i)//From last second row to first for
    {
        for (int j = i; j >= 0; --j)//As row size keep changing -> 0,1,2,3 -> 0,1,2 -> 0,1 -> 0 
        {
            //Similar to dp recursion
            int down = v[i][j] + dp[i + 1][j];//Calculate down
            int downRight = v[i][j] + dp[i + 1][j + 1];//Calculate downRight
            dp[i][j] = min(down, downRight);//Store in the ith row and jth column
        }
    }
    return dp[0][0];//Finally return the 0,0 which will store the minimum cost path
}

int triangleTabulationSpaceOptimizationDP(int n, vector<vector<int>> &v)
{
    //Prev will store the last row data, and curr will store current row data then just put prev = curr
    vector<int> prev(n, 0), curr(n, 0);
    for (int i = 0; i < n; ++i)
    {
        prev[i] = v[n - 1][i];//Base case
    }
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i; j >= 0; --j)
        {
            //Prev will inculde the previous iteration data
            int down = v[i][j] + prev[j];
            int downRight = v[i][j] + prev[j + 1];
            curr[j] = min(down, downRight);//Save it in curr of jth index
        }
        prev = curr;//Put prev = curr for next iteration use
    }
    return prev[0];//Now prev will store the result therefore return 0th index
}

int main()
{
    vector<vector<int>> v = {// Define corrent input 2D triangular vector
                             {1},
                             {2, 3},
                             {3, 6, 7},
                             {8, 9, 6, 10}};
    int n = v.size(); // Size of input vector
    // Here m = (n*(n-1))/2, as in the vector on the 0th row we have 1 size vector and in the nth row we have (n-1) size vector
    cout << triangleRec(0, 0, n, v) << "\n"; // TC - O(2^(n*m)) SC - O(n-1 + m-1)[stack space]

    vector<vector<int>> dp(n, vector<int>(n, -1)); // As we cant always define a n*m space vector therefor we define a n*n vector
    // A lot of space will be wasted
    cout << triangleMemoizationDP(0, 0, n, v, dp) << "\n"; // TC - O(n*m) SC - O(n-1 + m-1)[stack space] + O(n*n)[dp vector size]

    cout << triangleTabulationDP(n, v) << "\n";// TC - O(n*m) SC - O(n*m)[dp vector size]
    cout << triangleTabulationSpaceOptimizationDP(n, v) << "\n";

    return 0;
}