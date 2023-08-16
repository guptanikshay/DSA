// PATTERN OF THIS TYPE OF DP QUESTIONS = NO. OF DISTINCT WAYS
// NUMBER OF DICE ROLLS WITH TARGET SUM: In this question you are given 'n' dice with 'k' faces and a 'target' and you are supposed to find out the number of distinct ways to make the sum on the faces of dice equal to target.
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// RECURSION
long long solve(int dice, int faces, int target)
{
    if (target < 0 || (dice == 0 && target != 0) || (dice != 0 && target == 0))
        return 0;
    if (!dice && !target)
        return 1;
    long long ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans += solve(dice - 1, faces, target - i);
    }
    return ans;
}
int numRollsToTarget(int n, int k, int target)
{
    long long ans = solve(n, k, target);
    return (ans % (1000000007));
}

// RECURSION WITH MEMOIZATION
long long solve(int dice, int faces, int target, vector<vector<long long>> &dp)
{
    if (target < 0 || (dice == 0 && target != 0) || (dice != 0 && target == 0))
        return 0;
    if (!dice && !target)
        return 1;
    if (dp[dice][target] != -1)
        return dp[dice][target];
    long long ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans = (ans % MOD) + (solve(dice - 1, faces, target - i, dp) % MOD);
        ans %= MOD;
    }

    return dp[dice][target] = ans;
}
int numRollsToTarget(int n, int k, int target)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
    long long ans = solve(n, k, target, dp);
    return (ans % (MOD));
}

// BOTTOM UP APPROACH
int numRollsToTarget(int n, int k, int target) // TC=O(n*target*k)  SC=O(n*target)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
    dp[0][0] = 1;
    for (int dice = 1; dice <= n; dice++)
    {
        for (int t = 0; t <= target; t++)
        {
            long long ans = 0;
            for (int i = 1; i <= k; i++)
            {
                if (t - i >= 0)
                    ans += (dp[dice - 1][t - i] % MOD);
                ans %= MOD;
            }
            dp[dice][t] = ans;
        }
    }
    return dp[n][target];
}

// SPACE OPTIMIZED APPROACH
int numRollsToTarget(int n, int k, int target)
{
    vector<long long> prev(target + 1, 0);
    vector<long long> curr(target + 1, 0);
    prev[0] = 1;
    for (int dice = 1; dice <= n; dice++)
    {
        for (int t = 0; t <= target; t++)
        {
            long long ans = 0;
            for (int i = 1; i <= k; i++)
            {
                if (t - i >= 0)
                    ans += (prev[t - i] % MOD);
                ans %= MOD;
            }
            curr[t] = ans;
        }
        prev = curr;
    }
    return curr[target];
}
int main()
{

    return 0;
}