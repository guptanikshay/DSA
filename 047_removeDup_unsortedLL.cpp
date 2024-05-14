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
        Node *temp = curr->next;
        Node *prev = curr;
        while (temp != NULL)
        {
            if (curr->data != temp->data)
            {
                temp = temp->next;
                prev = prev->next;
            }
            else
            {
                Node *toDel = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete toDel;
            }
        }
        curr = curr->next;
    }
}
// Another approach that takes more space but consumes less time {O(n) complexity}, using maps.
void removeDup2(Node *&head)
{
    map<int, bool> visited;
    Node *curr = head;
    visited[curr->data] = true;
    while (curr != NULL && curr->next != NULL)
    {
        if (visited[curr->next->data] != true)
        {
            visited[curr->next->data] = true;
            curr = curr->next;
        }
        else
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }
}
int main()
{
    Node *head = new Node(10);
    insertAtTail(head, 11);
    insertAtTail(head, 10);
    insertAtTail(head, 10);
    insertAtTail(head, 9);
    insertAtTail(head, 79);
    insertAtTail(head, 9);
    cout << "The list before removing duplicates is\n";
    printLL(head);
    removeDup(head);
    cout << "The list after removing duplicates is\n";
    printLL(head);
    return 0;
}