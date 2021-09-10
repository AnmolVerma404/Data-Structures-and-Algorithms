#include <bits/stdc++.h>

using namespace std;

class A
{
    int a;

public:
    void setData(int a)
    {
        // a = a; //This will throw garbage value as a and a are same and c++ can't differectiate between it
        this->a = a;//'this' show's the a is in the class and set this class a's value to the parameter a that we get
    }
    void getData()
    {
        cout << "The value of a is : " << a;
    }
};

int main()
{
    A a;
    a.setData(5);
    a.getData();
    return 0;
}