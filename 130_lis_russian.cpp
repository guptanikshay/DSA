#include <bits/stdc++.h>
using namespace std;

// LONGEST INCREASING SUBSEQUENCE
// PS: You are supposed to find the longest strictly increasing subsequence in the given array.

// RECURSION
int solve(vector<int> &nums, int index, int last)
{
    if (index == nums.size())
        return 0;
    int incl = 0;
    if (last == -1 || nums[last] < nums[index])
        incl = 1 + solve(nums, index + 1, index);
    int excl = solve(nums, index + 1, last);
    return max(incl, excl);
}
int lengthOfLIS(vector<int> &nums)
{
    return solve(nums, 0, -1);
}

// RECURSION WITH MEMOIZATION TC=O(N^2)  SC=O(N^2)
int solve(vector<int> &nums, int index, int last, vector<vector<int>> &dp)
{
    if (index == nums.size())
        return 0;
    if (dp[index][last + 1] != -1) // Considering last+1 here because -1 is not a valid index
        return dp[index][last + 1];
    int incl = 0;
    if (last == -1 || nums[last] < nums[index])
        incl = 1 + solve(nums, index + 1, index, dp);
    int excl = solve(nums, index + 1, last, dp);
    return dp[index][last + 1] = max(incl, excl);
}
int lengthOfLIS(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    return solve(nums, 0, -1, dp);
}

// TABULATION
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int last = index - 1; last >= -1; last--)
        {
            int incl = 0;
            if (last == -1 || nums[last] < nums[index])
                incl = 1 + dp[index + 1][index + 1];
            int excl = dp[index + 1][last + 1];
            dp[index][last + 1] = max(incl, excl);
        }
    }
    return dp[0][0];
}

// TABULATION WITH SPACE OPTIMIZATION
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int last = index - 1; last >= -1; last--)
        {
            int incl = 0;
            if (last == -1 || nums[last] < nums[index])
                incl = 1 + next[index + 1];
            int excl = next[last + 1];
            curr[last + 1] = max(incl, excl);
        }
        next = curr;
    }
    return next[0];
}

// EVEN MORE OPTIMAL SOLN USING DP WITH BINARY SEARCH
// TC=O(N logN)   SC=O(N)
int lengthOfLIS(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    vector<int> res;
    res.push_back(nums[0]);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > res.back())
            res.push_back(nums[i]);
        else
        {
            int lb = lower_bound(res.begin(), res.end(), nums[i]) - res.begin(); // returns the index of element just bigger than nums[i]
            res[lb] = nums[i];
        }
    }
    return res.size();
}

// RUSSIAN DOLL ENVELOPES
// void hwSort(vector<vector<int>> &envelopes, int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int j = i - 1, w = envelopes[i][0], h = envelopes[i][1];
//         while (j >= 0 && envelopes[j][0] >= w)
//         {
//             if (envelopes[j][0] > w || envelopes[j][1] > h)
//             {
//                 envelopes[j + 1][0] = envelopes[j][0];
//                 envelopes[j + 1][1] = envelopes[j][1];
//             }
//             j--;
//         }
//         envelopes[j + 1][0] = w, envelopes[j + 1][1] = h;
//     }
// }
// int maxEnvelopes(vector<vector<int>> &envelopes)
// {
//     int n = envelopes.size();
//     if (n == 0)
//         return 0;
//     hwSort(envelopes, n);
//     vector<int> ans;
//     ans.push_back(envelopes[0][1]);
//     for (int i = 1; i < n; i++)
//     {
//         if (envelopes[i][1] > ans.back())
//             ans.push_back(envelopes[i][1]);
//         else
//         {
//             int lb = lower_bound(ans.begin(), ans.end(), envelopes[i][1])-ans.begin();
//             ans[lb] = envelopes[i][1];
//         }
//     }
//     return ans.size();
// }
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    if (n == 0)
        return 0;
    sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });
    vector<int> ans;
    ans.push_back(envelopes[0][1]);
    for (int i = 1; i < n; i++)
    {
        if (envelopes[i][1] > ans.back())
            ans.push_back(envelopes[i][1]);
        else
        {
            int lb = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
            ans[lb] = envelopes[i][1];
        }
    }
    return ans.size();
}
int main()
{

    return 0;
}