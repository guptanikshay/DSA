#include <bits/stdc++.h>
using namespace std;

// PS: You are given two arrays of same size and in one operation your are allowed to swap the corresponding elements of these arrays and you are supposed to return the minimum number of swaps required to make these arrays strictly increasing
// RECURSION
int solve(vector<int> &nums1, vector<int> &nums2, int i, bool swapped)
{
    if (i >= nums1.size())
        return 0;
    int ans = INT_MAX;
    int prev1 = nums1[i - 1], prev2 = nums2[i - 1];
    if (swapped)
        swap(prev1, prev2);
    if (nums1[i] > prev1 && nums2[i] > prev2)
        ans = solve(nums1, nums2, i + 1, false);
    if (nums1[i] > prev2 && nums2[i] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, i + 1, true));
    return ans;
}
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    return solve(nums1, nums2, 1, false);
}

// RECURSION WITH MEMOIZATION
int solve(vector<int> &nums1, vector<int> &nums2, int i, int swapped, vector<vector<int>> &dp)
{
    if (i >= nums1.size())
        return 0;
    if (dp[swapped][i] != -1)
        return dp[swapped][i];
    int ans = INT_MAX;
    int prev1 = nums1[i - 1], prev2 = nums2[i - 1];
    if (swapped)
        swap(prev1, prev2);
    if (nums1[i] > prev1 && nums2[i] > prev2)
        ans = solve(nums1, nums2, i + 1, 0, dp);
    if (nums1[i] > prev2 && nums2[i] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, i + 1, 1, dp));
    return dp[swapped][i] = ans;
}
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    vector<vector<int>> dp(2, vector<int>(nums1.size(), -1));
    return solve(nums1, nums2, 1, 0, dp);
}

// TABULATION
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    vector<vector<int>> dp(2, vector<int>(nums1.size() + 1, 0));
    for (int i = nums1.size() - 1; i >= 1; i--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;
            int prev1 = nums1[i - 1], prev2 = nums2[i - 1];
            if (swapped)
                swap(prev1, prev2);
            if (nums1[i] > prev1 && nums2[i] > prev2)
                ans = dp[0][i + 1];
            if (nums1[i] > prev2 && nums2[i] > prev1)
                ans = min(ans, 1 + dp[1][i + 1]);
            dp[swapped][i] = ans;
        }
    }
    return dp[0][1];
}

// TABULATION WITH SPACE OPTIMIZATION
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    vector<int> curr(2, 0), next(2, 0);
    for (int i = nums1.size() - 1; i >= 1; i--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;
            int prev1 = nums1[i - 1], prev2 = nums2[i - 1];
            if (swapped)
                swap(prev1, prev2);
            if (nums1[i] > prev1 && nums2[i] > prev2)
                ans = next[0];
            if (nums1[i] > prev2 && nums2[i] > prev1)
                ans = min(ans, 1 + next[1]);
            curr[swapped] = ans;
        }
        next = curr;
    }
    return curr[0];
}
int main()
{

    return 0;
}