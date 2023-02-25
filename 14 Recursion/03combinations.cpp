#include <bits/stdc++.h>

using namespace std;
/*
 * The difference between permutation and combination is
 * In permutation order matters i.e. 123 and 321 are different
 * Whereas in combination order dosen't matter i.e. 12 and 21 are same
 */
void func(vector<vector<int>> &res, vector<int> &v, int n, int k, int idx)
{
    if (v.size() == k)
    {
        res.emplace_back(v);
        return;
    }
    for (int i = idx + 1; i <= n; ++i)
    {
        /*
         * As order maters we are pushing back i but also passing i again in the function
         * Case 1
         * * func(res, v, n, k, i);
         * * Output - [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
         * Case 2
         * * func(res, v, n, k, idx+1);
         * * Output - [[1,2],[1,3],[1,4],[2,2],[2,3],[2,4],[3,2],[3,3],[3,4],[4,2],[4,3],[4,4]]
         * In the 2nd case we have repeating cases.
         */
        v.emplace_back(i);
        func(res, v, n, k, i);
        v.pop_back();
    }
}

vector<vector<int>> combine(vector<vector<int>> &res, vector<int> &temp, int n, int k)
{
    temp.resize(k, 0);
    int itr = 0;
    while (itr > -1)
    {
        temp[itr]++;
        if (temp[itr] > n)
            itr--;
        else if (itr == k - 1)
            res.push_back(temp);
        else
        {
            itr++;
            temp[itr] = temp[itr - 1];
        }
    }
    return res;
}

int main()
{
    /*
     * n is the range [1,n], and k is the size of combination
     */
    int n = 4, k = 2;
    vector<vector<int>> res;
    vector<int> temp;
    // func(res, temp, n, k, 0);
    combine(res, temp, n, k);
    for (auto &v : res)
    {
        for (auto &it : v)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}