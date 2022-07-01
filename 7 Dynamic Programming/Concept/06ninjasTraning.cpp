/*
In this problem we will be given a 2D array which contain row's which are days and columns which are Training tasks for the ninja and v[row][column] is the points given to the ninja also there are only 3 task available in a day, you have to print the maximum point ninja can get while doing one Training in a day and no two days Training can be same i.e. not two ith and jth row task can be same when the both rows are adjacent to one another.
(First problem that deals with 2D DP array)

Approach -
As here also we cant go greedy, therefore we have to try out all the possibilities therefore the answer is recursion!!!

So to find all, max and base case.
As we are goint top-dowm therefor and they can't be adjacent so we need to carry a prev pointer(last).
And the rest is explained in the code go order wise...
*/
#include <bits/stdc++.h>

using namespace std;

int ninjasTrainingRec(int day, int last, vector<vector<int>> &v)
{
    if (day == 0) // Base case will always be at when the day is zero i.e. v[0]
    {
        int mx = 0; // Find the maximum amont v[0]
        for (int i = 0; i < 3; ++i)
        {
            if (i != last) // Also the ith should not be equal to the last, as adjacent in rows are not allowed
            {
                mx = max(mx, v[day][i]);
            }
        }
        return mx; // Return the max element you have found
    }
    int mx = 0;
    for (int i = 0; i < 3; ++i) // As there are three task available in a day so run loop for them
    {
        if (i != last) // Check if the last task is not the ith task
        {
            // v[day][i] means, what are the points ninja get completing the ith task on the day(variable)
            int point = v[day][i] + ninjasTrainingRec(day - 1, i, v); // If not, add the v[day][i], and call for the recursive function
            // It the recursive call was for the base case it will return and compute for the next iteration
            mx = max(mx, point); // Check if the computed point was the max or not
        }
    }
    return mx; // Finally return the max element
}

int ninjasTrainingMemoizationDP(int day, int last, vector<vector<int>> &v, vector<vector<int>> &dp) // Explanation same as recursion solution and additional DP steps are explained
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
    if (dp[day][last] != -1) // If the current days last element is already computed just return it no need to recompute
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
    return dp[day][last] = mx; // As the current days last element is found out then set dp[day][last] val to mx. So it's can be used later
}

int ninjasTrainingTabulationDP(int n, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    /*
    If you go through the base case we can see that, if we are at day 0 and the last is 0, we can't take the 0th index.
    Therefore we must store the maximum of the other two in that.
    Also as the dp[n].size is 4, for the starting condition when the last is three and we need to find the max element among all the three task
    And that is the whole logic behind it!!!
    */
    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);
    dp[0][3] = max(v[0][0], max(v[0][1], v[0][2]));

    for (int day = 1; day < n; ++day)
    // Run the loop for all the day's in recursion when the day was 0 i.e. the base case, and this is bottom-up approach!!!
    {
        for (int last = 0; last < 4; ++last) // Will run to for 4 space in dp[day]
        {
            for (int task = 0; task < 3; ++task) // Will run for all except when current task is equal to the last task
            //That's the reason we need two for loop
            {
                if (task != last)
                {
                    //So calculate the point, and we need not to weight for recursion call to complete as there aren't any
                    int point = v[day][task] + dp[day - 1][task];//So simply get the last day-1 element of the task
                    /*
                    Important do not get confused. The last is the calculated one, and the task is the index being calculated
                    We did day-1 as it will include the maximum point for the ninjas where the task != last
                    */
                    dp[day][last] = max(dp[day][last], point);//Then see if point is max or not
                }
            }
        }
    }
    return dp[n - 1][3];//Finally return the nth day and the 3rd index which will contain the maximum result for the ninja
}

int ninjasTrainingTabulationSpaceOptimizationDP(int n, vector<vector<int>> &v)
{
    //As we see from the previous Tabulation solution we just need the prev computed solution
    //Also this is 2D DP problem therefore, we need a 1D array to store
    //But in this case the input 2D vector v is 2D but not n*m it's n*3 therefore we just need a constant space to store 4 elements
    vector<int> prev(4, -1);
    prev[0] = max(v[0][1], v[0][2]);
    prev[1] = max(v[0][0], v[0][2]);
    prev[2] = max(v[0][0], v[0][1]);
    prev[3] = max(v[0][0], max(v[0][1], v[0][2]));

    for (int day = 1; day < n; ++day)
    {
        vector<int> temp(4, -1);//For the iteration we need the prev array therefore we will store the result in the temp array
        for (int last = 0; last < 4; ++last)
        {
            for (int task = 0; task < 3; ++task)
            {
                if (last != task)
                {
                    temp[last] = max(temp[last], v[day][task] + prev[task]);//Calculate it, and store it in temp
                }
            }
        }
        prev = temp;//Set the prev array to the temp
    }
    return prev[3];//Finally return the last element of the prev array
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
    vector<vector<int>> v = {// Given
                             {2, 1, 3},
                             {3, 4, 6},
                             {10, 1, 6},
                             {8, 3, 7}};
    int n = v.size(); // Size

    // As we need the prev and we are going top down, therefore we will go from the last row and as no one is visited, therefor the prev can be 3 as v[n] have only 0,1,2 element as index there is no 3 index in v[n]
    cout << ninjasTrainingRec(n - 1, 3, v) << "\n"; // TC - O(2^(n*4)) SC - O(N)[Stack Space]

    // How to know we need 2D DP array.
    // The first thing may be the input it may be a 2D array as well, or it may not be
    // There is need of a prev state to maintained for that we need to store it in a 2D fashion
    vector<vector<int>> dp(n, vector<int>(4, -1));                // Defind a 2D DP
    cout << ninjasTrainingMemoizationDP(n - 1, 3, v, dp) << "\n"; // TC - O(n*4) ~ O(n) SC - O(n*4)[dp vector size] + O(n) stack space ~ O(n)
    dp.resize(n, vector<int>(4, -1));

    cout << ninjasTrainingTabulationDP(n, v, dp) << "\n"; // TC - O(n*4*3) ~ O(n) SC - O(n*4)[dp vector size] ~ O(n)

    cout << ninjasTrainingTabulationSpaceOptimizationDP(n, v) << "\n"; // TC - O(n*4*3) ~ O(n) SC - O(4)[prev element to carry] ~ O(1)
    return 0;
}