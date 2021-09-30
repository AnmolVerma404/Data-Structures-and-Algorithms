#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num1 = 10, num2 = 20;
    //The binary format of 10 is 1010 and 20 is 10100
    //If in binary number 0&0 will give 0 and only 1&0 and 0&1, 1&1 will give 1
    //Therefor the and result of 10 & 20 will be = 01010
    //                                            10100
    //                                            11110 i.e. 30
    int OR = num1 | num2;
    cout << OR;
    num1 = 4, num2 = 5;
    OR = num1 | num2;
    //Therefor the and result of 4 & 5 will be = 100
    //                                           101
    //                                           101 i.e. 5
    cout << "\n"
         << OR;

    return 0;
}