#include <bits/stdc++.h>

using namespace std;
#define ll long long
// Rabin Karp Algo use the Hash function also called Rolling hash function as the kmp algo use the prefix function or pi function
// Always use large prime number in the hash function to reduce collision or in this case know as Spurious Hits

int p = 31;
const int N = 1e5 + 7, m = 1e6 + 7;
vector<ll> power(N);

/*
    s -> pattern
    t -> text
    q   -> prime number
*/

int main()
{
    string s = "dba";
    string t = "ccaccaaedba";
    int T = t.size(), S = s.size();
    // Precalculating power with DP
    power[0] = 1;
    for (int i = 1; i < N; i++)
    {
        power[i] = (power[i - 1] * p) % m;
    }
    // h : hash of string t
    vector<ll> h(T + 1, 0);
    // The for loop will store the hash value in string t
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % m;
    }
    // h_s : hash of string s
    ll h_s = 0;
    // The for loop will store the hash value in string s
    for (int i = 0; i < S; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * power[i]) % m;
    }
    // i + S -1 so that we don't go out of bound
    /*
    Eg-
           01      012345
        s->ab ; t->acabad
        the for loop will stop at index 4 as if it check for index and that is out of bound because s.length in 2 and t.length is 6
    */
    for (int i = 0; i + S - 1 < T; i++)
    {
        // Here we are adding m so curr_h don't go -ve
        ll curr_h = (h[i + S] - h[i] + m) % m;
        if (curr_h == (h_s * power[i]) % m)
        {
            cout << "Found at index " << i << "\n";
        }
    }
    return 0;
}