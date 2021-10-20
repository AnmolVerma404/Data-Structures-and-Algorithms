#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e3 + 2;
/*
Val(value) array contain the val which can be anything like item/product and will only be seen in the dp array value.
The only array that matter is the wt(weight) array as that will determine whether the val can be holded in the knapsack or not.
*/
int val[N], wt[N];
// The dp array will store the val compared and maximized by weight and max Weight
int dp[N][N];

int knapsack(int n, int w)
{
    //"w" is <= zero will means that bag should be empty in recursion tree this will help to detect -ve indexing
    if (w <= 0)
        return 0;
    //"n" <= zero i.e. number of items is zero
    if (n <= 0)
        return 0;
    //If dp[n][w] != -1 i.e. we have already calculated so no need to recalculate again
    if (dp[n][w] != -1)
        return dp[n][w];
    //if wt[n-1]>w suggests that wt[n-1] is grater that the maximum value w
    if (wt[n - 1] > w)
        dp[n][w] = knapsack(n - 1, w);
    else
        //Finally we compare the last value with current value i.e. with added wt if it is not grater that max W
        dp[n][w] = max(knapsack(n - 1, w), knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);
    //And in last we return dp[n][w]
    return dp[n][w];
}

signed main()
{
    // N is the number of items in the knapsack/bag
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    // This is the max weight
    int W;
    cin >> W;
    // This will set -1 to every location in 
    memset(dp, -1, sizeof dp);

    cout << knapsack(n, W);

    return 0;
}