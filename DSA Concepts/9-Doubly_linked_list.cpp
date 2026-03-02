#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_middle(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos < 0)
        {
            cout << "Invalid Position.\n";
            return;
        }
        if (head == NULL)
        {
            if (pos == 0)
                head = tail = newNode;
            else
                cout << "Invalid Position.\n";
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL)
        {
            cout << "Invalid Position.\n";
            return;
        }
        if (temp->next == NULL)
        {
            push_back(val);
            return;
        }
        Node *nextNode = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printDLL()
    {
        Node *temp;
        cout << "Elemnets of the Doubly Linked List :\n";
        cout << "NULL <=> ";
        for (temp = head; temp != NULL; temp = temp->next)
            cout << temp->data << " <=> ";
        cout << "NULL" << endl;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is Empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    void pop_middle(int pos)
    {
        if (pos < 0 || head == NULL)
        {
            cout << "Invalid Position or List is Empty.\n";
            return;
        }
        if (pos == 0)
        {
            pop_front();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; ++i)
            temp = temp->next;
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid Position.\n";
            return;
        }
        Node *newNode = temp->next;
        temp->next = newNode->next;
        if (newNode->next)
            newNode->next->prev = temp;
        else
            tail = temp; // removed last node
        delete newNode;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is Empty.\n";
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }

    // same as singly linked list
    int search(int key)
    {
        Node *temp;
        int pos = 0;
        for (temp = head; temp != NULL; temp = temp->next)
        {
            if (temp->data == key)
                return pos;
            pos++;
        }
        return -1;
    }
};

int main()
{
    DoublyList DLL;
    DLL.push_front(1);
    DLL.push_front(2);
    DLL.push_front(3);
    DLL.push_back(20);
    DLL.push_back(23);
    DLL.push_back(25);
    DLL.pop_front();
    DLL.pop_front();
    DLL.pop_back();
    DLL.printDLL();
    // demonstrate search (returns index)
    cout << "search 20? position " << DLL.search(20) << "\n";
    cout << "search 100? position " << DLL.search(100) << "\n";

    // create list L and test middle operations
    DoublyList L;
    for (int i = 1; i <= 5; ++i)
        L.push_back(i);
    cout << "\nstarting list L:\n";
    L.printDLL();
    // insert at position 2 (third element)
    L.push_middle(99, 2);
    cout << "after push_middle(99,2):\n";
    L.printDLL();
    L.pop_middle(2);
    cout << "after pop_middle(2):\n";
    L.printDLL();

    // even-sized list example
    DoublyList L2;
    L2.push_back(10);
    L2.push_back(20);
    L2.push_back(30);
    L2.push_back(40);
    cout << "\nstarting even list L2:\n";
    L2.printDLL();
    // choose pos 2 again (after second element)
    L2.push_middle(77, 2);
    cout << "after push_middle(77,2) on L2:\n";
    L2.printDLL();
    L2.pop_middle(2);
    cout << "after pop_middle(2) on L2:\n";
    L2.printDLL();

    return 0;
}