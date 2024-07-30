#include <bits/stdc++.h>
using namespace std;

// BEST TIME TO BUY AND SELL STOCK PART 1: You are given an array prices that consists of the prices of a stock at respective days. You will buy the stock at a day and sell it on a day after that and make some profit. You need to return the maximum amount of profit you can make.
// APPROACH: We consider a particular day as the day of selling, so we obviously would have bought on a day before when the price was minimum, and hence we keep track of the day when the price was minimum. We mark the day 1 price as minimum price and start traversing from day 2.
// ITERATIVE CODE:
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int mini = prices[0], profit = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = prices[i] - mini;
        profit = max(diff, profit);
        mini = min(prices[i], mini);
    }
    return profit;
}

// BEST TIME TO BUY AND SELL STOCK PART 2: Same question, only difference is that you are allowed to buy and sell multiple times, unlike the last one where it was allowed only once. Note that we cannot buy another share if we have already bought one, we cannot buy again and again, if once bought, only thing we can do is sell.
// APPROACH: At every price, we have 3 options, either we can ignore it, buy it, or sell it. Buying and selling depend on the buy variable, if buy is 1, it means we are only allowed to buy and if buy is 0 then we are only allowed to sell. So at every index, we will calculate the answer for buying/selling or ignoring and will take the maximum of it. If we buy at a price, that price gets subtracted from our profit and if we sell at a price that price gets added to our profit.
// RECURSION
int solve(vector<int> &prices, int i, int buy)
{
    if (i == prices.size())
        return 0;
    int profit = 0;
    if (buy)
        profit = max(solve(prices, i + 1, 1), -prices[i] + solve(prices, i + 1, 0));
    else
        profit = max(solve(prices, i + 1, 0), prices[i] + solve(prices, i + 1, 1));
    return profit;
}
int maxProfit(vector<int> &prices)
{
    return solve(prices, 0, 1);
}

// RECURSION + MEMOIZATION
int solve(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
{
    if (i == prices.size())
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    int profit = 0;
    if (buy)
        profit = max(solve(prices, i + 1, 1, dp), -prices[i] + solve(prices, i + 1, 0, dp));
    else
        profit = max(solve(prices, i + 1, 0, dp), prices[i] + solve(prices, i + 1, 1, dp));
    return dp[i][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}

// TABUALTION
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(dp[i + 1][1], -prices[i] + dp[i + 1][0]);
            else
                profit = max(dp[i + 1][0], prices[i] + dp[i + 1][1]);
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}
// SPACE OPTIMIZATION
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<int> next(2, 0), curr(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(next[1], -prices[i] + next[0]);
            else
                profit = max(next[0], prices[i] + next[1]);
            curr[buy] = profit;
        }
        next = curr;
    }
    return curr[1];
}
int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}

// BEST TIME TO BUY AND SELL STOCK PART 3: Same problem, the catch is that you are only allowed to make the transaction atmost twice, i.e., you are only allowed to buy and sell the stocks atmost twice.
// APPROACH: We include one more variable that keeps a count of transactions until now and when it crosses the limit we simply return 0.
// RECURSIVE
int solve(vector<int> &prices, int i, int buy, int tran)
{
    if (i >= prices.size() || tran >= 2)
        return 0;
    int profit = 0;
    if (buy)
        profit = max(-prices[i] + solve(prices, i + 1, 0, tran), solve(prices, i + 1, 1, tran));
    else
        profit = max(prices[i] + solve(prices, i + 1, 1, tran + 1), solve(prices, i + 1, 0, tran));
    return profit;
}
int maxProfit(vector<int> &prices)
{
    return solve(prices, 0, 1, 0);
}

// RECURSIVE + MEMOIZATION
int solve(vector<int> &prices, int i, int buy, int tran, vector<vector<vector<int>>> &dp)
{
    if (i >= prices.size() || tran >= 2)
        return 0;
    if (dp[i][buy][tran] != -1)
        return dp[i][buy][tran];
    int profit = 0;
    if (buy)
        profit = max(-prices[i] + solve(prices, i + 1, 0, tran, dp), solve(prices, i + 1, 1, tran, dp));
    else
        profit = max(prices[i] + solve(prices, i + 1, 1, tran + 1, dp), solve(prices, i + 1, 0, tran, dp));
    return dp[i][buy][tran] = profit;
}
int maxProfit(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    return solve(prices, 0, 1, 0, dp);
}
// TABULATION
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int tran = 1; tran >= 0; tran--)
            {
                int profit = 0;
                if (buy)
                    profit = max(-prices[i] + dp[i + 1][0][tran], dp[i + 1][1][tran]);
                else
                    profit = max(prices[i] + dp[i + 1][1][tran + 1], dp[i + 1][0][tran]);
                dp[i][buy][tran] = profit;
            }
        }
    }
    return dp[0][1][0];
}
int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}
// SPACE OPTIMIZATION
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int tran = 1; tran >= 0; tran--)
            {
                int profit = 0;
                if (buy)
                    profit = max(-prices[i] + next[0][tran], next[1][tran]);
                else
                    profit = max(prices[i] + next[1][tran + 1], next[0][tran]);
                curr[buy][tran] = profit;
            }
        }
        next = curr;
    }
    return curr[1][0];
}
int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}

