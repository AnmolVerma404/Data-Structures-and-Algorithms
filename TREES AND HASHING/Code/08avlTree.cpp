/*
There are total of 4 type of insertion in AVL binary tree i.e.
    --LL rotation - When the right subtree is unbalanced and this is a base case i.e. only one node is unbalanced
    --RR rotation - When the left subtree is unbalanced and this is a base case i.e. only one node is unbalanced
    --LR rotation - This is a case when >=2 node's are unbalanced
            --First the child of the unbalnced tree will get balanced.
    --RL rotation - This is a case when >=2 node's are unbalanced
            --First the child of the unbalnced tree will get balanced.
*/
/*
LL case --> Perform Right Rotate --(i)
        Z                               y
      |                               |   \
     y           ->                  x     z
    |
   x
LR case --> Perform Left Rotate --> Perform Right Rotate --(ii) (in this case there is an extra as first we need to perform the left rotate so that the BT is now LL and after then the right rotate as the BT is now similar to --(i))
        Z                                 z                                 y
      |                                 |                                 |   \
     y          ->                     y                     ->          x     z
      \                               |
       x                             x   
RR case --> Perform Left Rotate --(iii)
        Z                         y      
          \                     |   \
           y    ->             x     z
            \
             x    
RL case --> Perform Right Rotate --> Perform Left Rotate --(iv) (in this case there is an extra as first we need to perform the right rotate so that the BT is now RR and after then the right rotate as the BT is now similar to --(iii))
        Z                       Z                                             y
         \                       \                                          |   \
          y     ->                y                          ->            x     z
        |                          \
       x                            x
*/
/*
If the LL is unbalanced the do right rotation and vise versa
*/
#include <bits/stdc++.h>

using namespace std;

class node{//The AVL tree class
    public:
    int data;
    node*left;
    node*right;
    int height;
};

int main()
{
    
    return 0;
}