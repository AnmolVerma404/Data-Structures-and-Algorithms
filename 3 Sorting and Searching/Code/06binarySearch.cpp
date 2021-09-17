#include <iostream>

using namespace std;

int binarySearch(int *a, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] > x)
        {
            return binarySearch(a, l, mid - 1, x);
        }
        return binarySearch(a, l, mid + 1, x);
    }
    return -1;
}

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {6, 4, 5, 7, 3, 8, 2};
    int x= 1;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr,0,n-1,x);
    (result==-1)?cout<<"Not Found!!!":cout<<"Found at index "<<result;
    return 0;
}