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

void insertion(node *root, int val) //This will insert the node in BST, with not breaking any of it' rule
//The recursive insertion can be done easily
{
    node *newNode = createNode(val);
    node *curr = root;
    node *temp;
    while (curr != NULL)
    {
        temp = curr;
        if (val < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (val < temp->data)
    {
        temp->left = newNode;
    }
    else
    {
        temp->right = newNode;
    }
}

node* insertionRecursive(node *root, int val)
{
    if (!root)
    {
        return createNode(val);
    }
    if (val < root->data)
    {
        root->left = insertionRecursive(root->left, val);
    }
    else
    {
        root->right = insertionRecursive(root->right, val);
    }
    return root;
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
    // insertion(root, 2);
    // insertion(root, 3);
    // insertion(root, 5);
    // insertion(root, 1);
    // insertion(root, 6);
    // insertion(root, 7);
    
    insertionRecursive(root, 2);
    insertionRecursive(root, 3);
    insertionRecursive(root, 5);
    insertionRecursive(root, 1);
    insertionRecursive(root, 6);
    insertionRecursive(root, 7);


    inOrder(root);
    return 0;
}