#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &v)
{
    for (auto &it : v)
        cout << it << "\n";
    cout << "\n";
}

int n, m;
vector<vector<int>> dp;

int func(string &s1, string &s2, int i, int j)
{
    if (i > n || j > m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + func(s1, s2, i + 1, j + 1);
    }
    else
    {
        int r1 = func(s1, s2, i, j + 1);
        int r2 = func(s1, s2, i + 1, j);

        return dp[i][j] = max(r1, r2);
    }
}

/*
 * In the iterative solution we didn't need a dp of m+1 and n+1 size even if we have written
 * But in the case of tabulation we need it
 * The reason is **index shifting**
 * Index shifting happens when the base case of our recursive code is less than 0
 * As in tabulation we can't write less than 0 base case. Therefore we add an extra index.
 */
int longestCommonSubsequence(string s1, string s2)
{
    dp.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                int r1 = dp[i][j + 1];
                int r2 = dp[i + 1][j];
                dp[i][j] = max(r1, r2);
            }
        }
    }

    return dp[0][0];
}

int main()
{
    string s1 = "abcde", s2 = "ace";
    n = s1.size(), m = s2.size();

    dp.resize(n + 1, vector<int>(m + 1, -1));
    cout << func(s1, s2, 0, 0) - 1 << "\n";

    cout << longestCommonSubsequence(s1, s2);

    return 0;
}