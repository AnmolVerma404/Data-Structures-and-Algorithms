#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 13, k; //1101
    // The left shift operator will shift the binary representation of the num by k terms
    // The given number 13 - 1101
    //                       110100  ->52
    //                          👆👆 these 0 are added via << i.e. left shift operator
    // 🔴🔴 The important thing to notice is the leftShift will be = num * 2^k !! here ^ is raise to power
    k = 2; //Will shift by k
    int leftShift = num << k;
    cout << leftShift;
    return 0;
}