// Question: Insert the given element at the bottom of the stack
#include <bits/stdc++.h>
using namespace std;
void printStack(stack <int> s){
    int n = s.size();
    for(int i=0; i<n; i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void insertAtBottom(stack <int> &s, int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s, ele);
    s.push(num);
}
int main(){
    stack <int> st;
    for(int i=10; i<70; i+=10)
    st.push(i);
    printStack(st);
    insertAtBottom(st, 1);
    printStack(st);
    return 0;
}