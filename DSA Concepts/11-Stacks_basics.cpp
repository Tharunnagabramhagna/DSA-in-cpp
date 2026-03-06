#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

/* General Points about Stack:
   1) Stack is LIFO (Last in First out) data structure.
   2) Stack has a variable named "top" to track the elements in it.
   3) Stack Functions => push(val),pop(),top().
*/

/* Stack implementation using vector */

class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v[v.size() - 1];
    }
    bool isEmpty()
    {
        return (v.size() == 0);
    }
};

/* Stack implementation using Linked List */

class StackLL
{
    list<int> ll;

public:
    void push(int val)
    {
        ll.push_front(val);
    }
    void pop()
    {
        ll.pop_front();
    }
    int top()
    {
        return ll.front();
    }
    bool isEmpty()
    {
        return ll.size() == 0;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Popping of Elements in Stack (Using Vectors) : \n";
    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    StackLL s1;
    s1.push(25);
    s1.push(30);
    s1.push(35);
    cout << "Popping of Elements in Stack (Using Vectors) : \n";
    while (!s1.isEmpty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    /* Stack implementation using C++ STL Libary */

    stack<int> s2;
    s2.push(75);
    s2.push(125);
    s2.push(154);
    cout << "Popping of Elements in Stack (Using STL) : \n";
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}