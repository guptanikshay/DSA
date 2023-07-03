#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}
void insertAtTail(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}
void insertAtPosition(Node *&head, int data, int pos)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }
    int len = 1;
    Node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
        len++;
    }
    if (pos == 1)
        insertAtHead(head, data);
    else if (pos == len + 1)
        insertAtTail(head, data);
    else
    {
        Node *n = new Node(data);
        Node *temp = head;
        for (int i = 0; i < pos - 2; i++)
            temp = temp->next;
        n->next = temp->next;
        n->prev = temp;
        (temp->next)->prev = n;
        temp->next = n;
    }
}
void delNode(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    int len = 1;
    Node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
        len++;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        if (pos == len)
            temp->prev->next = NULL;
        else
        {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
        delete temp;
    }
}
int main()
{
    // Node *n1 = new Node(10);
    Node *head = NULL;
    printLL(head);
    cout << getLength(head) << "\n";
    insertAtHead(head, 9);
    insertAtTail(head, 11);
    insertAtPosition(head, 7, 1);
    insertAtPosition(head, 19, 3);
    insertAtPosition(head, 14, 2);
    insertAtPosition(head, 13, 5);
    printLL(head);
    cout << getLength(head) << "\n";
    delNode(head, 1);
    // delNode(head, 6);
    printLL(head);
    cout << getLength(head) << "\n";
    return 0;
}