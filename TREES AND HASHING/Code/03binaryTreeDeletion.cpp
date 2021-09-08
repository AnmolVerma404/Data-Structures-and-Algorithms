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

void loDeletion(node *root, node *dNode) //First find the deepest right node and replace and delete it with the node to be deleted.
{
    node *curr = root;
    node *prev;
    while (curr != NULL)
    {
        prev = curr;
        curr = curr->right;
    }
    curr->left = dNode->left;
    curr->right = dNode->right;
    dNode = curr;
    prev->right = NULL;
    delete prev;
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

void loDeleteNodeLeaf(node *root, node *dNode) //Here we use queue and take the root node and the last node i.e. leaf node that is dNode
{
    queue<node *> q;
    q.push(root);
    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->data == dNode->data)
        {
            temp = NULL;
            delete (dNode);
            return;
        }
        if (temp->right)
        {
            if (temp->right == dNode)
            {
                temp->right = NULL;
                delete (dNode);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
        if (temp->left)
        {
            if (temp->left == dNode)
            {
                temp->left = NULL;
                delete (dNode);
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}

node* deletion(node* root, int  data)
{
    if (root == NULL)
        return NULL;
 
    if (root->left == NULL && root->right == NULL) {
        if (root-> data ==  data)
            return NULL;
        else
            return root;
    }
 
    queue<node*> q;
    q.push(root);
 
    node* temp;
    node*  data_node = NULL;
 
    // Do level order traversal to find deepest
    // node(temp) and node to be deleted ( data_node)
    while (!q.empty()) {
        temp = q.front();
        q.pop();
 
        if (temp-> data ==  data)
             data_node = temp;
 
        if (temp->left)
            q.push(temp->left);
 
        if (temp->right)
            q.push(temp->right);
    }
 
    if ( data_node != NULL) {
        int x = temp-> data;
        loDeleteNodeLeaf(root, temp);
         data_node-> data = x;
    }
    return root;
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
    cout << "\n";
    // delete(root->right->right);This don't work
    // loDeleteNodeLeaf(root, root->right->right);
    deletion(root,3);
    inOrderTraversal(root);
    cout << "\n";

    return 0;
}