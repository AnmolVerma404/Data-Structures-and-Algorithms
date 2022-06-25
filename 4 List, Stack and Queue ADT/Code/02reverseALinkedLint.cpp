#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

void linkedListTraversal(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        else
        {
            cout << curr->data << "->";
            curr = curr->next;
        }
    }
    cout << "\n";
}

node *reverseLL(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    node *head = new node();
    node *two = new node();
    node *three = new node();
    node *four = new node();
    node *five = new node();

    head->data = 1;
    head->next = two;

    two->data = 2;
    two->next = three;

    three->data = 3;
    three->next = four;

    four->data = 4;
    four->next = five;

    five->data = 5;
    five->next = NULL;

    //The current linked list is -- 1->2->3->4->5
    cout << "The current linked list:\n";
    linkedListTraversal(head);

    node *revLL = reverseLL(head);

    //The current linked list is -- 5->4->3->2->1
    cout << "The reversed linked list:\n";
    linkedListTraversal(revLL);

    return 0;
}