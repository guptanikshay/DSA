#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *rand;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->rand = NULL;
    }
};
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " " << temp->rand->data << "\n";
        temp = temp->next;
    }
}

// APPROACH 1: Firstly we copy the entire linked list except for the rand pointers, using the next pointers. Then we count the distance of node->rand from our node and point the rand pointer of our cloneLL's node to the node at the same distance.
// Node *cloneLL(Node *head)
// {
//     Node *temp = head;
//     Node *clone = new Node(-1);
//     Node *t = clone;
//     while (temp != NULL)
//     {
//         t->data = temp->data;
//         if (temp->next != NULL)
//         {
//             Node *n = new Node(-1);
//             t->next = n;
//             t = n;
//         }
//         temp = temp->next;
//     }
//     temp = head;
//     t = clone;
//     while (temp != NULL)
//     {
//         int dist = 0;
//         Node *temp2 = head;
//         while (temp->rand != temp2)
//         {
//             temp2 = temp2->next;
//             dist++;
//         }
//         Node *c = clone;
//         while (dist--)
//             c = c->next;
//         t->rand = c;
//         temp = temp->next;
//         t = t->next;
//     }
//     return clone;
// }

// APPROACH 2: In this approach as well we copy the entire linked list except for rand pointers to our cloneLL but we also create mapping of nodes of the original and the clone as we traverse the original LL. Then with the help of this mapping we copy random pointers. For instance, if the rand pointer of first node of original LL is pointing to third node of same LL, which is mapped to the third node of cloneLL, and this way we can point the rand pointer of first node of cloneLL to the the node that is mapped to the third node of the original LL.
// Node * cloneLL(Node * head){
//     Node * temp = head;
//     map <Node*, Node*> mapping;
//     Node * ans = new Node(-1);
//     Node * t = ans;
//     while(temp!=NULL){
//         t->data = temp->data;
//         mapping[temp] = t;
//         if(temp->next!=NULL){
//             Node * n = new Node(-1);
//             t->next = n;
//             t = n;
//         }
//         temp = temp->next;
//     }
//     temp = head;
//     t = ans;
//     while(temp!=NULL){
//         t->rand = mapping[temp->rand];
//         t = t->next;
//         temp = temp->next;
//     }
//     return ans;
// }
// APPROACH 3: In the first approach, TC was O(n^2), SC was O(1) and in the second approach, TC and SC both were O(n). Now, in this approach we will achieve TC of O(n) and SC of O(1).
// Firstly we copy the entire LL except for the random pointers, then manipulate the links. The next pointers of the originalLL are pointed to the respective nodes of the cloneLL and the next pointers of the cloneLL are pointed to the nodes where next pointers of originalLL were initially pointing to. This way we develop a mapping between the nodes of the originalLL and the cloneLL. Then we point the rand pointers to their respective nodes and after that we undo the mapping created b/w nodes and then we return our answer.
Node * cloneLL(Node * head){
    Node * temp = head;
    Node * ans = new Node(-1);
    Node * t = ans;
    while(temp!=NULL){
        t->data = temp->data;
        if(temp->next!=NULL){
            Node * n = new Node(-1);
            t->next = n;
            t = n;
        }
        temp = temp->next;
    }
    temp = head;
    t = ans;
    while(temp!=NULL){
        Node * onext = temp->next;
        temp->next = t;
        Node * cnext = t->next;
        t->next = onext;
        t = cnext;
        temp = onext;
    }
    temp = head;
    t = ans;
    while(temp!=NULL){
        t->rand = temp->rand->next;
        if(t->next!=NULL)
        t = t->next->next;
        temp = temp->next->next;
    }
    temp = head;
    t = ans;
    while(temp!=NULL){
        temp->next = t->next;
        if(temp->next!=NULL)
        t->next = temp->next->next;
        else
        t->next = NULL;
        temp = temp->next;
        t = t->next;
    }
    return ans;
}
int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    first->next = second;
    first->rand = third;
    second->next = third;
    second->rand = first;
    third->next = fourth;
    third->rand = fifth;
    fourth->next = fifth;
    fourth->rand = third;
    fifth->rand = second;
    cout << "The original Linked List is\n";
    printLL(first);
    Node *clone = cloneLL(first);
    cout << "The cloned Linked List is\n";
    printLL(clone);
    return 0;
}