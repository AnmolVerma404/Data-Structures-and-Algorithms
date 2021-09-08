#include <bits/stdc++.h>

using namespace std;
//When dummmy node is use in DLL we do not need to use **head as an argument in insert at start, end and delete as the head node is not changing!!!->Pros of using dummy node
class node
{
public:
    int data;
    node *next;
    node *prev;
};

void printNode(node *head)
{
    node *curr = head->next;
    if (head->next == head)
    {
        cout << "Empty DLL only dummy node present!!!\n";
        return;
    }
    cout << "DLL traversal begins!!!\n";
    while (curr != head)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\nDLL traversal over!!!"
         << "\n";
}

node *searchNode(node *head, int value)
{
    node *curr = head->next;
    while (curr != head)
    {
        if (curr->data == value)
        {
            return curr;
        }
        if (curr->data < value)
        {
            curr = curr->next;
        }
        else
        {
            break;
        }
    }
    return NULL;
}

void insertNode(node *head, int value)
{
    node *newNode = new node();
    node *curr = head->next;
    newNode->data = value;
    while (curr != head)
    {
        if (curr->data < value) //This will stop if loop find current data >= value
        {
            curr = curr->next;
        }
        else
        {
            break;
        }
    }
    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev = newNode;
    newNode->prev->next = newNode;
    cout << "The new node with value " << newNode->data << " is inserted!!!\n";
    /*
    The current node is in the position 3 due to the last loop first if condition
    prev|head|next==========prev|1|next=============prev|3|next    
                                    \\              ||
                                     \\            ||
                                       prev|2|next
    */
}

void deleteNode(node *head, int value)
{
    node *curr = searchNode(head, value);
    // while (curr != head)
    // {
    //     if (curr->data == value)
    //     {
    //         break;
    //     }
    //     else if (curr->data < value) //This will stop if loop find current data >= value
    //     {
    //         curr = curr->next;
    //     }
    //     else
    //     {
    //         curr = NULL;
    //         break;
    //     }
    // }
    if (curr != NULL)
    {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        cout << "The node with value " << curr->data << " is deleted!!!\n";
        delete (curr);
        return;
    }
    cout << "The given value " << value << " is not present at any node in the given DLL!!!\n";
}

int main()
{
    node *head = new node();
    head->next = head;
    head->prev = head;
    // printNode(head);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    printNode(head);
    deleteNode(head, 7);
    printNode(head);
    return 0;
}