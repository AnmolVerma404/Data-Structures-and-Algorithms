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
class node//This class will store the destination data and the link pointer to the destination
{
public:
    int data;
    node *link;
};

class vertexlist//This class will store the head of the adjacency list as mentioned above 1:2,3,4,5 the list one here 1 is the head. We dont need a function for adjList class as it only store the head pointer and which can be easily set in one line, in the main example the 1 is head.
{
public:
    node *vlisthead;
};

class Graph//This class will store all the sublist that are created, in simple word each element of this graph will be a head pointer which will be pointing to list
{
public:
    int v;
    vertexlist *vl;
};

node *NewNode(int value)//We need this function to create and set a new node value
{
    node *newnode = new node;
    newnode->data = value;
    newnode->link = NULL;

    return newnode;
}

//  We dont need a function for adjList class as it only store the head pointer and which can be easily set in one line, in the main example the 1 is head.


Graph *CreateGraph(int n)//This function will create and empty graph will have all the v number of vertices assigned NULL and will gives us an empty array that will contain all the destination's from the head pointer
{
    Graph *vlist = new Graph;
    vlist->v = n;
    vlist->vl = new vertexlist[n];
    for (int i = 0; i < n; i++)
    {
        vlist->vl[i].vlisthead = NULL;
    }
    return vlist;
}

void InsertNode(Graph *G, int v1, int v2)//Now the only thing left is the add the 2,3,4,5 in the main example and it's connection to 1 i.e. the head of the list. The adding edge in the graph can be Done  in O(1)
{
    node *newnode1 = NewNode(v1); //1->2
    node *newnode2 = NewNode(v2); //2->1

    if (G->vl[v2].vlisthead == NULL)//IF the pointer is NULL shows that no element is added up to
    /*
    Eg-> 1 ->(NULL,head) : add 2
         1->2->(head)    :add 3
         1->2->->3(head) :add 4 ...and so on
    We can see we will get this if statement if the new vertex connected element is not present or it's the first time
    */
    {
        G->vl[v2].vlisthead = newnode1;
    }
    else
    {
        newnode1->link = G->vl[v2].vlisthead;
        G->vl[v2].vlisthead = newnode1;
    }
    if (G->vl[v1].vlisthead == NULL)//As above only point 1->2 not 2->1 therefor this if else will add the pointer 2->1 so that the graph is undirected. We can see we will get this if statement if the new vertex connected element is not present or it's the first time
    /*
    Eg-1<-(NULL,head) : add 2
       1<-2-<(head)   : add 3   ...and so on
    */
    {
        G->vl[v1].vlisthead = newnode2;
    }
    else
    {
        newnode2->link = G->vl[v1].vlisthead;
        G->vl[v1].vlisthead = newnode2;
    }
}

void printGraph(Graph *G)
{
    for (int i = 0; i < G->v; i++)
    {
        cout<<i+1<<" : ";
        while (G->vl[i + 1].vlisthead != NULL)
        {
            cout << G->vl[i + 1].vlisthead->data << "  ";
            G->vl[i + 1].vlisthead = G->vl[i + 1].vlisthead->link;
        }
        cout<<"\n";
    }
}

int main()
{
    int v = 5;
    Graph *g = CreateGraph(v);
    InsertNode(g, 1, 2);
    InsertNode(g, 1, 3);
    InsertNode(g, 1, 4);
    InsertNode(g, 1, 5);
    InsertNode(g, 2, 3);
    InsertNode(g, 3, 4);
    InsertNode(g, 4, 5);
    printGraph(g);

    return 0;
}