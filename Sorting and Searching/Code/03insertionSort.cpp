// Tip to remember- Make to array a left array and a right array , compare element from right array to the left array if the element is small 'incert' it in the left array.
#include <iostream>

using namespace std;

void takeArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
}

void printArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void insertionSort(int *a, int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
        printArray(a,n);
    }
}

int main()
{
    int a[6] = {12,45,23,51,19,8};
    int size = sizeof(a) / sizeof(a[0]);
    // cout<<size;
    // takeArray(a, size);
    insertionSort(a, size);
    cout<<"THe sorted array is\n";
    printArray(a, size);
    return 0;
}