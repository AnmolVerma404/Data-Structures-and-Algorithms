#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 52; // 110100
    for (int i = 10; i >= 0; i--)
    {
        if ((x & (1 << i)) != 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }

    return 0;
}