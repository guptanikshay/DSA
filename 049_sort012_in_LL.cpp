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
// void sort012(Node *&head)
// {
//     int zero=0, one=0, two=0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->data == 0)
//             zero++;
//         else if (temp->data == 1)
//             one++;
//         else
//             two++;
//         temp = temp->next;
//     }
//     temp = head;
//     for (int i = 0; i < zero; i++)
//     {
//         temp->data = 0;
//         temp = temp->next;
//     }
//     for (int i = 0; i < one; i++)
//     {
//         temp->data = 1;
//         temp = temp->next;
//     }
//     for (int i = 0; i < two; i++)
//     {
//         temp->data = 2;
//         temp = temp->next;
//     }
// }
// Another approach, if data replacement is not allowed, then pointers will be replaced.
void insert(Node *& tail, Node * curr){
    tail->next = curr;
    tail = curr;
}
void sort012(Node *&head){
    Node * zeroHead = new Node(-1);
    Node * zeroTail = zeroHead;
    Node * oneHead = new Node(-1);
    Node * oneTail = oneHead;
    Node * twoHead = new Node(-1);
    Node * twoTail = twoHead;

    Node * curr = head;
    // create separate LLs
    while(curr!=NULL){
        int val = curr->data;
        if(val==0)
        insert(zeroTail, curr);
        else if(val==1)
        insert(oneTail, curr);
        else
        insert(twoTail, curr);
        curr = curr->next;
    }
    // merge new LLs
    if(oneHead->next!=NULL)
    zeroTail->next = oneHead->next;
    else
    zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead -> next;
    delete zeroHead, oneHead, twoHead;
}
int main()
{
    Node *head = new Node(1);
    insertAtTail(head, 1);
    insertAtTail(head, 0);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 0);
    cout << "The linked list before sorting\n";
    printLL(head);
    sort012(head);
    cout << "The linked list after sorting\n";
    printLL(head);
    return 0;
}