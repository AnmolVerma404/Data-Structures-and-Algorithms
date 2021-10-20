#include <bits/stdc++.h>

using namespace std;
/*
The main objective of Huffman coding is
    - Built a Huffman Tree from input character
    - Traverse the Huffman Tree and assign the code to character
How to built the tree
    - All the leaf node will be a unique character which will be stored in Min Heap and the value in the heap will be the frequency of character
*/

class MinHeapNode
{
public:
    //This will cantain either the character in the leaf node or the "$" sign that will 
    char data;
    unsigned int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printHuffman(MinHeapNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printHuffman(root->left, str + "0");
    printHuffman(root->right, str + "1");
}

void huffmanCode(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    for (int i = 0; i < size; i++)
    {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printHuffman(minHeap.top(), " ");
}

int main()
{
    // int n;
    // cin >> n;
    // char arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // int freq[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> freq[i];
    // }
    // huffmanCode(arr, freq, n);
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};

	int size = sizeof(arr) / sizeof(arr[0]);

	huffmanCode(arr, freq, size);

    return 0;
}