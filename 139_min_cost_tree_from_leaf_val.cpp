#include <bits/stdc++.h>
using namespace std;

// MINIMUM COST TREE FROM LEAF VALUES: You are given an array which represents the nodes of binary tree in an in-order traversal. The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively. Each node has either 0 or 2 children. Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.

// APPROACH: If we have 2 nodes, the answer is simply their product. If we have 3 nodes, then we can either consider the root node to be between 1st and 2nd node or we can consider the root node to be between 2nd and 3rd node and this way we will get two answers and the minimum of them will be our final answer. So basically we have a range of numbers and we need to find the answer in that, so we divide the range in two parts between every gap, i.e., 0-1, 1-2, 2-3, ... etc and calculate the answer. For instance, for the range [i, j], our answer for the first gap will be maxi(arr, start, i) * maxi(arr, i + 1, end) + solve(arr, start, i) + solve(arr, i + 1, end).

// RECURSION:
int maxi(vector<int> &arr, int start, int end)
{
    int maxi = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}
int solve(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return 0;
    if (start + 1 == end)
        return arr[start] * arr[end];
    int ans = 1e9;
    for (int i = start; i < end; i++)
    {
        ans = min(ans, (maxi(arr, start, i) * maxi(arr, i + 1, end) + solve(arr, start, i) + solve(arr, i + 1, end)));
    }
    return ans;
}
int mctFromLeafValues(vector<int> &arr)
{
    return solve(arr, 0, arr.size() - 1);
}

// RECURSION + MEMOIZATION
int maxi(vector<int> &arr, int start, int end)
{
    int maxi = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}
int solve(vector<int> &arr, int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
        return 0;
    if (start + 1 == end)
        return arr[start] * arr[end];
    if (dp[start][end] != -1)
        return dp[start][end];
    int ans = 1e9;
    for (int i = start; i < end; i++)
    {
        ans = min(ans, (maxi(arr, start, i) * maxi(arr, i + 1, end) + solve(arr, start, i, dp) + solve(arr, i + 1, end, dp)));
    }
    return dp[start][end] = ans;
}
int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(arr, 0, n - 1, dp);
}

// TABULATION
int maxi(vector<int> &arr, int start, int end)
{
    int maxi = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}
int solveTab(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = arr[i] * arr[i + 1];
    }

    for (int length = 2; length < n; length++)
    {
        for (int start = 0; start + length < n; start++)
        {
            int end = start + length;
            dp[start][end] = 1e9;
            for (int i = start; i < end; i++)
            {
                int cost = maxi(arr, start, i) * maxi(arr, i + 1, end) + dp[start][i] + dp[i + 1][end];
                dp[start][end] = min(dp[start][end], cost);
            }
        }
    }

    return dp[0][n - 1];
}
int mctFromLeafValues(vector<int> &arr)
{
    return solveTab(arr);
}
int main()
{

    return 0;
}