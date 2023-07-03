#include <bits/stdc++.h>
using namespace std;

void delMid(stack <int> &s){
    int n = s.size();
    if(n%2!=0)
    n+=1;
    int count = 0;
    stack <int> temp;
    while(count<(n/2)){
    temp.push(s.top()); 
    s.pop(); 
    count++;
    }
    temp.pop();
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}
// Another approach recursive
void solve(stack <int> &s, int count, int size){
    if(count == size/2){
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    solve(s, count+1, size);
    s.push(num);
}
void delMid2(stack <int> &s){
    int n = s.size();
    int count = 0;
    solve(s, count, n);
}

int main(){
    stack <int> st;
    for(int i=1; i<6; i++)
    st.push(i);
    delMid2(st);
    int n = st.size();    
    for(int i=0; i<n; i++){
    cout<<st.top()<<" ";
    st.pop();
    }
    cout<<"\n";
    return 0;
}