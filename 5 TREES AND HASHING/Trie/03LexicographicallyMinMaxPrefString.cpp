//Problem Link - https://www.codingninjas.com/codestudio/problems/complete-string_2687860
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    struct Node *c[26];
    bool isEnd = false;
    bool contain(char ch)
    {
        return (c[ch - 'a'] != NULL);
    }
    void add(char ch, Node *node)
    {
        c[ch - 'a'] = node;
    }
    Node *next(char ch)
    {
        return c[ch - 'a'];
    }
};
class Trie
{
private:
    Node *node;

public:
    Trie()
    {
        node = new Node();
    }
    void insert(string &s)
    {
        Node *curr = node;
        for (auto &c : s)
        {
            if (!curr->contain(c))
            {
                curr->add(c, new Node());
            }
            curr = curr->next(c);
        }
        curr->isEnd = true;
    }
    bool prefCount(string &s)
    {
        Node *curr = node;
        bool flag = true;
        for (auto &c : s)
        {
            if (curr->contain(c))
            {
                curr = curr->next(c);
                flag = flag & curr->isEnd;
            }
            else
                return false;
        }
        return flag;
    }
};

string completeString(int n, vector<string> &str)
{
    Trie *root = new Trie();
    for (auto &wd : str)
        root->insert(wd);
    int mx = -1;
    string res = "";
    for (auto &wd : str)
    {
        if (root->prefCount(wd))
        {
            if (wd.size() > res.size())
            {
                res = wd;
            }
            else if (wd.size() == res.size() && wd < res)
            {
                res = wd;
            }
        }
    }
    if (res == "")
        return "None";
    return res;
}
int main()
{
    return 0;
}