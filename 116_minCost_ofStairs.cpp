#include <bits/stdc++.h>
using namespace std;

// PS:- In this problem, we are supposed to find the minimum cost of climbing n stairs, where in one go we are allowed to climb 1 or 2 stairs by paying the cost associated with each stair.

// RECURSIVE APPROACH
int solve(vector<int> &cost, int n)
{
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];
    return cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    return min(solve(cost, n - 1), solve(cost, n - 2));
}

// RECURSIVE APPROACH WITH MEMOIZATION (TOP DOWN)
int solve(vector<int> &cost, int n, vector<int> &dp)
{
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];
    if (dp[n] != -1)
        return dp[n];
    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
}

// BOTTOM UP APPROACH OR TABULATION METHOD
int solve(vector<int> &cost, int n)
{
    vector<int> dp(n + 1);
    dp[0] = cost[0], dp[1] = cost[1];
    for (int i = 2; i < n; i++)
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    return min(dp[n - 1], dp[n - 2]);
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    return solve(cost, n);
}

// BOTTOM UP APPROACH WITH SPACE OPTIMIZATION
int solve(vector<int> &cost, int n)
{
    int p1 = cost[0], p2 = cost[1], curr;
    for (int i = 2; i < n; i++)
    {
        curr = cost[i] + min(p1, p2);
        p1 = p2;
        p2 = curr;
    }
    return min(p1, p2);
}
int minCostClimbingStairs(vector<int> &cost)
{
    return solve(cost, cost.size());
}
int main()
{

    return 0;
}