#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head; // (or) tail->next = newNode
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void printCLL()
    {
        // Edge Case
        if (head == NULL)
        {
            cout << "Circular Linked List is Empty.\n";
            return;
        }
        cout << "Elements of the Circular Linked List : \n";
        cout << "Head = " << head->data << endl;
        cout << head->data << "->";
        Node *temp;
        for (temp = head->next; temp != head; temp = temp->next)
            cout << temp->data << "->";
        cout << "HEAD\n";
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "List is Empty.\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }

    void deleteAtTail()
    {
        if (head == NULL)
        {
            cout << "List is Empty.\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = tail;
        Node *prev = head;
        while (prev->next != tail)
            prev = prev->next;
        tail = prev;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }
};

// Class without head
class CircList
{
    Node *tail;

public:
    CircList()
    {
        tail = NULL;
    }
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }
    void printCLL()
    {
        if (tail == nullptr)
        {
            cout << "Circular Linked List is empty.\n";
            return;
        }
        cout << "Elements of the Circular Linked List without head :\n";
        cout << "Head = " << tail->next->data << endl;
        Node *temp = tail->next;
        for (Node *curr = tail->next;; curr = curr->next)
        {
            cout << curr->data << "->";
            if (curr->next == tail->next)
                break;
        }
        cout << "HEAD\n";
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteAtHead()
    {
        if (tail == NULL)
        {
            cout << "List is Empty.\n";
            return;
        }
        Node *temp = tail->next;
        if (temp == tail)
        { // only one node in the list
            delete temp;
            tail = NULL;
        }
        else
        {
            tail->next = temp->next;
            delete temp;
        }
    }
    void deleteAtTail()
    {
        if (tail == NULL)
        {
            cout << "List is Empty.\n";
            return;
        }
        Node *temp = tail;
        // single node in list
        if (tail->next == tail)
        {
            delete tail;
            tail = NULL;
            return;
        }
        Node *prev = tail;
        while (prev->next != tail)
            prev = prev->next;
        tail = prev;
        tail->next = temp->next;
        delete temp;
    }
};

int main()
{
    CircularList cll;

    cll.insertAtHead(2);
    cll.insertAtHead(1);
    cll.insertAtHead(3);
    cll.insertAtTail(5);
    cll.deleteAtHead();
    cll.insertAtHead(12);
    cll.deleteAtTail();
    cll.printCLL();
    cout << endl;

    CircList cl1;
    cl1.insertAtHead(1);
    cl1.insertAtHead(2);
    cl1.insertAtHead(3);
    cl1.insertAtTail(15);
    cl1.deleteAtHead();
    cl1.insertAtTail(10);
    cl1.deleteAtTail();
    cl1.printCLL();
    cout << endl;

    return 0;
}