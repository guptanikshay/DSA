#include <iostream>
#include <stack>
using namespace std;

int main(){
    // Declaring the stack
    stack <int> s;
    // push operation
    s.push(1);
    s.push(2);
    s.push(3);
    // pop operation
    s.pop();
    cout<<"Printing the top element "<<s.top()<<"\n";
    if(s.empty())
    cout<<"Stack is empty\n";
    else
    cout<<"Stack is not empty\n";
    
    cout<<"Size of stack is "<<s.size()<<"\n";
    return 0;
}