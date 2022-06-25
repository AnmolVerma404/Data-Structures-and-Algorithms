#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

void traverseDLL(node *head)
{
    node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void addAtStart(node **head, int value)//**head is use as head position is to be changed and full linked list can be accessed with the head node
{
    // node * curr = head;
    node *newNode = new node();
    newNode->data = value;
    newNode->next = *head;
    newNode->prev = NULL;
    if ((*head) != NULL)
    {
        (*head)->prev = newNode; //If no dll present this step will not count
    }
    *head = newNode; //This step is important as the adress of head is changed from current head to newNode.
    // cout<<"\n";
}

void addAtLast(node **head, int value)
{
    node *newNode = new node();
    node *currNode = *head;
    newNode->next = NULL;
    newNode->data = value;

    if (currNode == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (currNode->next != NULL) //currNode->next != NULL as we should stop at last node
    {
        currNode = currNode->next;
    }
    currNode->next = newNode;
    newNode->prev = currNode;
}

void addAtIndex(node *prevNode, int value)
{
    //NO need of loop here as we know the prevNode and with that we can access the next node!!!.
    if (prevNode == NULL)
    {
        cout << "Previous node can't be NULL\n";
    }
    node *newNode = new node();
    newNode->data = value;

    newNode->next = prevNode->next;

    newNode->prev = prevNode;
    prevNode->next = newNode;

    if (newNode->next != NULL)
    {
        prevNode->next->prev = newNode;
    }
}

void deleteNode(node **head, node *del)
{
    if (*head == NULL || del == NULL)
    {
        cout << "DLL is already empty\n";
        return;
    }
    if (*head == del)
    { //If head is to be deleted
        *head = del->next;
    }

    if (del->next != NULL)
    { //The node to be deleted is not last
        del->next->prev = del->prev;
    }
    if (del->prev != NULL)
    { //The node to be deleted is not the first node
        del->prev->next = del->next;
    }
    delete (del);
    return;
}

int main()
{
    node *head = new node();
    node *second = new node();
    node *third = new node();

    head->prev = NULL;
    head->next = second;
    head->data = 1;

    second->prev = head;
    second->next = third;
    second->data = 3;

    third->prev = second;
    third->next = NULL;
    third->data = 4;

    traverseDLL(head);
    addAtStart(&head, 0);
    traverseDLL(head);

    traverseDLL(head);
    addAtLast(&head, 5);
    traverseDLL(head);

    traverseDLL(head);
    addAtIndex(second, 5);
    traverseDLL(head);

    traverseDLL(head);
    deleteNode(&head, second);
    traverseDLL(head);

    return 0;
}