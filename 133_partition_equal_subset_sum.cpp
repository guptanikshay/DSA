#include <bits/stdc++.h>
using namespace std;

// RECURSION
bool solve(int i, int tar, vector<int> &nums, int n)
{
    if (i >= n || tar < 0)
        return false;
    if (tar == 0)
        return true;
    bool incl = solve(i + 1, tar - nums[i], nums, n), excl = solve(i + 1, tar, nums, n);
    return (incl || excl);
}
bool canPartition(vector<int> &nums)
{
    int tar = 0;
    for (int i = 0; i < nums.size(); i++)
        tar += nums[i];
    if (tar % 2 != 0)
        return false;
    tar /= 2;
    return solve(0, tar, nums, nums.size());
}

// RECURSION WITH MEMOIZATION
bool solve(int i, int tar, vector<int> &nums, int n, vector<vector<int>> dp)
{
    if (i >= n || tar < 0)
        return false;
    if (tar == 0)
        return true;
    if (dp[i][tar] != -1)
        return dp[i][tar];
    bool incl = solve(i + 1, tar - nums[i], nums, n, dp), excl = solve(i + 1, tar, nums, n, dp);
    return dp[i][tar] = (incl || excl);
}
bool canPartition(vector<int> &nums)
{
    int tar = 0;
    for (int i = 0; i < nums.size(); i++)
        tar += nums[i];
    if (tar % 2 != 0)
        return false;
    tar /= 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(tar + 1, -1));
    return solve(0, tar, nums, nums.size(), dp);
}

// TABULATION
bool canPartition(vector<int> &nums)
{
    int tar = 0, n = nums.size();
    for (int i = 0; i < nums.size(); i++)
        tar += nums[i];
    if (tar % 2 != 0)
        return false;
    tar /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int t = 1; t <= tar; t++)
        {
            bool incl = false;
            if (t - nums[i] >= 0)
                incl = dp[i + 1][t - nums[i]];
            bool excl = dp[i + 1][t];
            dp[i][t] = (incl || excl);
        }
    }
    return dp[0][tar];
}

// SPACE OPTIMIZATION
bool canPartition(vector<int> &nums)
{
    int tar = 0, n = nums.size();
    for (int i = 0; i < nums.size(); i++)
        tar += nums[i];
    if (tar % 2 != 0)
        return false;
    tar /= 2;
    vector<int> curr(tar + 1, 0), next(tar + 1, 0);
    curr[0] = next[0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int t = 1; t <= tar; t++)
        {
            bool incl = false;
            if (t - nums[i] >= 0)
                incl = next[t - nums[i]];
            bool excl = next[t];
            curr[t] = (incl || excl);
        }
        next = curr;
    }
    return curr[tar];
}
int main()
{

    return 0;
}