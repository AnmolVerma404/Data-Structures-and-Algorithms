/*
Problem - https://leetcode.com/problems/cherry-pickup-ii/
In the problem statement we will be given a 2D array, and starting index of at two points,
your job is to travell from 0th row to the n-1th column and pick up cherry at a position.
Find out what is the maximum cherry both of them can pick up.
And the direction they can more are down,down left, and down right

Approach
Here also we need to find for all path i.e. in 9 direction(as for 1 direction by 1st person we will be having 3 different direction of the person 2)
From here we can observe the direction at j1th and j2th poition are 3x3 and j1,j2<m where m is the column length
And we will also having row index, as there will be overlapping subproblems, so we need a DP vector
But not 2D, we need 3D as there are m*m possibilities for m size row.
So dp size will by n*m*m

*/
#include <bits/stdc++.h>

using namespace std;

int cherryPickupRec(int i, int j1, int j2, int n, int m, vector<vector<int>> &v)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)//As a base edge case, we need to check both point out of bound conditions
        return -1e7;
    if (i == n - 1)//If I is at the last row
    {
        //Chack If both j1 and j2 are at same point then return them once, as only one of them can pick up cherry
        if (j1 == j2)
            return v[i][j1];
        else
            return v[i][j1] + v[i][j2];//If different point, so they can pick up there own cherry
    }
    //As there are 9 possible direction at 1 level of recursion
    //As at a point j1, there can be three different j2 direction, and there are 3 j1 therefor 3*3 = 9
    //Direction - 
    // (j1 - 1,j2 - 1), (j1 - 1,j2 + 0), (j1 - 1,j2 + 1), 
    // (j1 + 0,j2 - 1), (j1 + 0,j2 + 0), (j1 + 0,j2 + 1), 
    // (j1 + 1,j2 - 1), (j1 + 1,j2 + 0), (j1 + 1,j2 + 1)
    //There is a pattern in the direction i,e, -1, 0, 1 therefor run 2 for loop in it!!!.
    int mx = -1e7;//We need to find the maximum amont the 9 direction, so declare mx and set to verry small negative value, but not INT_MIN as it will overflow if negetive will be addded in it.
    for (int d1 = -1; d1 <= 1; ++d1)
    {
        for (int d2 = -1; d2 <= 1; ++d2)
        {
            int val = 0;
            //Similar to the base case
            if (j1 == j2)//If same location add, only one will pickup the cherry
            {
                val = v[i][j1];
            }
            else
            {
                val = v[i][j1] + v[i][j2];//Else both will pick up it.
            }
            val += cherryPickupRec(i + 1, j1 + d1, j2 + d2, n, m, v);//Recursively call for the next row, and find the result till the base case where i == n-1
            mx = max(mx, val);//Find the max among the 9 direction
        }
    }
    return mx;//Return the max that we calculated
}

int cherryPickupMemoizationDP(int i, int j1, int j2, int n, int m, vector<vector<int>> &v, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e7;
    if (i == n - 1)
    {
        if (j1 == j2)
            return v[i][j1];
        else
            return v[i][j1] + v[i][j2];
    }
    if (dp[i][j1][j2] != -1)//If it's already calculated the just return the overlapped result!!!
        return dp[i][j1][j2];
    int mx = -1e7;
    for (int d1 = -1; d1 <= 1; ++d1)
    {
        for (int d2 = -1; d2 <= 1; ++d2)
        {
            int val = 0;
            if (j1 == j2)
            {
                val = v[i][j1];
            }
            else
            {
                val = v[i][j1] + v[i][j2];
            }
            val += cherryPickupMemoizationDP(i + 1, j1 + d1, j2 + d2, n, m, v, dp);
            mx = max(mx, val);
        }
    }
    return dp[i][j1][j2] = mx;//Store the max in the current location, so it can be reused later
}

