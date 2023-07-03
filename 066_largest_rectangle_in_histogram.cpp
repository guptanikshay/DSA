#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallEle(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
            st.pop();
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallEle(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
            st.pop();
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    vector<int> prev(n);
    next = nextSmallEle(heights, n);
    prev = prevSmallEle(heights, n);
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int a = heights[i], b;
        if (next[i] == -1)
            next[i] = n;
        b = next[i] - prev[i] - 1;
        int newArea = a * b;
        area = max(newArea, area);
    }
    return area;
}
int main()
{
    vector<int> heights;
    heights.push_back(0);
    heights.push_back(1);
    cout << largestRectangleArea(heights);
    return 0;
}