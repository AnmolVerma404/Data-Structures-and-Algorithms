#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
/*
The below binary tree reperesantation
                        1               | l = 0 , h = 1
                     \     \            
                    2       3           | l = 1 , h = 2
                  \   \    \  \         
                4      5  6     7       | l = 2 , h = 3
*/
/*
The binary tree can only follow BFT
The maximum number of node at a level l is - 2^l(At root node level l = 0)
The maximum number node at a height h is 2^(h+1)-1(At root node height h = 1)
The minimum possible height in BT is |Log(2n+1)| -1, here base of log is 2
A binary tree with l leaves have atleast level of |logL|+1, here base of log is 2
The total number of leaf node in a BT which have either 0 or 2 child L = T+1, here L is the leaf and T is node with 2 children
*/

int main()
{
    node *root = new node(1);
    node *two = new node(2);
    node *three = new node(3);
    node *four = new node(4);
    node *five = new node(5);
    root->left = two;
    root->right = three;
    two->left = four;
    two->right = five;
    three->left = new node(6);
    three->right = new node(7);

    return 0;
}