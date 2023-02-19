/*
 * It is a contiguous | non contiguous sequence, which follow order in a array
 * Ex -> [3,1,5] => 3,1,5,3 1, 1 5, 3 5, 3 1 5... are subsequences
 * This is different from subarray as it does not contain gap
 * In Subarray you are only allowed to have contiguous element of array
 */
#include <bits/stdc++.h>

using namespace std;

/*
 * This is the recursion way of finding all the subsequences
 * Time Complexity  - O(n*(2^n))
 * Space Complexity - O(n){input space} + O(n){temp/auxillary storage space} + O(n){stack space} => O(n)
 */
void printAllSubsequencesRecursive(vector<int> &v, vector<int> &temp, int i, int n)
{
    if (i == n)
    {
        for (auto &it : temp)
        {
            cout << it << " ";
        }
        cout << "\n";
        return;
    }

    temp.emplace_back(v[i]);
    printAllSubsequencesRecursive(v, temp, i + 1, n);
    temp.pop_back();
    printAllSubsequencesRecursive(v, temp, i + 1, n);
}

/*
 * 1<<n => This is formula of number of possible subsequence.
 * It's equivalent to 2^n
 * Time Complexity  - O(n*(2^n)) => Exponential as first for loop run for 2^n time
 * Space Complexity - O(n){input space} + O(n){temp/auxillary storage space} => O(n)
 * The only benefit is there is no stack space used
 */
void printAllSubsequencesIterative(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < (1 << n); ++i)
    {
        vector<int> temp;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                temp.emplace_back(v[j]);
            }
        }
        for (int j = 0; j < temp.size(); ++j)
        {
            cout << temp[j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<int> v = {3, 1, 5};
    const int n = v.size();
    vector<int> temp;
    printAllSubsequencesRecursive(v, temp, 0, n);
    printAllSubsequencesIterative(v);
    cout << (1 << n);
    return 0;
}