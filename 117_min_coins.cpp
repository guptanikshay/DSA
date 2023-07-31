#include <bits/stdc++.h>
using namespace std;

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.Return the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins, return -1

// RECURSIVE APPROACH
// TC=exponential   SC=expo
int solve(vector<int> &coins, int amt)
{
    if (amt == 0)
        return 0;
    if (amt < 0)
        return INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve(coins, amt - coins[i]);
        if (ans != INT_MAX)
            mini = min(1 + ans, mini);
    }
    return mini;
}
int coinChange(vector<int> &coins, int amount)
{
    int ans = solve(coins, amount);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

// RECURSIVE APPROACH WITH MEMOIZATION (TOP DOWN APPROACH)
// TC=O(amt*coins)   SC=O(amt)
int solve(vector<int> &coins, int amt, vector<int> &dp)
{
    if (amt == 0)
        return 0;
    if (amt < 0)
        return INT_MAX;
    if (dp[amt] != -1)
        return dp[amt];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve(coins, amt - coins[i], dp);
        if (ans != INT_MAX)
            mini = min(1 + ans, mini);
    }
    dp[amt] = mini;
    return mini;
}
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    int ans = solve(coins, amount, dp);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

// TABULATION METHOD OR BOTTOM DOWN APPROACH
// TC=O(amt*coins)   SC=O(amt)
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    if (dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

// Space optimization is not possible here as we will again need the same no. of variables to store previous values as dp[i] might depend on any of the following parameters ranging from dp[i-1] to dp[i-coins.size()]
int main()
{

    return 0;
}