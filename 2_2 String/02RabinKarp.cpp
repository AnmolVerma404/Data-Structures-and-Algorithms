#include <bits/stdc++.h>

using namespace std;
#define ll long long
// Rabin Karp Algo use the Hash function also called Rolling hash function as the kmp algo use the prefix function or pi function
// Always use large prime number in the hash function to reduce collision or in this case know as Spurious Hits

int p = 31;
const int N = 1e5 + 7, m = 1e6 + 7;
vector<ll> power;

/*
    s -> pattern
    t -> text
    q   -> prime number
*/

int main()
{
    string s = "na";
    string t = "apna college";
    int T = t.size(), S = s.size();
    power[0] = 1;
    cout<<"Yes\n";
    for (int i = 1; i < N; i++)
    {
        power[i] = (power[i - 1] * p) % m;
    }
    cout<<"Yes\n";
    // h : hash of string t
    vector<ll> h(T + 1, 0);
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % m;
    }
    cout<<"Yes\n";
    // h_s : hash of string s
    ll h_s = 0;
    for (int i = 0; i < S; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * power[i]) % m;
    }
    cout<<"Yes\n";
    // i + S -1 so that we don't go out of bound
    for (int i = 0; i + S - 1 < T; i++)
    {
        ll curr_h = (h[i + S] - h[i] + m) % m;
        if (curr_h == (h_s * power[i]) % m)
        {
            cout << "Found at index " << i << "\n";
        }
    }
    cout<<"Yes\n";
    return 0;
}