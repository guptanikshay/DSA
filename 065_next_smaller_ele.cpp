// Given an array, find the next smaller element for a corresponding element, if not found, return -1. For instance, given array is [2, 1, 4, 3], the answer array would be [1, -1, 3, -1]
#include <bits/stdc++.h>
using namespace std;

// Brute Force (TC = O(n^2))
vector<int> nextSmallEle(vector<int> arr, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                ans.push_back(arr[j]);
                found = 1;
                break;
            }
        }
        if (!found)
            ans.push_back(-1);
    }
    return ans;
}

// Optimal Approach using Stack (TC = O(n))
vector<int> nextSmallEle2(vector<int> arr, int n)
{
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() >= arr[i])
            st.pop();
        ans.push_back(st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {2, 1, 4, 3};
    vector<int> ans = nextSmallEle2(arr, 4);
    for (int i = 0; i < 4; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}