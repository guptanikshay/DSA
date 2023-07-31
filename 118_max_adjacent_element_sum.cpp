#include <bits/stdc++.h>
using namespace std;

// PS: You are given an array of N integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array.
// RECURSIVE SOLUTION
// TC=expo   SC=expo
int solve(vector<int> &nums, int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    return max((solve(nums, n - 2) + nums[n]), solve(nums, n - 1));
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    return solve(nums, nums.size() - 1);
}

// RECURSIVE SOLUTION WITH MEMOIZATION
// TC=O(N)   SC=O(N)
int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    if (dp[n] != -1)
        return dp[n];
    dp[n] = max((solve(nums, n - 2, dp) + nums[n]), solve(nums, n - 1, dp));
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    vector<int> dp(nums.size() + 1, -1);
    return solve(nums, nums.size() - 1, dp);
}

// TABULATION METHOD (TC=O(N), SC=O(N))
int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    return dp[nums.size() - 1];
}

// SPACE OPTIMIZATION
// TC=O(N)  SC=O(1)
int maximumNonAdjacentSum(vector<int> &nums)
{
    int p1 = 0, p2 = nums[0], curr;
    for (int i = 1; i < nums.size(); i++)
    {
        curr = max(p1 + nums[i], p2);
        p1 = p2;
        p2 = curr;
    }
    return curr;
}
int main()
{

    return 0;
}