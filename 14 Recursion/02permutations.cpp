#include <bits/stdc++.h>

using namespace std;

void display(vector<int> &v)
{
    for (auto &it : v)
        cout << it << " ";
    cout << "\n";
}

/*
 * This is the recursive algorithm for finding all the permutation
 */
void permutationRecursive(vector<int> &v, int idx, const int n)
{
    if (idx == n)
    {
        display(v);
        return;
    }

    for (int i = idx; i < n; ++i)
    {
        swap(v[i], v[idx]);
        permutationRecursive(v, idx + 1, n);
        swap(v[i], v[idx]);
    }
}

/*
 * Iterative function to find permutations of a string
 * Sorce => https://www.techiedelight.com/find-permutations-string-cpp-java-iterative/
 */
void permutationIterative(vector<int> &v, const int n)
{
    if (n == 0)
    {
        return;
    }
    // base case
    if (n == 1)
    {
        display(v);
        return;
    }

    // sort the string in a natural order
    sort(v.begin(), v.end());

    while (1)
    {
        // print the current permutation
        display(v);

        /* The following code will rearrange the string to the next lexicographically
           ordered permutation (if any) or return if we are already at the
           highest possible permutation */

        // Find the largest index `i` such that `v[i-1]` is less than `v[i]`
        int i = n - 1;
        while (v[i - 1] >= v[i])
        {
            // if `i` is the first index of the string, we are already at the last
            // possible permutation (string is sorted in reverse order)
            if (--i == 0)
            {
                return;
            }
        }

        // find the highest index `j` to the right of index `i` such that
        // `v[j] > v[i-1]` (`v[i…n-1]` is sorted in reverse order)

        int j = n - 1;
        while (j > i && v[j] <= v[i - 1])
        {
            j--;
        }

        // swap character at index `i-1` with index `j`
        swap(v[i - 1], v[j]);

        // reverse substring `v[i…n-1]`
        reverse(v.begin() + i, v.end());
    }
}

/*
 * Find all the permutation of a list using C++ STL
 */
void permutationSTL(vector<int> &v, const int n)
{
    // Sort the given array
    sort(begin(v), begin(v) + n);

    // Find all possible permutations
    cout << "Possible permutations are:\n";
    do
    {
        display(v);
    } while (next_permutation(begin(v), begin(v) + n));
}

int main()
{
    vector<int> v = {1, 2, 3};
    const int n = v.size();
    permutationRecursive(v, 0, n);
    permutationIterative(v, n);
    permutationSTL(v, n);
    return 0;
}