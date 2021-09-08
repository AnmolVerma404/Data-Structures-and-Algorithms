/*
RB tree is also kind of self balancing tree
*/
/*
Rules
    -Every node is Either red or black
    -The root node is always black
    -A red node can't have a red parent or a red child
    -All path from the root node to the NULL node in a BST have equal number of black node
    -Leaf node is a black node
*/
/*
How to choose between RBT and AVLT 
    -If more insertion and deletion in the tree then choose RBT and vice versa
    -If searching is more common in the tree the choose the AVLT and vice versa
*/