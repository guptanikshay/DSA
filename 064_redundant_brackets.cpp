#include <bits/stdc++.h>
using namespace std;
bool isOp(char c){
    if(c =='+' || c =='-' || c =='*' || c =='/')
    return true;
    return false;
}
bool redundantB(string s){
    stack <char> st;
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='(' || isOp(s[i]))
        st.push(s[i]);
        else if(s[i]==')'){
            if(st.empty() || !isOp(st.top()))
            return true;
            else{
            while(!st.empty() && isOp(st.top()))
            st.pop();
            }
        }
    }
    return false;
}
int main(){
    string str = "(((a+b+e)*c)+d)+g";
    if(redundantB(str))
    cout<<"It contains redundant brackets\n";
    else
    cout<<"It does not contain redundant brackets\n";
    return 0;
}