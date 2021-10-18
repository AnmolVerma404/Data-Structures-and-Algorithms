#include <bits/stdc++.h>

using namespace std;

int main()
{
    //For larger value of n we take long long int
    long long int n;
    cin >> n;
    long long int dp[n];
    //But still if the integer val is more that the max val of int our code could crash therefor we use % operator 
    long long int M = 1000000007;
    //These will be the starting statement and this is will follow buttom up approach
    dp[0] = 0;
    dp[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        // We will store the sum of last two element of the array to the ith/current position
        dp[i] = (dp[i - 1] + dp[i - 2]) % M;
    }
    // The dp[n] will be the last element of the fibonacci series
    cout << dp[n];
    return 0;
}
/*
$ git commit -am " Added fibonacci series code with explanation "
*/