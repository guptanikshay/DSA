#include <iostream>
using namespace std;

// USING ARRAY
// class Queue{
//     int * arr;
//     int front;
//     int rear;
//     int size;
//     public:
//     Queue(int size){
//         this->size = size;
//         arr = new int[size];
//         front = 0;
//         rear = 0;
//     }
//     void push(int data){
//         if(rear == size)
//         {
//             cout<<"Queue is Full\n";
//             return;
//         }
//         arr[rear]= data;
//         rear++;
//     }
//     void pop(){
//         if(front==rear){
//             cout<<"Queue is empty\n";
//             return;
//         }
//         front++;
//         if(front==rear){
//             front = 0;
//             rear = 0;
//         }
//     }
//     int qfront(){
//         if(front == rear){
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         return arr[front];
//     }
//     int back(){
//         if(front == rear){
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         return arr[rear-1];
//     }
//     bool isEmpty(){
//         if(front == rear)
//         return true;
//         return false;
//     }
// };

// USING LINKED LIST
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
class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = front;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        if (front == NULL)
        {
            front = temp;
            rear = front;
        }
        rear->next = temp;
        rear = temp;
    }
    void pop()
    {
        if (front == NULL)
            cout << "Queue is empty\n";
        else if (front->next == NULL)
        {
            Node *temp = front;
            front = rear = NULL;
            delete temp;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    int qfront(){
        if(front == NULL){
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    int back(){
        if(rear==NULL){
            cout<<"Queue is empty\n";
            return -1;
        }
        return rear->data;
    }
    bool isEmpty(){
        if(front == NULL)
        return true;
        return false;
    }
};
int main()
{
    Queue q;
    q.push(11);
    q.push(13);
    q.push(15);
    q.push(12);
    cout << q.qfront() << "\n";
    q.pop();
    cout << q.qfront() << "\n";
    if (q.isEmpty())
        cout << "The Queue is empty\n";
    else
        cout << "The Queue is not empty\n";
    return 0;
}