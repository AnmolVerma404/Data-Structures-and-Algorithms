#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data = 0;
    node *next = NULL;
};

//👉👉Remember weherever their is a case of of removing or changing head node position you need to take an pointer to pointer argument
//Only inserting node at starting and at the end take pointer to pointer argument as we need to update/change the addred ot next/previous node therefor we need pointer address otherwise the linked list will be brocked
void createNode(node *n, int d)
{ //Takes two arguments as when a node is created the pointer is initilised and the data to the pointer is stored
}

void insertf(node **head, int d)
{ // ** as the head is pointer to the pointer
    //Alocate memory for the new node
    /*
    *(*head) here * head is a pointer with is holding value of parameter i.e. pointer provided by user and *(*head) is the adress of the pointer
    Eg.
    int x = 10;
    int *p = &x;
    int **q = &p; here p is the parameter take and q is the pointer to the pointer
    */
    node *newNode = new node();
    // Assign the value to the node
    newNode->data = d;
    // Assign newNode next element to the head, now the adress of head is assigned to the new node
    newNode->next = *head;
    //Now the can change the adress of head to the adress of new node
    *head = newNode;
}

void insertB(node *preNode, int data)
{
    if (preNode == NULL)
    {
        cout << "The prevNode can't be NULL";
        return;
    }
    node *newNode = new node();
    newNode->data = data;

    newNode->next = preNode->next;

    preNode->next = newNode;
}

void insertE(node **head, int data) //In linked list we will always know the head element therefore head is in the argument
{
    //Alocate memory for the new node nad assign the data and next to NULL as it new node will bt the last element
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    //If there is no linked list below will create new Linked list
    if (*head == NULL)
    {
        cout << "Created new linked list!!!\n";
        *head = newNode;
        return;
    }
    //Last node is assigned to head as top of the linked list now last will traverse to the link list and find the last element in simple word "last" is the i of for loop
    node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    //Here the last element is found and the next to last element is being assigned to the newNode
    last->next = newNode;
    return;
}

//Remember weherever their is a case of of removing or changing head node position you need to take an pointer to pointer argument
void deleteNode(node **head, int data)
{
    node *currNode = new node();
    node *prevNode = new node();
    currNode = *head;
    if (currNode->data == data)
    {
        *head = currNode->next;
        delete (currNode);
        return;
    }
    else
    {
        while (currNode!=NULL && currNode->data != data)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        if(currNode==NULL)
            return;
        prevNode->next = currNode->next;
        delete (currNode);
    }
}

void prindList(node *n)
{ //We have writen the data type node * as the user will provide node and that node will include the data and the pointer to the next element
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << "\n";
}

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    //Memory is allocated to the node in heap
    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 4;
    third->next = NULL;

    // prindList(head);
    // insertf(&head, 8);
    // prindList(head);

    // cout << &head << "\n";
    // cout<<*head<<"\n";
    // cout<<**head<<"\n";

    // cout<<third;

    // prindList(head);
    // insertB(second,3);
    // prindList(head);

    // prindList(head);
    // insertE(&head,5);
    // prindList(head);

    prindList(head);
    deleteNode(&head, 7);
    prindList(head);

    return 0;
}