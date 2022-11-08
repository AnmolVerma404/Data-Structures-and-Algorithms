#include <bits/stdc++.h>

using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        struct TrieNode *child[26];
        bool fg;
    };
    struct TrieNode *node;

public:
    Trie()
    {
        node = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = node;
        for (auto &w : word)
        {
            if (curr->child[w - 'a'] == NULL)
            {
                curr->child[w - 'a'] = new TrieNode();
            }
            curr = curr->child[w - 'a'];
        }
        curr->fg = true;
    }

    bool search(string word)
    {
        TrieNode *curr = node;
        for (auto &w : word)
        {
            if (curr->child[w - 'a'] == NULL)
                return false;
            curr = curr->child[w - 'a'];
        }
        return curr->fg;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = node;
        for (auto &w : prefix)
        {
            if (curr->child[w - 'a'] == NULL)
                return false;
            curr = curr->child[w - 'a'];
        }
        return true;
    }
};

int main()
{

    return 0;
}