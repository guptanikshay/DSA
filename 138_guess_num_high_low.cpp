#include <bits/stdc++.h>
using namespace std;

// GUESS NUMBER HIGHER OR LOWER: You have a range (1 -> N). We are playing the number guessing game, where the computer will pick a number from the given range and you need to guess it, and you will pay 'i' dollars to computer for every wrong guess 'i' and you'll lose if you run out of money. You need to find the minimum amount of money to successfully guess the number without running out of money. Basically, we need to find the minimum amount we need to ensure that we will be able guess the number regardless of the computer's pick.

// RECURSIVE APPROACH: We don't know what the computer will pick, so we consider every case from 1 to N. Now we consider a start point, lets say 1, and then we calculate the minimum cost required to guess every number from 1->N when the starting point is 1, and take the maximum value of all those costs, which is our answer for 1. Similarly we calculate the answer for 2->N, i.e., the cost of all reaching all the values from starting point 2 and so on, and then take the minimum of all these costs, which is our final answer, and also gives us the most optimal starting point.
int solve(int start, int end)
{
    if (start >= end)
        return 0;
    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solve(start, i - 1), solve(i + 1, end)));
    }
    return ans;
}
int getMoneyAmount(int n)
{
    return solve(1, n);
}

// RECURSIVE + MEMOIZATION
int solve(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];
    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
    }
    return dp[start][end] = ans;
}
int getMoneyAmount(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(1, n, dp);
}

// TABULATION
int solveTab(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int start = n; start > 0; start--)
    {
        for (int end = start + 1; end <= n; end++)
        {
            int ans = INT_MAX;
            for (int i = start; i <= end; i++)
            {
                ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
            }
            dp[start][end] = ans;
        }
    }
    return dp[1][n];
}
int getMoneyAmount(int n)
{
    return solveTab(n);
}
int main()
{

    return 0;
}