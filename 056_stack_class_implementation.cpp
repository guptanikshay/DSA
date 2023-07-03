#include <iostream>
using namespace std;

// STACK USING ARRAY
// class Stack
// {
//     // properties
//     public:
//     int *arr;
//     int top;
//     int size;
//     // behaviour
//     Stack(int size)
//     {
//         this->size = size;
//         this->arr = new int[size];
//         top = -1;
//     }

//     void push(int data)
//     {
//         if (size - top > 1)
//         {
//             this->top++;
//             arr[top] = data;
//         }
//         else
//             cout << "Stack Overflow\n";
//     }
//     void pop()
//     {
//         if (top >= 0)
//             top--;
//         else
//             cout << "Stack Underflow\n";
//     }
//     int peek()
//     {
//         if (top >= 0)
//             return arr[top];
//         else
//         {
//             cout << "Stack is empty\n";
//             return -1;
//         }
//     }
//     bool isEmpty(){
//         if(top==-1)
//         return true;
//         else
//         return false;
//     }
// };

// STACK USING LINKED LIST
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
class Stack
{
public:
    // properties
    Node *ll = NULL;
    Node *head = ll;
    // functions
    void push(int data)
    {
        this->ll = new Node(data);
        ll->next = head;
        head = ll;
    }
    void pop()
    {
        if(this->head==NULL){
            cout<<"Stack Underflow\n";
            return;
        }
        Node *temp = head; 
        head = head->next;
        delete temp;
    }
    int peek()
    {
        if (this->head != NULL)
            return this->head->data;
        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }
    bool isEmpty(){
        if(this->head==NULL)
        return true;
        else
        return false;
    }
};
int main()
{
    Stack st;
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.peek() << "\n";
    st.pop();
    cout << st.peek() << "\n";
    st.pop();
    st.pop();
    st.pop();
    if (st.isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
    return 0;
}