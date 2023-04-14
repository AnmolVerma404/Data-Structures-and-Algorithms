#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &v)
{
    for (auto &it : v)
        cout << it << " ";
    cout << "\n";
}

void print(int i)
{
    cout << i << " ";
}

int main()
{
    vector<int> v = {3, 5, 1, 7, 2, 9, 2, 3};

    // Normal way of printing vector
    for (int i = 0; i < v.size(); ++i)
    { // OR for(auto &i : v)
        cout << v[i] << " ";
    }
    cout << "\n";
    // OR
    for_each(begin(v), end(v), print); // here in print we do not need to write as print(<var>)
    cout << "\n";

    // using lambda function
    // in the prev print was getting the curr int i by default, the same is here we are catching the i and not writing the pring function
    // the return type is void, it's not necessary to write
    for_each(begin(v), end(v), [](int i) -> void
             { cout << i << " "; });
    cout << "\n";

    vector<int>::iterator it = find_if(begin(v), end(v), [](int i)
                                       { return i > 4; });
    cout << *it << "\n";

    vector<int> temp = v;

    sort(begin(temp), end(temp), [](int a, int b)
         { return a < b; }); // if a<b then it will return true and vector will be sorted in increasing order
    printArray(temp);

    return 0;
}