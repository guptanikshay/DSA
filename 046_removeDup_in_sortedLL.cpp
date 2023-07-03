#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node *&head, int data)
{
    Node *ptr = new Node(data);
    ptr->next = head;
    head = ptr;
}
void insertAtTail(Node *&head, int data)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    Node *temp = new Node(data);
    ptr->next = temp;
}
void printLL(Node *&head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    printf("\n");
}

void removeDup(Node *&head)
{
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data != curr->next->data)
            curr = curr->next;
        else
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
}
int main()
{
    Node *head = new Node(10);
    insertAtTail(head, 11);
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 12);
    insertAtTail(head, 14);
    insertAtTail(head, 14);
    cout << "The list before removing duplicates is\n";
    printLL(head);
    removeDup(head);
    cout << "The list after removing duplicates is\n";
    printLL(head);
    return 0;
}