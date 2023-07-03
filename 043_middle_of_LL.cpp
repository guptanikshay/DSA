#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
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
Node * findMiddle(Node * head){
    int len = 1;
    Node * ptr = head->next;
    while(ptr!=NULL){
        len++;
        ptr=ptr->next;
    }
    Node * middle=head;
    if(len%2==0)
    len+=2;
    else
    len+=1;
    for(int i=1; i<len/2; i++)
    middle = middle->next;
    return middle;
}

// OPTIMAL APPROACH
// Node * findMiddle2(Node* head){
//     int flag = 1;
//     Node * mid = head, * pro = head;
//     while(pro!=NULL){
//         if(flag>1 && flag%2==0)
//         mid=mid->next;
//         pro = pro->next;
//         flag++;
//     }
//     return mid;
// } // Better method below
Node * findMiddle2(Node * head){
    if(head == NULL || head->next == NULL)
    return head;
    Node * fast = head->next;
    Node * slow = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL)
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main(){
    Node *head = new Node(10);
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    insertAtTail(head, 14);
    insertAtTail(head, 15);
    insertAtTail(head, 16);
    insertAtTail(head, 17);
    cout << "The Linked List is \n";
    printLL(head);
    Node * m = findMiddle2(head);
    cout<<"Its middle is "<< m->data;
    return 0;
}