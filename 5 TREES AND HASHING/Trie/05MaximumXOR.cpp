#include <bits/stdc++.h>

using namespace std;

class Trie{
    private:
    struct TrieNode{
        TrieNode * c[2];
        bool contain(int bit){
            return c[bit]!=NULL;
        }
        TrieNode * get(int bit){
            return c[bit];
        }
        void put(int bit,TrieNode * root){
            c[bit] = root;
        }
    };
    TrieNode * node;
    public:
    Trie(){
        node = new TrieNode();
    }
    void insert(int num){
        TrieNode * curr = node;
        for(int i = 31;i>=0;--i){
            int bit = (num>>i)&1;
            if(!curr->contain(bit)){
                curr->put(bit,new TrieNode());
            }
            curr = curr->get(bit);
        }
    }
    int getMax(int num){
        TrieNode * curr = node;
        int mx = 0;
        for(int i = 31;i>=0;--i){
            int bit = (num>>i)&1;
            if(curr->contain(1-bit)){
                mx = mx | (1<<i);
                curr = curr->get(1-bit);
            }else{
                curr = curr->get(bit);
            }
        }
        return mx;
    }
};

int maxXOR(int n, int m, vector<int> &v1, vector<int> &v2) 
{
    Trie * trie = new Trie();
    for(auto &it : v1) trie->insert(it);
    int mx = 0;
    for(auto &it : v2){
        mx = max(mx,trie->getMax(it));
    }
    return mx;
}