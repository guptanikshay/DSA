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
// BRUTE FORCE APPROACH
void reverseLL(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    int newLL[len];
    temp = head->next;
    newLL[0] = head->data;
    for (int i = 1; i < len; i++)
    {
        newLL[i] = temp->data;
        temp = temp->next;
    }
    temp = head;
    for (int i = len - 1; i >= 0; i--)
    {
        temp->data = newLL[i];
        temp = temp->next;
    }
}
// MORE OPTIMAL APPROACH USING 3 POINTERS
void reverseLL2(Node *&head)
{
    Node *temp = head->next;
    Node *ptr = head;
    Node *prev = head;
    ptr->next = NULL;
    while (temp != NULL)
    {
        ptr = temp;
        temp = temp->next;
        ptr->next = prev;
        prev = ptr;
    }
    head = prev;
}
// ABOVE CODE IN RECURSIVE APPROACH
void reverse_rec1(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    reverse_rec1(head, curr->next, curr);
    curr->next = prev;
}
void reverseLL3(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    reverse_rec1(head, curr, prev);
}

// ANOTHER RECURSIVE APPROACH
Node *reverse_rec2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *chotaHead = reverse_rec2(head->next); // It will reverse the list elements present after head
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}
int main()
{
    Node *head = new Node(10);
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    insertAtTail(head, 14);
    insertAtTail(head, 15);
    insertAtTail(head, 16);
    cout << "The Linked List before reversal is \n";
    printLL(head);
    // reverseLL3(head);
    head = reverse_rec2(head);
    cout << "The Linked List after reversal is \n";
    printLL(head);
    return 0;
}