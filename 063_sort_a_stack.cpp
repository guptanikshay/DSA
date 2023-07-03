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
void sortedInsert(stack <int> &s, int num){
    if(s.empty() || s.top()<=num){
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(n);
}
void sortStack(stack <int> &s){
    if(s.empty())
    return;
    int num = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, num);
}
int main(){
    stack <int> st;
    st.push(12);
    st.push(-3);
    st.push(0);
    st.push(14);
    st.push(13);
    st.push(8);
    st.push(9);
    st.push(2);
    printStack(st);
    sortStack(st);
    printStack(st);
    return 0;
}