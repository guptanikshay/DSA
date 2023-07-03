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

bool checkCircular(Node * head){
    if(head==NULL)
    return true;
    Node * temp = head;
    if(temp->next == temp)
    return true;
    while(temp->next!=NULL){
        temp = temp->next;
        if(temp->next == head)
        return true;
    }
    return false;
}
int main(){
    Node *head = new Node(10);
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    insertAtTail(head, 14);
    insertAtTail(head, 15);
    insertAtTail(head, 16);
    // Node * temp = head;
    // while(temp->next!=NULL)
    // temp = temp->next;
    // temp->next = head;
    if(checkCircular(head))
    cout<<"The list is circular\n";
    else
    cout<<"The list is not circular\n";
    return 0;
}
// Another approach to solve this question is using maps :)