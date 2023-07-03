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
void printLL(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    Node *temp = head;
    cout << temp->data << " ";
    while (temp->next != head)
    {
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << "\n";
}

// This function takes the head pointer of the circular linked list and after execution this head pointer points to the first half and it returns a pointer pointing to the head of second half.
Node * circular2(Node * &head){
    Node * f = head->next, *s = head;
    while(f->next!=head){
        f=f->next;
        if(f->next!=head)
        f=f->next;
        s=s->next;
    }
    Node * head2 = s->next;
    s->next = head;
    f->next = head2;
    return head2;
}
int main(){
    Node *head = new Node(10);
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    insertAtTail(head, 14);
    insertAtTail(head, 15);
    insertAtTail(head, 16);
    Node * temp = head;
    while(temp->next!=NULL)
    temp = temp->next;
    temp->next = head;
    cout<<"The circular LL before function call is \n";
    printLL(head);
    Node * head2 = circular2(head);
    cout<<"After function call, two LLs are \n";
    printLL(head);
    printLL(head2);
    return 0;
}