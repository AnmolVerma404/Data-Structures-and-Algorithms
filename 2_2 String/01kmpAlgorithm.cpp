#include <bits/stdc++.h>

using namespace std;
// This is the profix function this will form a pi table for the pattern string
//Time complixity  of prefixFunction is O(n)
vector<int> prefixFunction(string p)
{
    int n = p.size();
    vector<int> pi(n, 0);
    // as the pi[0] will be zero as it's the first character therefor 0 occurence
    for (int i = 1; i < n; i++)
    {
        // j will carry the last value from pi table and will indicate the upto max length of prefix and sufix equal
        int j = pi[i - 1];
        // we will check in the p string upto p[i] != p[j] therefor it will check until j == 0 
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }
        /*
        s[0...i-1] = abc...ab ->pi[i-1] = 2
        s[0...i]   = abc...abc ->pi[i] = 3
        therefor if p[i] == p[j] we increment the j value 
        */
        if (p[i] == p[j])
            j++;
        //Finally put the j value pi[i], if the value didn't match then we have j = 0 from the while loop above and hence in the pi table we set p[i] = 0 if string not match
        pi[i] = j;
    }
    return pi;
}

void kmpAlgorithm(string t, string p)
{
    // First of all we need to calculate the pi table
    vector<int> pi = prefixFunction(p);
    // pos is the position that we found the match therefor initially it's set to -1
    int pos = -1;
    // We initialize i and j to 0
    int i(0), j(0);
    while (i < t.size())
    {
        // if the string match to the prifix then we will increment i and j
        /*     
            Eg- abc == ab_  ->  abc == abc
                 i      j   ->    i      j
        */
        if (t[i] == p[j])
        {
            i++;
            j++;
        }
        // if it did't match
        else
        {
            // then we will see if j is not equal to zero and we will go back to last result/pi value
            if (j != 0)
            {
                j = pi[j - 1];
            }
            // and if neither is true the string did't match we will just increment the main string and move foeward
            else
            {
                i++;
            }
        }
        // if the string completly match i.e. we have found the string and we can calculate the position
        if (j == p.size())
        {
            pos = i - p.size();
            break;
        }
    }
    // Finally we can pring the position where we found the string
    cout << pos;
}

int main()
{
    // t->target, p->pattern
    string t = "abcfaabcedde";
    string p = "abce";
    // Time complixity O(m+n)//where m is the size of string p and n is the size of the string t.
    kmpAlgorithm(t, p);
    return 0;
}