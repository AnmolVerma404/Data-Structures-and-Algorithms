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
    node *newNode = new node();
    if (!newNode)
    {
        cout << "Node can't be created\n";
    }
    newNode->data = val;
    newNode->right = newNode->left = NULL;
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

node *bstSearch(node *root, int val)
{
    if (root == NULL || root->data == val)
    {
        return root;
    }
    if (val < root->data)
    {
        return bstSearch(root->left, val);
    }
    return bstSearch(root->right, val);
}

int main()
{
    /*
The below binary tree reperesantation
                        4
                     \     \ 
                    2       6
                  \   \    \  \
                1      3  5     7    
*/
    node *root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);
    // inOrder(root);
    if(bstSearch(root,3)==NULL){
        cout<<"Key dosen't exist\n";
    }else{
        cout<<"Key exist\n";
    }
    return 0;
}