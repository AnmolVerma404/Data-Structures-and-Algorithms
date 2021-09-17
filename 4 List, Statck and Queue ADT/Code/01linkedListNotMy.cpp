/*
 * C++ Program to Implement Singly Linked List
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class single_llist
{
    Node *head;

public:
    single_llist() // default constructor. Initializing head pointer
    {
        head = NULL;
    }
    node *create_node(int);
    void insert_begin();
    void insert_pos();
    void insert_last();
    void delete_pos();
    void sort();
    void search();
    void update();
    void reverse();
    void display();
    single_llist()
    {
        start = NULL;
    }
};

// Menu
int main()
{
    int choice, nodes, element, position, i;
    single_llist sl;
    start = NULL;
    while (1)
    {
        cout << endl
             << "---------------------------------" << endl;
        cout << endl
             << "Operations on singly linked list" << endl;
        cout << endl
             << "---------------------------------" << endl;
        cout << "1.Insert Node at beginning" << endl;
        cout << "2.Insert node at last" << endl;
        cout << "3.Insert node at position" << endl;
        cout << "4.Insert node after a node" << endl;
        cout << "5.Insert node before a node" << endl;
        cout << "6.Insert node in middle of the linked list" << endl;
        cout << "7.Delete first  node" << endl;
        cout << "8.Insert last node" << endl;
        cout << "9.Delete a Particular Node" << endl;
        cout << "10.Update Node Value" << endl;
        cout << "11.Search Element" << endl;
        cout << "12.Display Linked List" << endl;
        cout << "13.Exit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Inserting Node at Beginning: " << endl;
            sl.insert_begin();
            cout << endl;
            break;
        case 2:
            cout << "Inserting Node at Last: " << endl;
            sl.insert_last();
            cout << endl;
            break;
        case 3:
            cout << "Inserting Node at a given position:" << endl;
            sl.insert_pos();
            cout << endl;
            break;
        case 4:
            cout << "Insert node after a node" << endl;
            sl.insert_after();
            cout << endl;
            break;
        case 5:
            cout << "Insert node before a node" << endl;
            sl.insert_before();
            cout << endl;
            break;
        case 6:
            cout << "Insert node in middle of the linked list" << endl;
            sl.insert_middle();
            cout << endl;
            break;
        case 7:
            cout << "Delete the first element" << endl;
            s1.delete_first();
            break;
        case 8:
            cout << "Delete the last element" << endl;
            s1.delete_last();
            break;
        case 9:
            cout << "Delete a particular node: " << endl;
            sl.delete_pos();
            break;
        case 10:
            cout << "Update Node Value:" << endl;
            sl.update();
            cout << endl;
            break;
        case 11:
            cout << "Search element in Link List: " << endl;
            sl.search();
            cout << endl;
            break;
        case 12:
            cout << "Display elements of link list" << endl;
            sl.display();
            cout << endl;
            break;
        case 13:
            cout << "Exiting..." << endl;
            exit(1);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

// Inserting element in beginning
void single_llist::insert_begin(int val)
{
    // make a new node
    Node *new_node = new Node;
    new_node->data = val;
    new_node->next = NULL;

    // If list is empty, make the new node, the head
    if (head == NULL)
        head = new_node;
    // else, make the new_node the head and its next, the previous head
    else
    {
        new_node->next = head;
        head = new_node;
    }
    cout << "Element Inserted at beginning" << endl;
}

//Inserting Node at last
void single_llist::insert_last(int val)
{
    int value;
    cout << "Enter the value to be inserted: ";
    cin >> val;
    Node *new_node = new Node;
    new_node->data = val;
    new_node->next = NULL;

    Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    cout << "Element Inserted at last" << endl;
}

//Insertion of node at a given position
void single_llist::insert_pos()
{
    int position, newElement;
    cout << "enter the position to insert:";
    cin >> position;
    cout << "enter the element";
    cin >> newElement;

    Node *newNode = new Node();
    newNode->data = newElement;
    newNode->next = NULL;

    if (position < 1)
    {
        cout << "\nposition should be >= 1.";
    }
    else if (position == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {

        Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }

        if (temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "\nThe previous node is null.";
        }
    }
}

//Insertion after a node
void single_llist::insert_after(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

//Insertion before a node
void single_llist::insert_before(struct node *head, Node *given_ptr, int val)
{
    if (head == given_ptr)
    {
        Node *n = new Node(val);
        n->next = head;
        head = n;
        return n;
    }
    else
    {

        Node *p, *n = head;
        for (n, p; n != given_ptr;
             p = n, n = n->next)
            ;
        Node *m = new Node(val);
        m->next = p->next;
        p->next = m;

        return m;
    }
}

//Insertion of a node in the middle of the linked list
void single_llist::insert_middle(struct node *head, int x)
{
    if (*head == NULL)
        *head = getNode(x);
    else
    {
        Node *newNode = getNode(x);

        Node *ptr = *head;
        int len = 0;

        while (ptr != NULL)
        {
            len++;
            ptr = ptr->next;
        }

        int count = ((len % 2) == 0) ? (len / 2) : (len + 1) / 2;
        ptr = *head;

        while (count-- > 1)
            ptr = ptr->next;

        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

//Delete the first element
void single_llist::delete_first(struct node *head)
{
    if (head == NULL)
        return NULL;

    // Move the head pointer to the next node
    Node *temp = head;
    head = head->next;

    delete temp;

    return head;
}

//Delete the last element
void single_llist::delete_last(struct node *head)
{
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            Node *lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
}

//Delete element of a given position
void single_llist::delete_pos(Node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    Node *temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;
    Node *next = temp->next->next;

    free(temp->next);

    temp->next = next;
}

void print(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

//Update a given Node
void single_llist::update()
{
    int value, pos, i;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Enter the node postion to be updated: ";
    cin >> pos;
    cout << "Enter the new value: ";
    cin >> value;
    Node *temp, *ptr;
    temp = head;
    if (pos == 1)
    {
        head->data = value;
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "There are less than " << pos << " elements";
                return;
            }
            temp = temp->next;
        }
        temp->data = value;
    }
    cout << "Node Updated" << endl;
}

//Searching an element
void single_llist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Enter the value to be searched: ";
    cin >> value;
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        pos++;
        if (temp->data == value)
        {
            flag = true;
            cout << "Element " << value << " is found at position " << pos << endl;
        }
        temp = temp->next;
    }
    if (!flag)
        cout << "Element " << value << " not found in the list" << endl;
}

//Display Elements of a link list
void single_llist::display()
{
    struct node *temp;
    if (head == NULL)
    {
        cout << "The List is Empty" << endl;
        return;
    }
    temp = head;
    cout << "Elements of list are: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
