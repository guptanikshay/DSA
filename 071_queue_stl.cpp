#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <int> q;
    q.push(11);
    q.push(13);
    q.push(15);
    cout<<"The size of Queue"<<q.size()<<"\n";
    cout<<q.front()<<"\n";
    q.pop();
    cout<<"The size of Queue"<<q.size()<<"\n";
    cout<<q.front()<<"\n";
    if(q.empty())
    cout<<"The Queue is empty\n";
    else
    cout<<"The Queue is not empty\n";
    return 0;
}