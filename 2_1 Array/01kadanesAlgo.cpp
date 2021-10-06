#include <bits/stdc++.h>

using namespace std;

int maxSubArray(int arr[], int n)
{
    // The maxSum will contain the max Sum of the array it is not effected by i value and is only changed iff currSum>maxSum
    // And also if the array contain only negative terms initializing maxSum=0 will not work so we initilize it wo INT_MIN aka minimum number i.e. -2147483648
    int maxSum = INT_MIN;
    // The currSum will contain the current Sum of the array and it is dependent on i value as in every iteration it will be updated with arr[i] and if currSum<0 will will initilize currSum=0
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum = currSum + arr[i];
        //if the curr sum is grater than the max sum that means that we have found a new largest subarray therefor we will put maxsum = currSum
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
        // If we found out that the curr Sum is less that zero, then we can surly say that the currSum subarray is of no use therefor we put currSum = 0 and in next itration we begain new subarray
        if (currSum < 0)
        {
            currSum = 0;
        }
        // cout<<currSum<<" "<<maxSum<<"\n";
        /*
         currSum  maxSum
            5       5
            1       5
            0       5
            6       6
            5       6
        */
    }
    return maxSum;
}

int main()
{
    int arr[] = {5, -4, -2, 6, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubArray(arr, n);
    return 0;
}