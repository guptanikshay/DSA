#include <iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node * next;
    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node * &head, int data){
    Node * ptr = new Node(data);
    ptr->next = head;
    head = ptr;
}
void printLL(Node * &head){
    Node * ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    printf("\n");
}
void insertAtPosition(Node * &head, int pos, int data){
    int cnt = 1;
    Node * ptr = head;
    while(cnt<pos-1){
        ptr=ptr->next;
        cnt++;
    }
    Node * n = new Node(data);
    n->next = ptr->next;
    ptr->next = n;
}
void insertAtTail(Node * &head, int data){
    Node * ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    Node * temp = new Node(data);
    ptr->next = temp;
}
void deleteNode(Node * &head, int pos){
    // deleting first node
    if(pos == 1){
        Node * ptr = head;
        head = head->next;
        delete ptr;
    }
    // deleting middle and last node
    else{
        Node * ptr = head,* prev = head;
        int cnt = 1;
        while(cnt<pos){
            if(cnt<pos-1)
            prev = prev->next;
            ptr = ptr->next;
            cnt++;
        }
        prev->next = ptr->next;
        ptr->next = NULL;
        delete ptr;
    }
}
int main(){
    Node * n1 = new Node(10);
    cout<<n1->data<<"\n";
    cout<<n1->next<<"\n";
    Node * head = n1;
    insertAtHead(head, 34);
    insertAtTail(head, 69);
    insertAtTail(head, 81);
    insertAtPosition(head, 3, 21);
    cout<<"Before deletion\n";
    printLL(head);
    deleteNode(head, 2);
    printf("After deletion\n");
    printLL(head);
    return 0;
} 