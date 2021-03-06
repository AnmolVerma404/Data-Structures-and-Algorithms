// C++ program for implementation of selection sort
// Tip to remember- As the name suggest select each and every element and compare it to rest of the elements in the array.
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size);
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    // Loop up to n-1 as, if i is at n-1 the array n-1 element are sorted that mean the last one is also sorted
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        // form i + 1 as, there is not gain in comparing arr[j] < arr[min_idx] where j == min_idx
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        printArray(arr, n);
    }
    // My way but wrong remember correct algorithm
    // for (i = 0; i < n - 1; i++)
    // {
    //     for (j = i + 1; j < n; j++)
    //         if (arr[j] < arr[i])
    //         {
    //             swap(&arr[j], &arr[i]);
    //         }
    //     printArray(arr, n);

    //     // Swap the found minimum element with the first element
    // }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions
int main()
{
    int arr[] = {12, 45, 23, 51, 19, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}

// This is code is contributed by rathbhupendra
