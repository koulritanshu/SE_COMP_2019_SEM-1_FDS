// In any language program mostly syntax error occurs due to
// unbalancing delimiter such as (),{},[]. Write C++ program using
// stack to check whether given expression is well parenthesized or
// not

#include <iostream>
#include <string>
#define MAX 100
using namespace std;

template <class T>
class Stack
{
    T arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(T val)
    {
        if (top == MAX - 1)
        {
            cout << ">> Stack is full." << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    T pop()
    {
        T x = arr[top];
        top--;
        return x;
    }
    bool empty()
    {
        return (top == -1);
    }
    T TOP()
    {
        return arr[top];
    }
};

class Expression
{
    string s;

public:
    Expression(string x)
    {
        s = x;
    }
    void checkExpression()
    {
        int index = -1;
        char ch;
        Stack<char> obj;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                obj.push(s[i]);
            }
            else if (s[i] != ')' && s[i] != '}' && s[i] != ']')
            {
                continue;
            }
            else
            {
                if (s[i] == ')')
                {
                    if (obj.empty() || obj.TOP() != '(')
                    {
                        index = i;
                        ch = ')';
                        break;
                    }
                    else
                    {
                        obj.pop();
                    }
                }
                else if (s[i] == '}')
                {
                    if (obj.empty() || obj.TOP() != '{')
                    {
                        index = i;
                        ch = '}';
                        break;
                    }
                    else
                    {
                        obj.pop();
                    }
                }
                else if (s[i] == ']')
                {
                    if (obj.empty() || obj.TOP() != '[')
                    {
                        index = i;
                        ch = ']';
                        break;
                    }
                    else
                    {
                        obj.pop();
                    }
                }
            }
        }
        if (obj.empty() && index == -1)
        {
            cout << ">> The expression is well parenthesized." << endl;
        }
        else
        {
            if (index == -1)
            {
                index = s.size()-1;
                ch = s[s.size()-1];
            }
            cout << ">> Expression is not well parenthesized." << endl;
            cout << ">> Expression breaks at index " << index << " and character " << ch << endl;
        }
        cout << endl << endl;
    }
};

int main()
{
    string s;
    while (true)
    {
        cout << "1. Enter an expression." << endl;
        cout << "2. Check expression." << endl;
        cout << "3. Exit" << endl;
        int choice;
        cout << ">> Make choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cin.ignore();
            getline(cin,s);
        }
        else if (choice == 2)
        {
            Expression obj(s);
            obj.checkExpression();
        }
        else
        {
            cout << ">> GoodBye!" << endl;
            break;
        }
    }
}