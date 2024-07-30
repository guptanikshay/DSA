#include <bits/stdc++.h>
using namespace std;

// PS: Given an array, you are supposed to find the longest arithmetic progression in it.

// // MY APPROACH: The idea is to find the difference between all the elements of the array and keep count of the number of same differences and the one with the highest count will be our answer.
// int longestArithSeqLength(vector<int> &nums)
// {
//     int n = nums.size(), ans = 0, diff;
//     unordered_map<int, int> count;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             diff = nums[i] - nums[j];
//             count[diff]++;
//             ans = max(ans, count[diff]);
//         }
//     }
//     return ans + 1;
// } --> Wrong answer, because numbers with same difference might be present at location where they are not forming an array.

// BRUTE FORCE: The logic is almost same as above approach, the only difference is that we are not using map in this one. We take two numbers, consider them as the last elements of an AP and check whether the elements present before them have the same common difference as these two and we keep updating the max AP length found
int solve(int index, int diff, vector<int> &nums)
{
    int ans = 0;
    for (int i = index - 1; i >= 0; i--)
    {
        if (nums[index] - nums[i] == diff)
        {
            ans = max(ans, 1 + solve(i, diff, nums));
        }
    }
    return ans;
}
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums));
        }
    }
    return ans;
}

// MEMOIZATION
// dp[index][diff] represents the longest length of AP with difference diff at this index.
int solve(int index, int diff, vector<int> &nums, unordered_map<int, int> dp[])
{
    int ans = 0;
    if (dp[index].count(diff))
        return dp[index][diff];
    for (int i = index - 1; i >= 0; i--)
    {
        if (nums[index] - nums[i] == diff)
        {
            ans = max(ans, 1 + solve(i, diff, nums, dp));
        }
    }
    return dp[index][diff] = ans;
}
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    int ans = 0;
    unordered_map<int, int> dp[n + 1]; // Here every dp[i] stores a map which in turn stores differences with length counts, i.e., we have a data structure that stores length of longest arithemetic sequences of every possible common difference at every index.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums, dp));
        }
    }
    return ans;
}

// TABULATION
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size(), ans = 0;
    unordered_map<int, int> dp[n + 1];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            int cnt = 1;
            if (dp[j].count(diff)) // will return 1 or 0, depending on the exitence of diff in dp[j]
                cnt = dp[j][diff];
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

// SPACE OPTIMIZATION: The hint was to used the a+c=2b formula and finding a length 3 AP in a sorted sequence. Find the solution.

int main()
{

    return 0;
}