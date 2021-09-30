#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int x = 52; // 110100
    for (int i = 30; i >= 0; i--)
    {
        // As 1 is a int, it can be easily overflowed if x is long long int therefor we can use 1ll as long long int 1 or 1ul as unsigned long int
        // The algorith is simple the i will be left shifted by 1 and if x and 1ll<<i is XOR with 0 or not equal to 0 then the digit is one or vice versa 0 int the x's binary form
        if ((x & (1ll << i)) ^ 0)
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