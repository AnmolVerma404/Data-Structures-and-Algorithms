#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Brute Force O(n^2)
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sol[4] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // Hence we can use stack as the 2nd for loop is dependent on the first
        {
            if (arr[j] > arr[i])
            {
                sol[i] = arr[j];
                break;
            }
        }
        if (i == n - 1)
        {
            sol[i] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
    // Using stack O(n)
    vector<int> v;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}