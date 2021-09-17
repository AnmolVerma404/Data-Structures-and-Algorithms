//In the queue the front element is the top element so if we are printing the queue we start it from the front element
//The queue is based on the FIFO principal i.e. first in first out
/*
Queue:-
        Front(deletion)-->44-->97-->23-->rear(insertion)
*/
#include <bits/stdc++.h>

using namespace std;

const int sizeQ = 1000;

class node
{
public:
    int data;
    // int size;//I commented this as we dont need the size while implementing queue via LL
    node *next;
    node(int d)//With the help of this constructor we don't need to anymore set the data and the next to d and NULL resp..
    {
        data = d;
        next = NULL;
    }
};

// int isEmpty(node *rear)
// {
//     if (rear == NULL)
//     {
//         return 1;
//     }
//     return 0;
// }

// int isFull(node *front)//The LL implementation of queue can't never be full
// {
//     if (front->size == sizeQ)
//     {
//         return 1;
//     }
//     return 0;
// }

// void printQueue(node *q)
// {
//     // if (isEmpty)
//     // {
//     //     cout << "The Queue is empty\n";
//     // }
//     node *curr = new node();
//     while (curr != NULL)
//     {
//         cout << curr->data << " ";
//         curr = curr->next;
//     }
//     cout << "\n";
// }

class Queue
{
public:
    node *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
    void enQueue(int x)
    {
        node *temp = new node(x);//This will allocate the mamory and the data x to the temp node.
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void deQueue()
    {
        if (front == NULL)
        {
            return;
        }
        node *temp = front; //In this and the next step basically what is happining is we save the front node in the temp element and then assigining the next of the front to it's predecessor.
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete (temp);
    }
};

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    // q.deQueue();
    // q.deQueue();
    // printQueue(q);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    // q.deQueue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;

    return 0;
}