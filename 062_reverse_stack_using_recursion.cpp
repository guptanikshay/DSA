#include <bits/stdc++.h>
using namespace std;
void printStack(stack<int> s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void insertAtBottom(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s, ele);
    s.push(num);
}
void revStack(stack<int> &s)
{
    if (s.empty())
        return;
    int num = s.top();
    s.pop();
    revStack(s);
    insertAtBottom(s, num);
}
int main()
{
    stack<int> st;
    for (int i = 0; i < 15; i += 2)
        st.push(i);
    printStack(st);
    revStack(st);
    printStack(st);
    return 0;
}