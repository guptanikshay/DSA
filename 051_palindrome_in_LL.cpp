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

// BRUTE FORCE: Copy the LL into an array and use palindrome logic of array
// bool checkArr(int * arr, int n){
//     int s = 0, e = n-1;
//     while(s<=e){
//         if(arr[s++]!=arr[e--])
//         return false;
//     }
//     return true;
// }
// bool checkLL(Node * head){
//     int len = 0, i=0;
//     Node * temp = head;
//     while(temp!=NULL){
//         len++;
//         temp=temp->next;
//     }
//     int * arr = new int[len];
//     temp = head;
//     while(temp!=NULL){
//         arr[i++] = temp->data;
//         temp = temp->next;
//     }
//     return checkArr(arr, len);
// }

// Another approach, that has the same time complexity but consumes less space.
Node *getMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *fast = head->next;
    Node *slow = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
Node *reverseLL(Node *head)
{
    Node *prev = head;
    Node *curr = head;
    Node *temp = head->next;
    curr->next = NULL;
    while (temp != NULL)
    {
        curr = temp;
        temp = temp->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}
bool checkLL(Node *head)
{
    Node *mid = getMiddle(head);
    mid->next = reverseLL(mid->next);
    Node *s = head, *m = mid->next;
    while (m != NULL)
    {
        if (s->data != m->data){
            mid->next = reverseLL(mid->next);
            return false;
        }
        s = s->next;
        m = m->next;
    }
    mid->next = reverseLL(mid->next);
    return true;
}
int main()
{
    Node *head = new Node(1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    printLL(head);
    if (checkLL(head))
        cout << "It is a palindrome\n";
    else
        cout << "It is not a palindrome\n";
    printLL(head);
    return 0;
}