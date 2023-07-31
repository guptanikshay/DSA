#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

// A Derangement is a permutation of 'n' elements such that no element appears in its original position.
// PS:- GIVEN A NUMBER N, FIND THE TOTAL NUMBER OF DERANGEMENTS POSSIBLE OF A SET OF N ELEMENTS
// RECURSION TC=expo SC=expo
long long int countDerangements(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return (((n - 1) % M) * ((countDerangements(n - 1) % M) + (countDerangements(n - 2) % M))) % M;
}

// RECURSION WITH MEMOIZATION TC=O(N)  SC=O(N)
long long solve(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = ((n - 1) % M * (solve(n - 1, dp) % M + solve(n - 2, dp) % M)) % M;
    return dp[n];
}
long long int countDerangements(int n)
{
    vector<long long int> dp(n + 1, -1);
    long long ans = solve(n, dp);
    return ans;
}

// TABULATION  TC=O(N)  SC=O(N)
long long int countDerangements(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0, dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((i - 1) * (dp[i - 1] % M + dp[i - 2] % M) % M) % M;
    }
    return dp[n];
}

// TABULATION WITH SPACE OPTIMIZATON TC=O(N)  SC=O(1)
long long int countDerangements(int n)
{
    if (n == 1 || n == 2)
        return n - 1;
    long long int p1 = 0, p2 = 1, curr;
    for (int i = 3; i <= n; i++)
    {
        curr = ((i - 1) * ((p1 % M + p2 % M)) % M) % M;
        p1 = p2;
        p2 = curr;
    }
    return curr;
}
int main()
{

    return 0;
}