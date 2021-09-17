#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

node *createNode(int val)
{
    node *newNode = new node;
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

/*
            4
           |  \
          2     6
         | \   | \
        1   3 5   7  
            After invert
            4
           |  \
          6     2
         | \   | \
        7   5 3   1  
*/

node *invtBT(node *root)
{
    if (root == NULL)
    {
        return root;
    }

    node *left = invtBT(root->left);
    node *right = invtBT(root->right);

    root->right = left;
    root->left = right;

    return root;
}

int main()
{
    node *root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);
    inOrder(root);
    root = invtBT(root);
    cout << "\n";
    inOrder(root);
    // 7 6 5 4 3 2 1
    return 0;
}