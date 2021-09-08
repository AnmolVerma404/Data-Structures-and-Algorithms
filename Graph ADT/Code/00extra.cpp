/*
BFS- It is the bredth first traversal in graph similar to the tree traversal the initial vertices traverse to it's adjacent
*/
#include <bits/stdc++.h>

using namespace std;

/*
The inheritance is == node ->child-> list of nodes ->child that contain multiple list of nodes -> graph
*/

/*
    5--------1       
    \      | \ \
    \     |  \    \->edges
    \    |   \       \
    \   |    \         2->vertics
    \  |     \       |   
    \ |      \     |
    \|       \ |
    4--------3 
        ^       
        \
        edges
*/
/*
list - {
     1:2,3,4,5
     2:1,3
     3:1,4
     4:1,3,5
     5:1,4
}
*/
//dest->Destination, src->source
// **Important main example used -> 1:2,3,4,5
class node //This class will store the destination data and the next pointer to the destination
{
public:
    int data;
    node *next;
};

class vertexlist //This class will store the head of the adjacency list as mentioned above 1:2,3,4,5 the list one here 1 is the head. We dont need a function for adjList class as it only store the head pointer and which can be easily set in one line, in the main example the 1 is head.
{
public:
    node *head;
};

class graph //This class will store all the sublist that are created, in simple word each element of this graph will be a head pointer which will be pointing to list
{
public:
    int v;
    vertexlist *array;
};

node *NewNode(int value) //We need this function to add 2 or 3 or 4 or 5 in the list where 1 is head and when we add one of the above we always set the next to be NULL obviously.
{
    // cout<<"Done 1\n";
    node *newNode = new node;
    newNode->data = value;
    newNode->next = NULL;
    // cout<<"Done 2\n";
    return newNode;
}
//  We dont need a function for adjList class as it only store the head pointer and which can be easily set in one line, in the main example the 1 is head.

graph *createGraph(int v) //This function will create and empty graph will have all the v number of vertices assigned NULL and will gives us an empty array that will contain all the destination's from the head pointer
{
    // cout<<"Done 3\n";
    graph *Graph = new graph;
    Graph->v = v;
    Graph->array = new vertexlist[v + 1]; //The v + 1 as size of array should be 5
    for (int i = 0; i < v + 1; i++)
    {
        Graph->array[i].head = NULL; //Why we are putting array[i] here❓
    }
    // cout<<"Done 4\n";
    return Graph;
}

void InsertNode(graph *g, int src, int dest) //Now the only thing left is the add the 2,3,4,5 in the main example and it's connection to 1 i.e. the head of the list. The adding edge in the graph can be Done  in O(1)
{
    node *newNode1 = NewNode(src);  //1->2
    node *newNode2 = NewNode(dest); //2->1
    //1->2
    if (g->array[dest].head == NULL)
    {
        //If the list is empty
        g->array[dest].head = newNode1;
    }
    else
    {
        //If the list is not empty
        newNode1->next = g->array[dest].head;
        g->array[dest].head = newNode1;
    }
    //2->1
    if (g->array[src].head == NULL)
    {
        //If the list is empty
        g->array[src].head = newNode2;
    }
    else
    {
        //If the list is not empty
        newNode2->next = g->array[dest].head;
        g->array[src].head = newNode2;
    }
}

void printGraph(graph *Graph)
{
    // cout<<"Done 7\n";
    for (int i = 0; i < Graph->v; i++)
    {
        node *list = Graph->array[i].head;
        cout << "\n\tV(" << i + 1 << ") -> {  ";
        while (Graph->array[i + 1].head != NULL)
        {
            cout << Graph->array[i + 1].head->data << " ";
            Graph->array[i + 1].head = Graph->array[i + 1].head->next;
        }
        cout << "}";
    }
    // cout<<"Done 8\n";
}

int main()
{
    // cout<<"Done 9\n";
    int v = 5;
    graph *g = createGraph(v);
    InsertNode(g, 1, 2);
    InsertNode(g, 1, 3);
    InsertNode(g, 1, 4);
    InsertNode(g, 1, 5);
    InsertNode(g, 2, 3);
    InsertNode(g, 3, 4);
    InsertNode(g, 4, 5);//Some mistake with index

    printGraph(g);
    // cout<<"Done 10\n";

    return 0;
}