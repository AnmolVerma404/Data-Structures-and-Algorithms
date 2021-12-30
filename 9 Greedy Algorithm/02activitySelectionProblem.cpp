#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Here n is the number of activities
    int n;
    cin >> n;
    // 2D vector to storing activities information like start and endpoint of an activity
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        // Start and endpoint to be stored in the vector v
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    /*
    Below we use the lambda function, as the third argument, it is a convenient way of defining an anonymous function object (a closure) right at the location where it's invoked or passed as an argument to a function.
    */
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; }); //  A custom comparator to sort in ascending order wrt end time
    //"take" will be the final output, it refers to the number of activities that are selected
    int take = 1;
    //We initialize take = 1 because we are taking the smallest activity i.e. v[0][1]
    int end = v[0][1];
    for (int i = 1; i < n; i++)
    {
        //v[i][0]>=end, is the obvious condition as the current end time should be less than the next activity starting time so they do not overlap
        if (v[i][0] >= end)
        {
            //Therefore we increment take by 1 and put end = v[i][1]
            take++;
            end = v[i][1];
        }
    }
    //Finally, we output the number of activities
    cout << take << "\n";
    return 0;
}