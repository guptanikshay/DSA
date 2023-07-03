#include <iostream>
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
Node * addLL(Node * no1, Node * no2){
    no1 = reverseLL(no1);
    no2 = reverseLL(no2);
    Node * t1 = no1, * t2 = no2;
    Node * no3 = new Node(0);
    Node * ptr = no3;
    int sum = 0, carry = 0;
    while(t1!=NULL && t2!=NULL){
        sum = t1->data + t2->data;
        Node * temp = new Node((sum+carry)%10);
        ptr->next = temp;
        ptr = temp;
        carry = sum/10;
        t1 = t1 ->next;
        t2 = t2->next;
    }
    if(t1==NULL)
    ptr->next = t2;
    else
    ptr->next = t1;
    if(carry!=0){
        Node * c = new Node(carry);
        ptr->next = c;
        ptr = c;
    }
    Node * t = no3;
    no3 = no3->next;
    delete t;
    no3 = reverseLL(no3);
    return no3;
}
int main(){
    Node *no1 = new Node(9);
    insertAtTail(no1, 9);
    // insertAtTail(no1, 2);
    // insertAtTail(no1, 5);
    Node * no2 = new Node(9);
    insertAtTail(no2, 9);
    // insertAtTail(no2, 0);
    // insertAtTail(no2, 9);
    // insertAtTail(no2, 9);
    cout<<"The numbers to be added are \n";
    printLL(no1); printLL(no2);
    Node * no3 = addLL(no1, no2);
    cout<<"Their sum is \n";
    printLL(no3);
    return 0;
}