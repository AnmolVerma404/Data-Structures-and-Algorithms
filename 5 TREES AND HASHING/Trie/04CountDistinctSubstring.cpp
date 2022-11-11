// Problem Link - https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292

#include <bits/stdc++.h>

using namespace std;

int res = 0;
class Trie
{
private:
    struct TrieNode
    {
        TrieNode *c[26];
        bool isEnd = false;
    };
    TrieNode *node;

public:
    Trie()
    {
        node = new TrieNode();
    }
    void insert(string &s, int idx)
    {
        TrieNode *curr = node;
        for (int i = idx; i < s.size(); ++i)
        {
            if (curr->c[s[i] - 'a'] == NULL)
            {
                res++;
                curr->c[s[i] - 'a'] = new TrieNode();
            }
            curr = curr->c[s[i] - 'a'];
        }
        curr->isEnd = true;
    }
};
int countDistinctSubstrings(string &s)
{
    res = 0;
    int n = s.size();
    Trie *node = new Trie();
    for (int i = 0; i < n; ++i)
    {
        node->insert(s, i);
    }
    return res + 1;
}