//Problem Link - https://www.codingninjas.com/codestudio/problems/implement-trie_1387095
#include <bits/stdc++.h>

using namespace std;

class Trie
{
    struct TrieNode
    {
        struct TrieNode *c[26];
        int ctpfx = 0;
        int ctend = 0;
    };
    TrieNode *node;

public:
    Trie()
    {
        node = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *curr = node;
        for (auto &w : word)
        {
            if (curr->c[w - 'a'] == NULL)
            {
                curr->c[w - 'a'] = new TrieNode();
            }
            curr = curr->c[w - 'a'];
            curr->ctpfx++;
        }
        curr->ctend++;
    }

    int countWordsEqualTo(string &word)
    {
        TrieNode *curr = node;
        for (auto &w : word)
        {
            if (curr->c[w - 'a'] != NULL)
            {
                curr = curr->c[w - 'a'];
            }
            else
            {
                return 0;
            }
        }
        return curr->ctend;
    }

    int countWordsStartingWith(string &word)
    {
        TrieNode *curr = node;
        for (auto &w : word)
        {
            if (curr->c[w - 'a'] != NULL)
            {
                curr = curr->c[w - 'a'];
            }
            else
            {
                return 0;
            }
        }
        return curr->ctpfx;
    }

    void erase(string &word)
    {
        // Write your code here.
        TrieNode *curr = node;
        for (auto &w : word)
        {
            if (curr->c[w - 'a'] != NULL)
            {
                curr = curr->c[w - 'a'];
                curr->ctpfx--;
            }
            else
                return;
        }
        curr->ctend--;
    }
};
int main(){
    string a;
    return 0;
}