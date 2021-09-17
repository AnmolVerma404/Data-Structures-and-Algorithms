#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

void printCLL(node *head)
{
    node *curr = head;
    if (&head == NULL)
    {
        cout << "The CLL is empty\n";
        return;
    }
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

void insertNodeCLL(node *head, int value) //Remember to use pointer to pointer or use adress of head in the if statment
{
    if (&head == NULL)
    {
        node *newNode = new node();
        newNode->data = value;
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    node *newNode = new node();
    node*curr = head;
    newNode->data = value;
    while(curr->data<value){
        curr = curr->next;
    }
    newNode->next = curr->next;
    newNode->prev = curr->prev;
    curr->next->prev = newNode;
    curr->prev = newNode;
}

void deleteNodeCLL(node *head, int value)
{
    if (head == NULL)
    {
        cout << "The CLL is empty\n";
        return;
    }
    node *curr = head;
    while (curr->data != value)
    {
        curr = curr->next;
        if (curr == head)
        {
            cout << "The element is not present in the CLL\n";
            return;
        }
    }
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    delete (curr);
}

int main()
{
    node *head = new node();
    insertNodeCLL(head,1);
    // printCLL(head);
    insertNodeCLL(head, 2);
    insertNodeCLL(head, 3);
    insertNodeCLL(head, 4);
    cout << "\n";
    printCLL(head);
    deleteNodeCLL(head, 3);
    cout << "\n";
    printCLL(head);
    return 0;
}