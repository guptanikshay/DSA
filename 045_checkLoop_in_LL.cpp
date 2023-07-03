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

Node *checkLoop(Node *head)
{
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
            return temp;
        visited[temp] = true;
        temp = temp->next;
    }
    return NULL;
}
// Another method to do this is using Floyd's Cylce detection algorithm, in which two pointers are used, one slow and other fast and the list traversed using them. If slow and fast meet at some point in the list, then loop is present else if fast reaches NULL then loop is absent.
// To find the starting point of loop using map approach, just return the node which is already visited.
// To find the starting point of loop using Floyd's algorithm, after the meetup of both pointers, make slow=head and starting slow and fast at same pace (one at a time), the node where they meet is the starting Node of loop.
Node *checkLoop2(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *f = head, *s = head;
    while (f != NULL)
    {
        f = f->next;
        s = s->next;
        if (f != NULL)
            f = f->next;
        if (f == s)
        {
            s = head;
            while (f != s)
            {
                f = f->next;
                s = s->next;
            }
            return s;
        }
    }
    return NULL;
}
void removeLoop(Node *&head){
    if(head==NULL)
    return;
    Node * start = checkLoop2(head);
    Node * temp = start;
    while(temp->next!=start)
    temp = temp->next;
    temp->next = NULL;
    return;
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
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head->next->next;
    temp = checkLoop2(head);
    if (temp != NULL)
        cout << "Loop is present in the list at " << temp->data << "\n";
    else
        cout << "No loop is present in the list\n";
    removeLoop(head);
    temp = checkLoop2(head);
    if (temp != NULL)
        cout << "Loop is present in the list at " << temp->data << "\n";
    else
        cout << "No loop is present in the list\n";
    return 0;
}