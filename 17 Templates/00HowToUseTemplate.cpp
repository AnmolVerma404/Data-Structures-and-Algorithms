/*
 * You can either copy the class code(header file aka .h) inside the template file.
 * Or paste the file in your folder and #include "fileName.h" and use the class
 * Here is the example how to use DisjointSet.h class
 * If the .h file is not in the same directory, you can use #include "../fileName.h" for upper directory.
 * Or use #include "./folderName/fileName.h" for lower directory.
 */

#include "DisjointSet.h"
#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &v)
{
    for (auto &it : v)
        cout << it << " ";
    cout << "\n";
}

int main()
{
    DisjointSet ds = DisjointSet(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }
    ds.unionByRank(3, 7);
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }

    ds.unionByRank(1, 2);
    return 0;
}