int cherryPickupTabulationDP(int n, int m, vector<vector<int>> &v)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    //Base case, for all the 9 direction if i is at the last row then fill the 3D DP with all the 9 direction
    for (int j1 = 0; j1 < m; ++j1)
    {
        for (int j2 = 0; j2 < m; ++j2)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = v[n - 1][j1];
            else
                dp[n - 1][j1][j2] = v[n - 1][j1] + v[n - 1][j2];
        }
    }
    //There will be 3 for looops nested as we, have n*m*m dp, also we need to find the maximum among 9 direction
    //Therefore in the last we need two constant TC nested for loops!!!
    for (int i = n - 2; i >= 0; --i)//As last row is already evaluated, so start wilth n-2
    {
        for (int j1 = 0; j1 < m; ++j1)
        {
            for (int j2 = 0; j2 < m; ++j2)
            {
                int mx = -1e7;//Same logic of recursion two nested O(1) for loops
                for (int d1 = -1; d1 <= 1; ++d1)
                {
                    for (int d2 = -1; d2 <= 1; ++d2)
                    {
                        int val = 0;
                        if (j1 == j2)
                        {
                            val = v[i][j1];
                        }
                        else
                        {
                            val = v[i][j1] + v[i][j2];
                        }
                        if (j1 + d1 >= 0 && j1 + d1 < m && j2 + d2 >= 0 && j2 + d2 < m)//Out of bound condition
                        {
                            val += dp[i + 1][j1 + d1][j2 + d2];
                        }
                        else//If it's out of index set val to very low negative integer
                        {
                            val += -1e7;
                        }
                        mx = max(mx, val);//Find the max among 9 direction
                    }
                }
                dp[i][j1][j2] = mx;//Set the dp of ith row and j1 & j2 point, so it can be used in the next itration
            }
        }
    }
    return dp[0][0][m - 1];//As we were travelling from n-1th row to bottom, therefore the resulut will be store in the last index of the j2t row
}

int cherryPickupTabulationSpaceOptimizationDP(int n, int m, vector<vector<int>> &v)
{
    //As we have seen from previous problem we solved about space optimization i.e.
    //1D -> 2 variables
    //2D -> 1D
    //Therefore it's obvious we will use 2D vector here => 3D -> 2D
    vector<vector<int>> prev(m, vector<int>(m, 0));//Previous will store the base case
    vector<vector<int>> curr(m, vector<int>(m, 0));//Current will store current iteration result, and then will be set to prev so it's can be used in the next itration

    //Store the base case in prev 2D vector
    for (int j1 = 0; j1 < m; ++j1)
    {
        for (int j2 = 0; j2 < m; ++j2)
        {
            if (j1 == j2)
                prev[j1][j2] = v[n - 1][j1];
            else
                prev[j1][j2] = v[n - 1][j1] + v[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j1 = 0; j1 < m; ++j1)
        {
            for (int j2 = 0; j2 < m; ++j2)
            {
                int mx = -1e7;
                for (int d1 = -1; d1 <= 1; ++d1)
                {
                    for (int d2 = -1; d2 <= 1; ++d2)
                    {
                        int val = 0;
                        if (j1 == j2)
                        {
                            val = v[i][j1];
                        }
                        else
                        {
                            val = v[i][j1] + v[i][j2];
                        }
                        if (j1 + d1 >= 0 && j1 + d1 < m && j2 + d2 >= 0 && j2 + d2 < m)
                        {
                            val += prev[j1 + d1][j2 + d2];
                        }
                        else
                        {
                            val += -1e7;
                        }
                        mx = max(mx, val);
                    }
                }
                curr[j1][j2] = mx;//Set the calculated max value in the curr 2D vector
            }
        }
        prev = curr;//After j1th and j2th iteration completed, you can set curr to prev so that it can be used in the next ith iteration
    }
    return prev[0][m - 1];//Finally return the stored maximum cherry output store in the 2D prev vector last index
}

int main()
{
    vector<vector<int>> v = {{3, 1, 1},
                             {2, 5, 1},
                             {1, 5, 5},
                             {2, 1, 1}};

    int n = v.size();
    int m = v[0].size();

    cout << cherryPickupRec(0, 0, m - 1, n, m, v) << "\n"; // TC - O((3^n) * (3^n)) SC - O(n)[stack space]

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << cherryPickupMemoizationDP(0, 0, m - 1, n, m, v, dp) << "\n"; // TC - O(n*m*m)*9 SC - O(n*m*m) + O(n)[stack space]

    cout << cherryPickupTabulationDP(n, m, v) << "\n"; // TC - O(n*m*m)*9 SC - O(n*m*m)

    cout << cherryPickupTabulationSpaceOptimizationDP(n, m, v) << "\n"; // TC - O(n*m*m)*9 SC - O(m*m)

    return 0;
}