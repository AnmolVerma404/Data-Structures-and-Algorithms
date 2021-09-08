#include <bits/stdc++.h>
using namespace std;
// example of merge sort in C/C++
// merge function take two intervals
// one from start to mid
// second from mid+1, to end
// and merge them in sorted order
void printArray(int a[], int n);
void merge(int *Arr, int start, int mid, int end)
{
    // create a temp array
    int temp[end - start + 1];

    // crawlers for both intervals and for temp
    int i = start, j = mid + 1, k = 0;

    // traverse both arrays and in each iteration add smaller of both elements in temp
    while (i <= mid && j <= end)
    {
        if (Arr[i] <= Arr[j])
        {
            temp[k] = Arr[i];
            k += 1;
            i += 1;
        }
        else
        {
            temp[k] = Arr[j];
            k += 1;
            j += 1;
        }
    }

    // add elements left in the first interval
    while (i <= mid)
    {
        temp[k] = Arr[i];
        k += 1;
        i += 1;
    }

    // add elements left in the second interval
    while (j <= end)
    {
        temp[k] = Arr[j];
        k += 1;
        j += 1;
    }

    // copy temp to original interval
    for (i = start; i <= end; i += 1)
    {
        Arr[i] = temp[i - start];
    }
}

// Arr is an array of integer type
// start and end are the starting and ending index of current interval of Arr

void mergeSort(int *Arr, int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(Arr, start, mid);
        mergeSort(Arr, mid + 1, end);
        merge(Arr, start, mid, end);
    }
}

void printArray(int a[], int n){
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);
    cout<<"The sorted array\n";
    printArray(arr,arr_size);

    return 0;
}