#include <bits/stdc++.h>

using namespace std;

#define lineBreak cout<<"\n";
#define out(x) cout<<x<<" ";
#define dOut(x,y) cout<<x<<" "<<y<<"\n";
const int n = 10;
/*
~ -> Approx
*/
int main()
{
    //O(n)
    for(int i = 0;i<n;i++){//i<n will check for n+1 time Therefor O(n+1) ~ O(n)
        //Statement will execute for n times
        // out(i);
    }
    // Output - 0 1 2 3 4 5 6 7 8 9
    // lineBreak;

    //O(n)
    for(int i = n;i>0;i--){//i>0 will check for n+1 time Therefor O(n+1) ~ O(n)
        //Statement will execute for n times
        // out(i);
    }
    // Output - 10 9 8 7 6 5 4 3 2 1
    // lineBreak;

    //O(n)
    for(int i = 0;i<n;i+=2){
        //Statement will execute for n/2 times, as divide by 2 which is constant and that can be ignored.
        // out(i);
    }
    // Output - 0 2 4 6 8
    // lineBreak;

    //O(n^2)
    for(int i = 0;i<n;i++){
        // out(i);
        // lineBreak;
        for(int j = 0;j<n;j++){
            // out(j);
        }
        // lineBreak;
    }
    // Output - 
    // 0 
    // 0 1 2 3 4 5 6 7 8 9 
    // 1 
    // 0 1 2 3 4 5 6 7 8 9
    // 2
    // 0 1 2 3 4 5 6 7 8 9
    // 3
    // 0 1 2 3 4 5 6 7 8 9
    // 4
    // 0 1 2 3 4 5 6 7 8 9
    // 5
    // 0 1 2 3 4 5 6 7 8 9
    // 6
    // 0 1 2 3 4 5 6 7 8 9
    // 7
    // 0 1 2 3 4 5 6 7 8 9
    // 8
    // 0 1 2 3 4 5 6 7 8 9
    // 9
    // 0 1 2 3 4 5 6 7 8 9 
    // lineBreak;

    //O(n^2)
    for(int i = 0;i<n;i++){
        // out(i);
        // lineBreak;
        for(int j = 0;j<i;j++){
            //Statement will run n(n+1)/2 time which is (n^2 + n)/2, removing all the constant we will left with n^2 + n, as we know for larger input(i.e. n) the n will not have significant 
            // out(j);
        }
        // lineBreak;
    }
    // Output - 
    // 0
    // 
    // 1
    // 0
    // 2
    // 0 1
    // 3
    // 0 1 2
    // 4
    // 0 1 2 3
    // 5
    // 0 1 2 3 4
    // 6
    // 0 1 2 3 4 5
    // 7
    // 0 1 2 3 4 5 6
    // 8
    // 0 1 2 3 4 5 6 7
    // 9
    // 0 1 2 3 4 5 6 7 8
    // lineBreak;

    //O(log(n))
    for(int i = 1;i<n;i*=2){
        // out(i);
    }
    // Output - 1 2 4 8 i.e. 2^0 2^1 2^2 2^3
    /*
    We can see the output are increasing by multiple of two as the loop increment condition is i*=2 
    Therefor - 2^0 - 2^1 - 2^2 ----....--- 2^k
    as 2^k loop will terminate soo 2^k = n - (i)
    And as we know a^b=c == log(c)base(a) = b
    From equation (i) we can write log(n)base(2) = k
    */
    // lineBreak;

    // O(log(n))
    for(int i = n;i>1;i/=2){
        // out(i);
    }
    // Output - 10 5 2
    /*
    Similar to the previous one instead of multiplying we are dividing i by 2
    Which will result to - n/2^0 - n/2^1 - n/2^2 ---...--- n/2^k, at this point the loop will terminate
    Therefor n/2^k=1 => n = 2^k => k = log(n)base(2) 
    */
    // lineBreak;

    // O(nlog(n))
    for(int i = 1;i<n;i++){
        // out(i);
        // lineBreak;
        for(int j = 1;j<n;j*=2){
            // out(j);
        }
        // lineBreak;
    }
    /*
    output - 
    1 
    1 2 4 8
    2
    1 2 4 8
    3
    1 2 4 8
    4
    1 2 4 8
    5
    1 2 4 8
    6
    1 2 4 8
    7
    1 2 4 8
    8
    1 2 4 8
    9
    1 2 4 8
    nlogn as n from the first for loop and logn from the 2nd, if loop are nested then we multiple TC of those.
    */
    // lineBreak;

    // O(log(log(n)))
    int p = 0;
    for(int i = 1;i<n;i*=2){
        p++;
        // out(i);
    }
    // lineBreak;
    for(int j = 1;j<p;j*=2){
        // out(j);
    }
    /*
    outut - 
    1 2 4 8 
    1 2
    as the var p will only increment log(n) time and p is the loop termination condition for the 2nd loop therefor they are dependent loops and the 2nd loop is also of log(p) TC.
    Therefor we TC for 2nd loop -> log(p) - (i) where p = log(n) - (ii)
    from (i) & (ii) we get TC for 2nd loop -> O(log(log(n))) with base 2.As 2 is being multiplied in both the loops
    */
    // lineBreak;

    // O(n^(1/2))
    p = 0;
    for(int i = 1;p<=n;i++){
        p+=i;
        // dOut(i,p);
    }
    /*
    output - 
    1 1
    2 3
    3 6
    4 10
    5 15
    Here the TC is O(root(n)), here's why - 
    To condition to fail p>n
        i   p
        1   1
        2   1+2
        3   1+2+3
        4   1+2+3+4
        5   1+2+3+4+5
        |   |||||||||
        |   |||||||||
        |   |||||||||
        k   1+2+3+4+5+6+......+k
        p>n => 1+2+3+...+k>n => (k(k+1))/2>n => K^2 + k > n => k^2 > n => k = root(n) = (n)^1/2
    */
    // lineBreak;

    // O((n)^1/2)
    for(int i = 0;i*i<n;i++){
        out(i);
    }
    /*
    Output - 0 1 2 3
    This loop terminating condition is i*i<n => i^2<n => i = root(n)
    */
    lineBreak;


    return 0;
}