// BEST TIME TO BUY AND SELL STOCK PART 4: Same as 3, catch is that you are allowed to make the transaction only k times, so we simply replace 2 by k in above solution
// SPACE OPTIMIZATION
int solveTab(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int tran = k - 1; tran >= 0; tran--)
            {
                int profit = 0;
                if (buy)
                    profit = max(-prices[i] + next[0][tran], next[1][tran]);
                else
                    profit = max(prices[i] + next[1][tran + 1], next[0][tran]);
                curr[buy][tran] = profit;
            }
        }
        next = curr;
    }
    return curr[1][0];
}
int maxProfit(int k, vector<int> &prices)
{
    return solveTab(prices, k);
}

// BEST TIME TO BUY AND SELL STOCK WITH TRANSACTION FEE: Similar question, transaction allowed multiple times, catch is that your are supposed to pay transaction fee every time you sell the stock
// RECURSION
int solve(vector<int> &prices, int fee, int i, int buy)
{
    if (i == prices.size())
        return 0;
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(prices, fee, i + 1, 0), solve(prices, fee, i + 1, 1));
    }
    else
        profit = max(prices[i] - fee + solve(prices, fee, i + 1, 1), solve(prices, fee, i + 1, 0));
    return profit;
}
int maxProfit(vector<int> &prices, int fee)
{
    return solve(prices, fee, 0, 1);
}
// RECURSION+MEMOIZATION
int solve(vector<int> &prices, int fee, int i, int buy, vector<vector<int>> &dp)
{
    if (i == prices.size())
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(prices, fee, i + 1, 0, dp), solve(prices, fee, i + 1, 1, dp));
    }
    else
        profit = max(prices[i] - fee + solve(prices, fee, i + 1, 1, dp), solve(prices, fee, i + 1, 0, dp));
    return dp[i][buy] = profit;
}
int maxProfit(vector<int> &prices, int fee)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return solve(prices, fee, 0, 1, dp);
}
// TABULATION
int solveTab(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            else
                profit = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int> &prices, int fee)
{
    return solveTab(prices, fee);
}
// SPACE OPTIMIZATION
int solveTab(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<int> next(2, 0), curr(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[i] + next[0], next[1]);
            else
                profit = max(prices[i] - fee + next[1], next[0]);
            curr[buy] = profit;
        }
        next = curr;
    }
    return curr[1];
}
int maxProfit(vector<int> &prices, int fee)
{
    return solveTab(prices, fee);
}

// BEST TIME TO BUY AND SELL STOCK WITH COOLDOWN: Catch is that you cannot buy the stock on the next day after selling it, i.e., there is cooldown phase of 1 day. So we simply move the index by two places after selling.
// RECURSION
int solve(vector<int> &prices, int i, int buy)
{
    if (i >= prices.size())
        return 0;
    int profit = 0;
    if (buy)
        profit = max(-prices[i] + solve(prices, i + 1, 0), solve(prices, i + 1, 1));
    else
        profit = max(prices[i] + solve(prices, i + 2, 1), solve(prices, i + 1, 0));
    return profit;
}
int maxProfit(vector<int> &prices)
{
    return solve(prices, 0, 1);
}
// RECURSIVE + MEMOIZATION
int solve(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
{
    if (i >= prices.size())
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    int profit = 0;
    if (buy)
        profit = max(-prices[i] + solve(prices, i + 1, 0, dp), solve(prices, i + 1, 1, dp));
    else
        profit = max(prices[i] + solve(prices, i + 2, 1, dp), solve(prices, i + 1, 0, dp));
    return dp[i][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}
// TABULATION
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            else
                profit = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}
// SPACE OPTIMIZATION
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<int> next(2, 0), curr(2, 0), prev(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[i] + curr[0], curr[1]);
            else
                profit = max(prices[i] + next[1], curr[0]);
            prev[buy] = profit;
        }
        next = curr;
        curr = prev;
    }
    return prev[1];
}
int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}
int main()
{

    return 0;
}