#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Brute Force
    int arr[] = {1, 3, 2, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sol[4] = {0};
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            if (arr[j] > arr[i])
            {
                sol[i] = arr[j];
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << sol[i] << " ";
    }
    return 0;
}