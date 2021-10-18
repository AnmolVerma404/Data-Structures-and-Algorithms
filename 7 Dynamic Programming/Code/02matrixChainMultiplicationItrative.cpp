#include <bits/stdc++.h>

using namespace std;
//As the dp[i][j] initially have the value 1e9+7 and it can't be stored in int data type therefore we define int as long long and due to that the int main is changed to signed
#define int long long

//N is the size of the array a and MOD will store the maximum value so we can find minimum in mcm function
const int N = 102, MOD = 1e9 + 7;
/*
The array a[N] will store the dimension of the mitrices in such way that dimension of i'th matrix is a[i-1]*a[i]
Eg-
    10 20 30 20 30          -> have 4 matrix 
    10X20|20X30|30X20|20X30 -> dimension of all the 4 matrix
*/
int a[N];
// The 2D array dp[N][N] will contain the set of minimum val at the i'th and j'th of dp[i][j]
int dp[N][N];

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = MOD;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
            }
        }
    }
    cout << dp[1][n - 1];
    return 0;
}