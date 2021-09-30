#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 13, k; //1101
    // The right shift operator will shift the binary representation of the num by k terms
    // The given number 13 - 1101
    //                         11  -> 3
    //                          👆👆 these 0 and 1 is removed via >> i.e. right shift operator  
    // 🔴🔴 The important thing to notice is the rightShift will be = num/2^k !! here ^ is raise to power 
    k = 2;//Will shift by k
    int rightShift = num>>k;
    cout<<rightShift;
    return 0;
}