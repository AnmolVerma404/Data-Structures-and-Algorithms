// Tip to remember- This is the simplest search as the name give hint that linear search i.e. search element in the array one by one.
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

int linearSearch(int *a, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            cout << "Element found!!!\n";
            return 0;
        }
    }
    cout << "Element not found!!!\n";
    return 0;
}
int main()
{
    int a[5];
    int size = sizeof(a) / sizeof(a[0]);

    takeArray(a, size);
    // printArray(a, size);
    linearSearch(a, size, 3);

    return 0;
}