/*
In this problem we will be given a 2D array which contain row's which are days and columns which are Training for the ninja and v[row][column] is the points given to the ninja, you have to print the maximum point ninja can get while doing one Training in a day and no two days Training can be same.
*/
#include <bits/stdc++.h>

using namespace std;

int ninjasTrainingRec(int day, int last, vector<vector<int>> &v)
{
    if (day == 0)
    {
        int mx = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (i != last)
            {
                mx = max(mx, v[day][i]);
            }
        }
        return mx;
    }
    int mx = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (i != last)
        {
            int point = v[day][i] + ninjasTrainingRec(day - 1, i, v);
            mx = max(mx, point);
        }
    }
    return mx;
}

int ninjasTrainingMemoizationDP(int day, int last, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int mx = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (i != last)
            {
                mx = max(mx, v[day][i]);
            }
        }
        return mx;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int mx = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (i != last)
        {
            int point = v[day][i] + ninjasTrainingMemoizationDP(day - 1, i, v, dp);
            mx = max(mx, point);
        }
    }
    return dp[day][last] = mx;
}

int ninjasTrainingTabulationDP(int n, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);
    dp[0][3] = max(v[0][0], max(v[0][1], v[0][2]));

    for (int day = 1; day < n; ++day)
    {
        for (int last = 0; last < 4; ++last) // Will run to for 4 space in dp[day]
        {
            for (int task = 0; task < 3; ++task) // Will run for all except
            {
                if (task != last)
                {
                    int point = v[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int ninjasTrainingTabulationSpaceOptimizationDP(int n, vector<vector<int>> &v)
{
    vector<int> prev(4, -1);
    prev[0] = max(v[0][1], v[0][2]);
    prev[1] = max(v[0][0], v[0][2]);
    prev[2] = max(v[0][0], v[0][1]);
    prev[3] = max(v[0][0], max(v[0][1], v[0][2]));

    for (int day = 1; day < n; ++day)
    {
        vector<int> temp(4, -1);
        for (int last = 0; last < 4; ++last)
        {
            for (int task = 0; task < 3; ++task)
            {
                if (last != task)
                {
                    temp[last] = max(temp[last], v[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

void printDP(vector<vector<int>> &dp)
{
    int n = dp.size(), m = dp[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> v = {
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8, 3, 7}};
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));

    cout << ninjasTrainingRec(n - 1, 3, v) << "\n"; // TC - O(2^(n*4)) SC - O(N)[Stack Space]

    cout << ninjasTrainingMemoizationDP(n - 1, 3, v, dp) << "\n"; // TC - O(n*4) ~ O(n) SC - O(n*4)[dp vector size] + O(n) stack space ~ O(n)
    dp.resize(n, vector<int>(4, -1));

    cout << ninjasTrainingTabulationDP(n, v, dp) << "\n"; // TC - O(n*4*3) ~ O(n) SC - O(n*4)[dp vector size] ~ O(n)

    cout << ninjasTrainingTabulationSpaceOptimizationDP(n, v) << "\n";// TC - O(n*4*3) ~ O(n) SC - O(4)[prev element to carry] ~ O(1)
    return 0;
}