#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &v)
{
    for (auto &it : v)
        cout << it << " ";
    cout << "\n";
}
void printArray(vector<pair<int, int>> &v)
{
    for (auto &it : v)
        cout << it.first << " " << it.second << "\n";
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
    sort(begin(temp), end(temp), [](int &a, int &b)
         { return b < a; });
    printArray(temp);

    vector<pair<int, int>> vp = {{1, 2}, {3, 4}, {1, 7}, {1, 1}};
    printArray(vp);
    auto tempPair = vp;
    sort(begin(tempPair), end(tempPair)); // normal sorf first then second
    printArray(tempPair);
    tempPair = vp;
    // This will sort accending for the first and decending for the second in pair
    sort(begin(tempPair), end(tempPair), [](auto &p1, auto &p2)
         {
        if(p1.first == p2.first) return p1.second>p2.second;
        return p1.first<p2.first; });
    printArray(tempPair);

    return 0;
}