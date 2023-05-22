#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &v)
{
    for (auto &it : v)
        cout << it << " ";
    cout << "\n";
}

/*
 * Recursion DP code
 * TC - Recursion - more than O(2^(n*m)) Space - O(min(m,n))(axuillary space)
 * TC - DP + Recursion - O(n*m) Space - O(m*n) + O(min(m,n))(axuillary space)
 * TC - DP + Tabulation - O(n*m) Space - O(m*n)
 * TC - DP + Tabulation + Space optimization - O(n*m) Space - O(m)
 */
int func(string &s1, string &s2, int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int same = 0, notSame = 0;
    if (s1[i] == s2[j])
    {
        same = 1 + func(s1, s2, i - 1, j - 1, m, n, dp);
    }
    else
    {
        notSame = max(func(s1, s2, i - 1, j, m, n, dp), func(s1, s2, i, j - 1, m, n, dp));
    }
    return dp[i][j] = max(same, notSame);
}

/*
 * Iterative code
 * Print the longest common subsequence
 */
int longestCommonSubsequence(string s1, string s2)
{
    const int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int same = 0, notSame = 0;
            if (s1[i - 1] == s2[j - 1])
            {
                same = 1 + dp[i - 1][j - 1];
            }
            else
            {
                notSame = max(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] = max(same, notSame);
        }
    }
    string s = "";
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(begin(s), end(s));
    cout << s << "\n";
    return dp[m][n];
}

int main()
{

    return 0;
}