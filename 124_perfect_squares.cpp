#include <bits/stdc++.h>
using namespace std;

// PS: Given an integer n, return the least number of perfect square numbers that sum to n
// RECURSION
int numSquares(int n)
{
    if (n == 0)
        return 0;
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + numSquares(n - i * i));
    }
    return ans;
}

// RECURSION WITH MEMOIZATION
int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solve(n - i * i, dp));
    }
    dp[n] = ans;
    return dp[n];
}
int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, dp);
    return ans;
}

// TABULATION
int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            if (i >= j * j)
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    return dp[n];
}
int main()
{

    return 0;
}