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

/*
The DFS have three type of travesal 
        - Pre Order Trav.
        - In Order Trav.
        - Post Order Trav.
*/
void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
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
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
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
    cout<<"Pre Order Traversal of a BST also can be applied in a BT\n";
    preOrder(root);
    cout<<"\nIn Order Traversal of a BST also can be applied in a BT\n";
    inOrder(root);//If the tree is BST then in Order traversal will give sorted list
    cout<<"\nPost Order Traversal of a BST also can be applied in a BT\n";
    postOrder(root);

    return 0;
}