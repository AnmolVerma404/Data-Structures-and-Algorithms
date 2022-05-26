//TC - O(n(log(log(n)))) - 
#include <bits/stdc++.h>

using namespace std;

void soe(int n)
{
    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    soe(n);
    return 0;
}