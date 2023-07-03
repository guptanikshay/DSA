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

// The approach is same as that of arrays, we divide the LL into two parts and then we sort the halves and then we merge them.
Node * mid(Node * head1){
    if(head1==NULL || head1->next == NULL)
    return head1;
    Node * slow = head1;
    Node * fast = head1->next;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node * mergeLL(Node * head1, Node * head2){
    if(head1 == NULL)
    return head2;
    if(head2 == NULL)
    return head1;
    if(head2->data<head1->data){
        Node * temp = head2;
        head2 = head2->next;
        temp->next = head1;
        head1 = temp;
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
void mergeSortLL(Node *&s)
{
    if(s->next == NULL || s == NULL)
    return;
    Node * middle = mid(s);
    Node * temp = middle->next;
    middle->next = NULL;
    mergeSortLL(s);
    mergeSortLL(temp);
    s = mergeLL(s, temp);
}
int main()
{
    Node *head = new Node(10);
    insertAtTail(head, 14);
    insertAtTail(head, 13);
    insertAtTail(head, 9);
    insertAtTail(head, 15);
    insertAtTail(head, 9);
    insertAtTail(head, 12);
    cout << "The LL before sorting is\n";
    printLL(head);
    mergeSortLL(head);
    cout << "The LL after sorting is\n";
    printLL(head);
    return 0;
}