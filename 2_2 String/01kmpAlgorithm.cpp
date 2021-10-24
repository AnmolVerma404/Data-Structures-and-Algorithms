#include <bits/stdc++.h>

using namespace std;
//This is the profix function this will form a pi table for the pattern string
vector<int> prefixFunction(string p)
{
    int n = p.size();
    vector<int> pi(n, 0);
    // as the pi[0] will be zero
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (p[i] == p[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void kmpAlgorithm(string t, string p)
{
    vector<int> pi = prefixFunction(p);
    int pos = -1;
    int i(0), j(0);
    while (i < t.size())
    {
        if (t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = pi[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == p.size())
        {
            pos = i - p.size();
            break;
        }
    }
    cout << pos;
}

int main()
{
    //t->target, p->pattern
    string t = "abcfaabcedde";
    string p = "abce";
    kmpAlgorithm(t, p);
    return 0;
}