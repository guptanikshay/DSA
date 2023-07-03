#include <bits/stdc++.h>
using namespace std;
void printQ(queue <int> q){
    int n = q.size();
    for(int i=0; i<n; i++){
    cout<<q.front()<<" ";
    q.pop();
    }
    cout<<"\n";
}
// Approach 1: Using Stack
void reverseQ(queue <int> &q){
    stack <int> s;
    int n = q.size();
    for(int i=0; i<n; i++){
        s.push(q.front());
        q.pop();
    }
    for(int i=0; i<n; i++){
        q.push(s.top());
        s.pop();
    }
}
int main(){
    queue <int> q;
    for(int i=1; i<7; i++)
    q.push(i);
    printQ(q);
    reverseQ(q);
    printQ(q);
    return 0;
}