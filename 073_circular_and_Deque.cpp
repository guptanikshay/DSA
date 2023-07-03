#include <bits/stdc++.h> 
using namespace std;

class CircularQueue{
    int size;
    int front;
    int rear;
    int * arr;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        arr = new int[n];
        front = -1; 
        rear = -1;
        size = n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front!=-1 && front == rear+1) || (front == 0 && rear == size-1)){
            return false;
        }
        else if(front == -1){
            front++;
            rear++;
            arr[front] = value;
        }
        else if(front!=0 && rear==size-1){
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front == -1)
        return -1;
        else if(front == rear){
            int temp = arr[front];
            front = -1;
            rear = -1;
            return temp;
        }
        else if(front == size-1){
            int temp = arr[front];
            front = 0;
            return temp;
        }
        else{
            int temp = arr[front];
            front++;
            return temp;
        }
    }
};

class Deque
{
    long long int * arr;
    long long int front;
    long long int rear;
    long long int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new long long int[n];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || front == rear+1)
        return false;
        else if(front == -1){
            front = rear =0;
        }
        else if(front == 0){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || front == rear+1)
        return false;
        else if(front == -1){
            front = rear =0;
        }
        else if(rear == size-1){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(front == -1)
        return -1;
        else if(front == rear){
            int temp = arr[front];
            front = rear = -1;
            return temp;
        }
        else if(front == size-1){
            int temp = arr[front];
            front = 0;
            return temp;
        }
        else{
            int temp = arr[front];
            front++;
            return temp;
        }
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(front == -1)
        return -1;
        else if(front == rear){
            int temp = arr[front];
            front = rear = -1;
            return temp;
        }
        else if(rear == 0){
            int temp = arr[rear];
            rear = size-1;
            return temp;
        }
        else{
            int temp = arr[rear];
            rear--;
            return temp;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(front == -1)
        return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(rear==-1)
        return rear;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1)
        return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || front == rear+1)
        return true;
        return false;
    }
};
int main(){
    
    return 0;
}