#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void printLL(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    Node *temp = head;
    cout << temp->data << " ";
    while (temp->next != head)
    {
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << "\n";
}
void insertAtHead(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        head->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    n->next = head;
    temp->next = n;
    head = n;
}
void insertAfter(Node *&head, int data, int num)
{
    Node *temp = head;
    while (temp->data != num)
    {
        temp = temp->next;
        if (temp == head)
        {
            cout << "This value does not exist in the list.\n";
            break;
        }
    }
    Node *n = new Node(data);
    n->next = temp->next;
    temp->next = n;
}

void delValue(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    Node *temp = head;
    if (head->data == val)
    {
        if (head->next == head)
        {
            head = NULL;
            delete temp;
            return;
        }
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        Node *t = head;
        head = temp->next;
        t->next = NULL;
        delete t;
        return;
    }
    while ((temp->next)->data != val)
    {
        temp = temp->next;
        if (temp == head)
        {
            cout << "Value does not exist in the list\n";
            return;
        }
    }
    Node *d = temp->next;
    temp->next = d->next;
    d->next = NULL;
    delete d;
}
int main()
{
    Node *n1 = new Node(10);
    // Node *head = NULL;
    Node *head = n1;
    head->next = head;
    printLL(head);
    // insertAtHead(head, 11);
    // insertAtHead(head, 12);
    // insertAtHead(head, 13);
    // insertAtHead(head, 14);
    // insertAfter(head, 69, 12);
    // printLL(head);
    delValue(head, 10);
    printLL(head);
    return 0;
}