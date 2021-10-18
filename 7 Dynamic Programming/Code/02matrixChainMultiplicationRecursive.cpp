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

int mcm(int i, int j)
{
    // This is the basis recursion termination condition if i and j will be equal i.e. diagonal it will retrun 0
    if (i == j)
    {
        return 0;
    }
    //If dp[i][j]==-1 i.e. at i and j of dp the minimum value have not yet stored,then we will calculate or else if it's not equal to -1 i.e. we have already calculated then we will just return dp[i][j]
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    //As the dp[i][j] is not yet calculated therefor to find minimum we store the maximum value in dp[i][j]
    dp[i][j] = MOD;
    /*
    Eg  - this step find the sub multiplication matrix i.e.
        - AXBXCXD
        - (A(BXCXD)->(A(B(CXD))|A((BXC)D))) | ((AXBXC)D->(((AXB)C)D| (A(BXC))D)) as in this case only the BXC is calculated many time and it is done by recursion in ** below "for" loop will check each combination adn sub combination **
    */
    for (int k = i; k < j; k++)
    {
        // This will check the minimum of dp[i][j] or mcm(i,k) that will recursively solve the sub multiplication and similarly mcm(k+1,j) and a[i-1]*a[k]*a[j] will multiply the dimention 
        //If we see the main data is in array "a" that will give the minimum value
        //In simple word k is for the bracket in the above example 
        dp[i][j] = min(dp[i][j], mcm(i, k) + mcm(k + 1, j) + a[i - 1] * a[k] * a[j]);
    }
    //Finally we return dp[i][j] and in the last recursive call the value of i and j will be 1 and n-1 respectively
    return dp[i][j];
}

signed main()
{
    int n;
    cin >> n;
    // Here we set all values in dp to -1 as if we encounter it in mcm function conditional statement to check wether if have already find the minimum to avoid re-calculation
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << mcm(1, n - 1) << "\n";
    return 0;
}