#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    int n = q.size();
    stack <int> s;
    for(int i=0; i<k; i++){
        s.push(q.front());
        q.pop();
    }
    for(int i=0; i<k; i++){
        q.push(s.top());
        s.pop();
    }
    for(int i=0; i<n-k; i++){
        int a = q.front();
        q.pop();
        q.push(a);
    }
    return q;
}
int main(){
    
    return 0;
}