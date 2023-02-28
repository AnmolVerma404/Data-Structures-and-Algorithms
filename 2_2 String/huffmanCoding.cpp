#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &v)
{
    for (auto &it : v)
        cout << it << "\n";
    cout << "\n";
}

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, int freq)
    {
        left = NULL;
        right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return l->freq > r->freq;
    }
};

void printHuffmanCoding(MinHeapNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
    {
        cout << root->data << " : " << str << "\n";
    }
    printHuffmanCoding(root->left, str + '0');
    printHuffmanCoding(root->right, str + '1');
}

void huffmanCoding(vector<char> &v, vector<int> &freq, const int n)
{
    MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> pq;

    for (int i = 0; i < n; ++i)
    {
        pq.push(new MinHeapNode(v[i], freq[i]));
    }

    while (pq.size() != 1)
    {
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    printHuffmanCoding(pq.top(), "");
}

int main()
{
    vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    const int n = v.size();
    huffmanCoding(v, freq, n);
    return 0;
}