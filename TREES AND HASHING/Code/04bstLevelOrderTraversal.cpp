#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

node *createNode(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void levelOrderTrav(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    node *curr;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            q.push(NULL);
            cout << "\n";
        }
        else
        {
            if (curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
            cout << curr->data << " ";
        }
    }
}

int main()
{
    node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    levelOrderTrav(root);

    return 0;
}