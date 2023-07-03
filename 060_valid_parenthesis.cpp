#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ']')
        {
            if (st.top() == '[')
                st.pop();
            else
                return false;
        }
        else if (s[i] == '}')
        {
            if (st.top() == '{')
                st.pop();
            else
                return false;
        }
        else
        {
            if (st.top() == '(')
                st.pop();
            else
                return false;
        }
    }
    if(st.empty())
    return true;
    return false;
}
int main()
{
    string s = "[[({[()]})]]";
    if (isValid(s))
        cout << "Valid parentheses\n";
    else
        cout << "Invalid parentheses\n";
    return 0;
}