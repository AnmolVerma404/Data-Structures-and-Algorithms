#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *link;
};

class vertexlist
{
public:
    node *vlisthead;
};

class Graph
{
public:
    int v;
    vertexlist *vl;
};

node *NewNode(int value)
{
    node *newnode = new node;
    newnode->data = value;
    newnode->link = NULL;

    return newnode;
}

Graph *CreateGraph(int n)
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

void InsertNode(Graph *G, int v1, int v2)
{
    node *newnode1 = NewNode(v1);
    node *newnode2 = NewNode(v2);

    if (G->vl[v2].vlisthead == NULL)
    {
        G->vl[v2].vlisthead = newnode1;
    }
    else
    {
        newnode1->link = G->vl[v2].vlisthead;
        G->vl[v2].vlisthead = newnode1;
    }
    if (G->vl[v1].vlisthead == NULL)
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