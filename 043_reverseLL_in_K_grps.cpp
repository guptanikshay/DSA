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

Node * reverseK(Node *&head, int k){
    Node * curr = head;
    Node * prev = NULL;
    Node * fore = NULL;
    int cnt = 0;
    while(curr!=NULL && cnt<k){
        fore = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fore;
        cnt++;
    }
    if(fore!=NULL)
    head->next = reverseK(fore, k);
    return prev;
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
    cout << "The Linked List before reversal is \n";
    printLL(head);
    head = reverseK(head, 2);
    cout << "The Linked List after reversal is \n";
    printLL(head);
    return 0;
}