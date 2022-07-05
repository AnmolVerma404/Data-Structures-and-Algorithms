/*
In this problem we will be given 2 integer input n and m, here n is the lenght of row, and m is the length of column of a 2D matrix we need to find all the unique path that are available from starting position i.e. 0,0 to the end position i.e. n-1,m-1. Also it's given that you can only move down and right!!!
There can be an additional problem which is base on the same logic and almost same code, in which we will be given a grid in which g[i][j] can be 0 and -1, if it's -1 we can't follow that path, and if 0 then we can. We just need to add an extra conditional statement i.e. if(g[n][m]==-1) return 0 will solve the code!!!

Approach 
As we need to find all the possible path, therefore first thing in our mind should be recursion.
Now followed in the code!!!
*/
#include <bits/stdc++.h>

using namespace std;

int gridUniquePathRecursion(int n, int m)
{
    /*
    This is the base condition after recursion calls if we were on right path, we will reach our 
    destination i.e. 0,0 so we can say it was a valid path and we will return 1, as one path is
    possible from the executed steps.
    */
    if (n == 0 && m == 0)
    {
        return 1;
    }
    if (n < 0 || m < 0)//If n or m goes less than zero that mean it's not a valid path, therefore retuern 0, so if it's either up or left it's sum will be only the valid path
        return 0;
    //As we can either move up or down therefore we will try both path from our current position in matrix
    int up = gridUniquePathRecursion(n - 1, m);//For up decrement the nth row index by 1, and make a recursion call for it
    int left = gridUniquePathRecursion(n, m - 1);//And the another direction is left, and for that we just need to move m index by one which is the column index
    return up + left;//Finally return the sum of up and left, as it will sum up all the possible paths
}

int gridUniquePathMamoizationDP(int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
    {
        return dp[n][m] = 1;//Always while returning save it in dp vector
    }
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)//If the nth and mth point is already visited then no need to recompute, just return the previously calculated result
        return dp[n][m];
    int up = gridUniquePathMamoizationDP(n - 1, m, dp);
    int left = gridUniquePathMamoizationDP(n, m - 1, dp);
    return dp[n][m] = up + left;//Save the nth and mth result, which define number of possible path from n,m to 0,0. Now they can be reused later.
}

int gridUniquePathTabulationDP(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));//Define a dp vector of size n*m
    dp[0][0] = 1;//Base case when n == 0 and m == 0 return , therefore here we store 1
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0)//Base base already stored
                continue;
            int up = 0, left = 0;
            if (i != 0)//Edge case, if i is zero we cant go negative therefor continue
                up = dp[i - 1][j];
            if (j != 0)//Edge case, if j is zero we cant go negative therefor continue
                left = dp[i][j - 1];
            dp[i][j] = up + left;//Now for the ith and jth index sum the up and left and you will get the paths
        }
    }
    return dp[n - 1][m - 1];//Finally return the nth-1 and mth -1 as it stores grids unique paths
}

int gridUniquePathTabulationSpaceOptimizationDP(int n, int m)
{
    vector<int> prev(m, 0);//To store the previous.
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp(m, 0);//This will store current row, we need to get the j-1th unique path
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0){//Base case
                temp[i] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)//Edge case, if i > 0 that means we cam visit previous row without index out of bound error
                up = prev[i - 1];//Save in up, therefore take the stored result from previous array
            if (j > 0)//Edge case, if j > 0 that means we cam visit current row without index out of bound error
                left = temp[j - 1];//Save in left, therefore take the stored result from current array, as this was calculated in the last jth iteration(2nd for loop)
            temp[j] = up + left;//Add up both paths
        }
        prev = temp;//Now the prev becomes current
    }
    return prev[m - 1];//Finally return prev[m-1] which will store the matrix unique path
}

int main()
{
    int n = 3, m = 3;//Input // n-> row, m -> column

    cout << gridUniquePathRecursion(n - 1, m - 1) << "\n";//TC - O(2^(n*m)) SC - O(n-1 + m-1)[stack space] + O(1)[Auxiliary space]

    /*
    As the above approach was taking exponential time which is not good at all!!!. Therefore we can observe that
    there are overlapping subproblems in this problem, i.e. at any point matrix[n][m] we found how many ways are possible from 
    that point, and that mean if another recursion call come and visit matrix[n][m] the result will be the same, therefore we
    can store the result in n*m array
    */
    vector<vector<int>> dp(n, vector<int>(m, -1));//So define a n*m vector
    cout << gridUniquePathMamoizationDP(n - 1, m - 1, dp) << "\n";//TC - O(n*m) SC - O(n-1 + m-1)[stack space] + O(n*m)[dp array space]

    /*
    To get rid of stack space we need to convert the solution into tabulation formate, i.e. instead of making recursively
    call from top to down, we will build our way from bottom to up!!!
    */
    cout << gridUniquePathTabulationDP(n, m) << "\n";//TC - O(n*m) SC - O(n*m)[dp vector space]

    //From the solution we can observe that, at a iteration we only need current and last matrix row. Therefore we can further reduce the space complexity
    cout << gridUniquePathTabulationSpaceOptimizationDP(n, m) << "\n";//TC - O(n*m) SC - O(m)[for storing current and prev row]

    return 0;
}