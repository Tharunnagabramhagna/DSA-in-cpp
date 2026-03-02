#include <iostream>
using namespace std;

// Creating the Linked List
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
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // Push Front Function
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        // 1st Case
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        { // 2nd Case
            newNode->next = head;
            head = newNode;
        }
    }

    // Push Middle Function
    void push_middle(int val, int pos)
    {
        // Edge Cases
        if (pos < 0 || head == NULL)
        {
            cout << "Invalid Position.\n";
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        // The Logic
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        // Early exit
        if (temp == NULL)
        {
            cout << "Invalid pos.\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        // Edge Case
        if (newNode->next == NULL)
            tail = newNode;
    }

    // Push Back Function
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        // 1st Case
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Search in Linked List
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

    // Pop Front Function
    void pop_front()
    {
        if (head == NULL)
        {
            printf("List is Empty.\n");
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    // Pop Middle Function
    void pop_middle(int pos)
    {
        // Edge Cases
        if (pos < 0 || head == NULL)
        {
            cout << "Invalid Position or List is Empty.\n";
            return;
        }
        // Case 1: Delete head
        if (pos == 0)
        {
            pop_front();
            return;
        }
        // Case 2: Delete from middle or end
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL || temp->next == NULL)
            {
                cout << "Invalid Position.\n";
                return;
            }
            temp = temp->next;
        }
        // Check if node to delete exists
        if (temp->next == NULL)
        {
            cout << "Invalid Position.\n";
            return;
        }
        Node *newNode = temp->next;
        temp->next = newNode->next;

        // Update tail if we deleted the last node
        if (newNode == tail)
            tail = temp;

        delete newNode;
    }

    // Pop Back Function
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is Empty.\n";
            return;
        }
        // single element
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
            temp = temp->next;
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // Print a Linked List
    void printLL()
    {
        Node *temp;
        cout << "Elements of the Linked List : ";
        for (temp = head; temp != NULL; temp = temp->next)
            cout << temp->data << "->";
        cout << "NULL" << endl;
    }
};

int main()
{
    List LL;

    LL.push_front(4);
    LL.push_front(3);
    LL.push_front(2);
    LL.pop_front();
    LL.push_middle(5, 3);
    LL.pop_middle(2);
    LL.pop_back();
    LL.push_back(1);
    cout << "Element 3 is at index : " << LL.search(1) << endl;
    LL.printLL();

    return 0;
}