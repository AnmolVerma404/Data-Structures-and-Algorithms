#include <bits/stdc++.h>
using namespace std;
#define ll int
#define lli long long int
#define llu unsigned int
#define llui unsigned long long int
#define lls short int
#define st string
#define deb(x) cout << #x << ' ' << x << "\n";
#define debn cout << "\n";
#define setpre(x)  \
    cout << fixed; \
    cout.precision(x);
#define all(x) x.begin(), x.end()
#define M 1000000007
template <class base, class power>
double quick_power(base b, power p)
{
    ll temp = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            temp = (b * temp) % M;
        }
        b = (b * b) % M;
        p = p / 2;
    }
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a = 10, b = 10, c = 10, d = 10, e = 10;
    cout << a++ + e << '\n'; //This will not increment a but will add 10(a) to 10(e)
    cout << ++b + e << '\n'; //This will first increment b the the will add 11(b) to 10(e)
    a = 10, b = 10, c = 10, d = 10, e = 10;

    deb(a++); //This will not increment.
    deb(a);
    deb(++b);
    deb(c--); //This will not decrement but will show value.
    deb(c);
    deb(--d);
    return 0;
}