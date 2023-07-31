#include <bits/stdc++.h>
using namespace std;

// DYNAMIC PROGRAMMING: It is applied when the below two conditions are satisfied:-   1. The optimal solution of a bigger problem can be found using the optimal solution of its sub problems    2. Overlapping sub problems should be present in the problem

// RECURSIVE AND MEMOIZATION SOLUTION OF NTH FIBONACCI NUMBER (TOP DOWN APPROACH)
int solve(int n, vector<int> &dpArr)
{
    if (n == 0 || n == 1)
        return n;
    if (dpArr[n] != -1)
        return dpArr[n];
    dpArr[n] = solve(n - 1, dpArr) + solve(n - 2, dpArr);
    return dpArr[n];
}
int fib(int n)
{
    vector<int> dpArr(n + 1, -1);
    return solve(n, dpArr);
}

// BOTTOM UP APPROACH OR TABULATION METHOD
int fib(int n)
{
    if (n <= 1)
        return n;
    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// SPACE OPTIMIZATION
int fib(int n)
{
    if (n <= 1)
        return n;
    int curr, p1 = 0, p2 = 1;
    for (int i = 2; i <= n; i++)
    {
        curr = p1 + p2;
        p1 = p2;
        p2 = curr;
    }
    return curr;
}
int main()
{

    return 0;
}