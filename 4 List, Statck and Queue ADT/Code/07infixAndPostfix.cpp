#include <bits/stdc++.h>

using namespace std;

int prec(char c)//This will check the precedence of the current character
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void infixToPostfix(string s)
{
    stack<char> st;
    string result;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')//Will pop all the element inside the braces i.e. (2+3*5) all the inside element will be popped from the stack 
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))//The precedence will be calculated here if the precedence is low then all the element will be popped
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())//The rest operator which are left in the stack will be added in result and popped from the stack
    {
        result += st.top();
        st.pop();
    }
    cout << result << '\n';
}

int main()
{
    string s = "A*(B+C*D)+E";
    infixToPostfix(s);

    return 0;
}