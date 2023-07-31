#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

// NINJA AND THE FENCE
// PS:- Ninja is has a fence and he is given the task to paint this fence. The fence has N posts and ninja has K colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color. Find the number of ways of doing this task.
// Approach: Consider the case that we have 2 posts and 2 colors, then we need to find the number of ways when the last 2 posts have the same color (3 ways) and the number of ways when the last 2 posts have different color (6 ways (k*(k-1))). Hence total number of painting 2 posts with k colors = k+k(k-1).
// Now if we have 3 posts and k colors, then the number of ways such that last 2 posts have same color = k(k-1) and number of ways such that last two posts have same color = (k+k(k-1))(k-1)
// Now you get the idea, that for last two posts (out of n posts) to have same color, we just pick the answer of n-1 case when last two posts have different color and add the same color as last post at the end to get the number of ways (= number ways of painting n-1 posts such that last two posts have different color)
// For the last 2 posts to have different color, we pick all the cases from n-1 and add any color to its end other than its last color (k-1 options), so total number of ways become (k-1)*solve(n-1)
// RECURSION
int numberOfWays(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return ((k % M) + (k % M) * ((k - 1) % M)) % M;
    return ((numberOfWays(n - 2, k) % M + numberOfWays(n - 1, k) % M) * (k - 1)) % M;
}

// RECURSION WITH MEMOIZATION
int solve(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return (k + (k % M) * (k - 1) % M) % M;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = ((solve(n - 2, k, dp) * 1LL % M + solve(n - 1, k, dp) * 1LL % M) * (k - 1)) % M;
    return dp[n];
}
int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, k, dp);
    return ans;
}

// TABULATION METHOD
int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = (k + (k % M) * (k - 1) % M) % M;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 2] * 1LL % M + dp[i - 1] * 1LL % M) * (k - 1)) % M;
    }
    return dp[n];
}

// TABULATION WITH SPACE OPTIMIZATION
int numberOfWays(int n, int k)
{
    if (n == 1)
        return k;
    int p1 = k, p2 = (k + (k % M) * (k - 1) % M) % M, curr;
    if (n == 2)
        return p2;
    for (int i = 3; i <= n; i++)
    {
        curr = ((p1 * 1LL % M + p2 * 1LL % M) * (k - 1)) % M;
        p1 = p2;
        p2 = curr;
    }
    return curr;
}
int main()
{

    return 0;
}