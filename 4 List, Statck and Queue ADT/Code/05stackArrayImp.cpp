#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100;

class Stack
{
public:
    int st[MAX_SIZE];
    int top;
    Stack()
    {
        top = -1;
    }
    //We can use all funtion in the class and outside the class also but with an argument stack*
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void printStack();
};

void Stack ::push(int value)
{
    if (top >= MAX_SIZE)
    {
        cout << "Stack Overflow\n";
        return;
    }
    // top++;
    // st[top] = value;//This is the common way
    st[++top] = value; //The ++top(1) is different from top++(2), in the first the top is incrementing also and can be printed but second can be printed or be use with other.
    cout << value << " was pushed in the stack.\n";
}

int Stack ::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow\n";
        return 0;
    }
    int poppedEl = st[top--]; //Here we used top--(1) insted of --top(2) as 1 will give the top location of array to popped El and the the top will decrement by one so that we can use the popped element to prinf the popped element if we use 2 we would first decrement the top and that would we wrong
    return poppedEl;
}

int Stack ::peek()
{
    if (top < 0)
    {
        cout << "The stack is empty\n";
    }
    int topEl = st[top];
    return top;
}

bool Stack::isEmpty()
{
    if (top < 0)
    {
        return true;
    }
    return false;
}

bool Stack::isFull()
{
    if (top >= MAX_SIZE)
    {
        return true;
    }
    return false;
}

void Stack::printStack(){
    if(top<0){
        cout<<"Empty Stack\n";
        return;
    }
    for(int i=0;i<=top;i++){
        cout<<st[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.printStack();
    cout << s.pop() << " is popped\n";
    s.printStack();
    s.push(5);
    cout << s.pop() << " is popped\n";
    cout << s.pop() << " is popped\n";
    cout << s.pop() << " is popped\n";
    cout << s.pop() << " is popped\n";
    s.printStack();

    return 0;
}