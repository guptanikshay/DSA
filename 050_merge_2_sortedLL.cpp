#include <iostream>
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

// BRUTE FORCE
// Node *merge2LL(Node *&head1, Node *&head2)
// {
//     if(head1==NULL)
//     return head2;
//     if(head2==NULL)
//     return head1;
//     Node *head3 = new Node(-1);
//     Node *t1 = head1, *t2 = head2;
//     while (t1 != NULL && t2 != NULL)
//     {
//         if (t1->data <= t2->data)
//         {
//             insertAtTail(head3, t1->data);
//             t1 = t1->next;
//         }
//         else
//         {
//             insertAtTail(head3, t2->data);
//             t2 = t2->next;
//         }
//     }
//     while(t1!=NULL){
//         insertAtTail(head3, t1->data);
//         t1=t1->next;
//     }
//     while(t2!=NULL){
//         insertAtTail(head3, t2->data);
//         t2=t2->next;
//     }
//     Node * ans = head3->next;
//     delete head3;
//     return ans;
// }

// OPTIMAL APPROACH
Node * merge2LL(Node * &head1, Node * &head2){
    if(head1 == NULL)
    return head2;
    if(head2 == NULL)
    return head1;
    if(head2->data<head1->data){
        Node * n = head2;
        head2 = head2->next;
        n->next = head1;
        head1 = n;
    }
    Node * prev = head1;
    Node * curr = head1->next;
    Node * temp = head2;
    while(curr!=NULL && temp!=NULL){
        if(temp->data>=prev->data && temp->data<=curr->data){
            Node * t = temp;
            temp = temp->next;
            t->next = curr;
            prev->next = t;
            prev = t;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    if(temp!=NULL)
    prev->next = temp;
    return head1;
}
int main()
{
    Node *head1 = new Node(10);
    insertAtTail(head1, 14);
    insertAtTail(head1, 23);
    insertAtTail(head1, 25);
    insertAtTail(head1, 29);
    insertAtTail(head1, 31);
    insertAtTail(head1, 34);
    Node *head2 = new Node(6);
    insertAtTail(head2, 9);
    insertAtTail(head2, 19);
    insertAtTail(head2, 24);
    insertAtTail(head2, 25);
    insertAtTail(head2, 33);
    insertAtTail(head2, 33);
    cout<<"The Linked Lists before merging are\n";
    printLL(head1);
    printLL(head2);
    Node * head3 = merge2LL(head1, head2);
    cout<<"The Linked Lists after merging are\n";
    printLL(head3);
    return 0;
}