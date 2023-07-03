#include <bits/stdc++.h>
using namespace std;
class MinStack {
    stack <long long int> s;
    long long int mini;
public:
    MinStack() {

    }
    
    void push(long long int val) {
        if(s.empty()){
            mini = val;
            s.push(val);
        }
        else{
            if(val<mini){
                s.push(2*val - mini);
                mini = val;
            }
            else
            s.push(val);
        }
    }
    
    void pop() {
        if(s.empty())
        return;
        if(s.top()>=mini)
        s.pop();
        else{
            mini = 2*mini - s.top();
            s.pop();
        }
    }
    
    long long int top() {
        if(s.top()>=mini)
        return s.top();
        else{
            return mini;
        }
    }
    
    long long int getMin() {
        return mini;
    }
};

int main(){
    
    return 0;
}