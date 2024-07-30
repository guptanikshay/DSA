#include <bits/stdc++.h>
using namespace std;

// UNIQUE BINARY SEARCH TREES: You are given a natural number, which represents the number of nodes you have and you need to return the number of unique binary search trees you can form with the given nodes. For instance, with three nodes, you can form 5 unique BSTs.
// APPROACH: If we have n nodes and we assume the i'th node as the root node, then on its left it will have i-1 nodes and on its right it will have n-i nodes, and the number of unique BSTs we can form will the product of number of BSTs we can form with i-1 and n-i nodes, which gives us our recursive relation and hence our solution.

// RECURSIVE:
int solve(int n)
{
    if (n <= 1)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i - 1) * solve(n - i);
    }
    return ans;
}
int numTrees(int n)
{
    return solve(n);
}

// RECURSIVE + MEMOIZATION:
int solveMem(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solveMem(i - 1, dp) * solveMem(n - i, dp);
    }
    return dp[n] = ans;
}
int numTrees(int n)
{
    vector<int> dp(n + 1, -1);
    return solveMem(n, dp);
}

// TABULATION
int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
int numTrees(int n)
{
    return solveTab(n);
}

// SPACE OPTIMIZATION: It can be optimized using the Catalan Series. The n'th term of catalan series is (2n)!/((n+1)! * n!)

int main()
{

    return 0;
}