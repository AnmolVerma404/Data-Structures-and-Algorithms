#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &v)
{
    for (auto &it : v)
        cout << it << "\n";
    cout << "\n";
}

/*
 * Brute Force
 */
void subArrayBF(vector<int> &v, const int &n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = i; k <= j; ++k)
            {
                cout << v[k] << " ";
            }
            cout << "\n";
        }
    }
}

void subArrayEx(vector<int> &v, const int &n)
{
    unsigned int pw = pow(2, n);

    for (int i = 1; i < pw; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                cout << v[j] << " ";
            }
        }
        cout << "\n";
    }
}

void subArrayRec(vector<int> &v, const int &n, int st, int en)
{
    if (en == n)
        return;
    else if (st > en)
    {
        subArrayRec(v, n, 0, en + 1);
    }
    else
    {
        for (int i = st; i <= en; ++i)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        subArrayRec(v, n, st + 1, en);
    }
}

int main()
{
    vector<int> v = {1, 2, 3};
    const int n = v.size();

    // subArrayBF(v, n);
    // subArrayEx(v, n);
    subArrayRec(v, n, 0, 0);

    return 0;
}