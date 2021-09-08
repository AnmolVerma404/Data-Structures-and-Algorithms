
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
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *levelOrderInsertion(node *root, int val) //This is a level order traversal therefor is the binary tree the loop will travell from 1->2->3->4->5->6->7 until it find lift/right as NULL, Level Order Insertion as it's not a BST
{
    if (root == NULL)
    {
        root = createNode(val);
        return root;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = createNode(val);
            return root;
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = createNode(val);
            return root;
        }
    }
    return NULL;
}

void inOrderTraversal(node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main()
{
    /*
The below binary tree reperesantation
                        1
                     \     \ 
                    2       3
                  \   \    \  \
                4      5  6     7    
*/
    node *root = createNode(1);
    root = levelOrderInsertion(root, 2);
    root = levelOrderInsertion(root, 3);
    root = levelOrderInsertion(root, 4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root = levelOrderInsertion(root, 7);
    inOrderTraversal(root);

    return 0;
}