#include <bits/stdc++.h>
using namespace std;

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// RECURSION
int solve(vector<int> &nums, int tar)
{
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        res += solve(nums, tar - nums[i]);
    }
    return res;
}
int combinationSum4(vector<int> &nums, int target)
{
    return solve(nums, target);
}

// RECURSION WITH MEMOIZATION
int solve(vector<int> &nums, int tar, vector<int> &dp)
{
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;
    if (dp[tar] != 0)
        return dp[tar];
    for (int i = 0; i < nums.size(); i++)
    {
        dp[tar] += solve(nums, tar - nums[i], dp);
    }
    return dp[tar];
}
int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, 0);
    int ans = solve(nums, target, dp);
    return ans;
}

// TABULATIION METHOD
int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < nums.size(); j++)
            if (i - nums[j] >= 0)
                dp[i] += dp[i - nums[j]];
    }
    return dp[target];
}

// TABULATION WITH SPACE OPTIMIZATION: It is not possible here as dp[i] depends on a range of numbers
int main()
{

    return 0;
}