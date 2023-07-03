#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    char data;
    Node * next;
    Node(char c){
        this->data = c;
        this->next = NULL;
    }
};
class Stack{
    public:
    Node * ll = NULL;
    Node * head = ll;
    void push(char c){
        ll = new Node(c);
        ll->next = head;
        head = ll;
    }
    char pop(){
        if(head==NULL)
        return '\0';
        else{
            char c = head->data;
            Node * t = head;
            head = head->next;
            delete t;
            return c;
        }
    }
};
void reverseByStack(string& s){
    Stack st;
    int i=0;
    while(s[i]!='\0')
        st.push(s[i++]);
    i = 0;
    while(s[i]!='\0')
    s[i] = st.pop(), i++;
}
int main(){
    string str = "swasti";
    cout<<"The string before reversal is "<<str<<"\n";
    reverseByStack(str);
    cout<<"The string after reversal is "<<str<<"\n";
    return 0;
}