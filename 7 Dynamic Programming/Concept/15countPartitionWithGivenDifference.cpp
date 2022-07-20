/*
Problem Link - https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

As the problem want us to find the number of subsets in the vector which have difference less than given variable "d" which stands for difference.
Also the two differnt subset must contain complete array.

Both subset will sum up to the total sum of the vector
Therefore we can say that from the problem statement
    s1 + s2 = d      -- (i)
    s1>=s2           -- (ii)
    s1 = tSum-s2     -- (iii)
from equation 1 and 3
    s2 = (tSum-D)/2  --(iv)

s2 can be used as target, for the code in the last problem!!!
*/
#include <bits/stdc++.h>

using namespace std;

int partDiffMamoizationDP(int i, int t, vector<int> &v, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        //This is different from the previous as, for this problem the array can contain 0
        //If it's 0 in the last code it will not add up the the number of ways
        if (t == 0 && v[0] == 0)//To check if t is zero and v[0] is also zero
        {
            return 2;//We return 2, as we have two option i.e. to take or not take 0!!!
        }
        if (t == 0 || t == v[i])//Old condition
        {
            return 1;
        }
        return 0;//Else return zero
    }

    if (dp[i][t] != -1)
        return dp[i][t];

    int take = v[i] <= t ? partDiffMamoizationDP(i - 1, t - v[i], v, dp) : 0;

    int notTake = partDiffMamoizationDP(i - 1, t, v, dp);

    return dp[i][t] = take + notTake;
}

int main()
{
    //This code is completely similar to 13th problem therefor refer that
    vector<int> v = {5, 2, 6, 4};
    int n = v.size();
    int d = 3;

    int sum = 0;
    for (auto &it : v)
        sum += it;

    if (sum - d < 0 || (sum - d) % 2)//As we are dividing by 2, therefore it must be even, also sum should now be less than the difference, as it's not possible
    {
        cout << "False";
        return 0;
    }

    int t = (sum - d) / 2;//Target

    vector<vector<int>> dp(n, vector<int>(t + 1, -1));

    cout << partDiffMamoizationDP(n - 1, t, v, dp);

    return 0;
}