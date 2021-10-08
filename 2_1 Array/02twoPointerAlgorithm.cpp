/*
This algorithm mostly work on sorted arrays!!!
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {-1, 0, 2, -4, 4, 3};
    int n = sizeof arr / sizeof arr[0];
    // It is important to sort the array for two pointer algo to work
    //Eg A famous question Two Sum can be easily solved with this approach in O(n) and brute force is O(n^2)
    cout << "The sorted array is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    int twoSum = 5;
    //Brute Force approach O(n^2) and this don't need sorted arrray
    cout << "Brute Force approach O(n^2)\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] + arr[j] == twoSum)
            {
                cout << arr[i] << " + " << arr[j] << " = " << twoSum << "\n";
                break;
            }
        }
    }
    // Two pointer approach O(n)
    cout << "Two Pointer approach O(n)\n";
    sort(arr, arr + n);
    int i = 0;     //first pointer
    int j = n - 1; //second pointer
    while (i < j)
    {
        if (arr[i] + arr[j] == twoSum)
        {
            cout << arr[i] << " + " << arr[j] << " = " << twoSum << "\n";
            break;
        }
        else if (arr[i] + arr[j] < twoSum)
        {
            i++;
        }
        else if (arr[i] + arr[j] > twoSum)
        {
            j--;
        }
    }
    return 0;
}