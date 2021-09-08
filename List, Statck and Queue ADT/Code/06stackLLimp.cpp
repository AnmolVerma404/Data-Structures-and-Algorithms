/*
Stack:-
        5 ; 5 down is 4 is similarly others
        4
        3
        2
        1
*/
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *down; //Supppose stack->push(1,2,3,4,5);then 5 down is 4 down is 3 down is 2 down is 1
};

void push(node **top, int value)
{
    node *newNode = new node();
    newNode->data = value;
    newNode->down = *top;
    *top = newNode;
    cout << value << " was pushed in the linked list\n";
}

void pop(node **top)
{
    if (*top == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }
    node *curr = *top;
    *top = (*top)->down; //This mean the &top is now shifted to the down/next element is the stack
    int poppedEl = curr->data;
    cout << "Element " << poppedEl << " was popped from the stack.\n";
    delete (curr);
}

void peek(node *top)
{
    cout << "The top element is the stack is " << top->data << "\n";
    // cout<<"The 2nd top element is "<<top->down->data<<"\n";//The element is written down but the data to down is down dont be confused
}

void printStack(node *top)
{
    if (top == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "The elements of the stack are:\n";
    node *curr = top;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->down;
    }
}

int main()
{
    node *s = NULL;
    pop(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    pop(&s);
    printStack(s);
    return 0;
}