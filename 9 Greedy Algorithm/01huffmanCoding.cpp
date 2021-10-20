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
    //This will cantain either the character in the leaf node or the "$" sign that it's not a leaf node
    char data;
    // The freq indicate how many time a char is occurred
    unsigned int freq;
    MinHeapNode *left, *right;
    //A constructor to set the left and right node and assign the freq and data
    MinHeapNode(char data, unsigned int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
/*
In priority queue (min heap) we need this compare class
priority_queue<MinHeapNode *, vector<MinHeapNode *>, greater<MinHeapNode*>> will show different result
*/
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
    // If the current node data is "$" that indicate it't not the leaf node and hence we should print the added up data from this recursive function
    if (root->data != '$')
        cout << root->data << ":" << str << "\n";
    // We recursively call for the left and the right branch as the left will always contain the 0 bit and the right will contain 1 bit
    printHuffman(root->left, str + "0");
    printHuffman(root->right, str + "1");
}

void huffmanCode(char data[], int freq[], int size)
{
    /*
    Now we will make a class call that will initilize the left, right, and the top
    left-> It will carry the left branch freq
    right-> It will carry the right branch freq
    top-> It will carry the addition of both left and right branch freq
    ##Note below example is valid for this full code and function
    Eg-                 |$|30|->(top)
                      /      \
              |$|14|-(left)  |e|16|->(right)
              /      \
          |a|5|     |b|9|
    */
    MinHeapNode *left, *right, *top;
    /*
    Why we are using min Heap?
    -> In the while loop we will get the smallest frequency character with minHeap.top() and as generating a tree we need 2 smallest freq char for the left and right branch. And we will add it in top and similarly we will repeat this unlil min heap size is 1 as that will only cantain the added frequency of all the character
    */    
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    //This will count and increase the frequency of the char array
    for (int i = 0; i < size; i++)
    {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }
    while (minHeap.size() != 1)
    {
        //The 1st smallest in the min heap
        left = minHeap.top();
        minHeap.pop();
        //The 2st smallest in the min heap
        right = minHeap.top();
        minHeap.pop();
        // Add both and store both, as given in the example the top will not be the leaf not and therefore data will be "$"
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    //Finally we print
    printHuffman(minHeap.top(), " ");
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int freq[n];
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }
    huffmanCode(arr, freq, n);
    // char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	// int freq[] = {5, 9, 12, 13, 16, 45};

	// int size = sizeof(arr) / sizeof(arr[0]);

	// huffmanCode(arr, freq, size);

    return 0;
}