#include <bits/stdc++.h>
using namespace std;
/*
 Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).
 */
// Basically you'll have two strings, str and pattern and you're supposed to check whether the pattern matches the str or not. The pattern may contain a '?' and a '*', where the '?' matches with any single character and '*' matches with any sequence of characters.
// MY APPROACH: Didn't work as I was traversing the str and pattern from start, they should be traversed from the end.
bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{
    if (i <= -1 && j <= -1)
        return true;
    if (i <= -1 || j <= -1)
        return false;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == p[j] || s[i] == '?' || p[j] == '?')
        return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
    else if (p[j] == '*')
    {
        while (j != -1 && p[j] == '*')
            j--;
        if (j == -1)
            return dp[i][j + 1] = true;
        while (i != -1 && s[i] != p[j])
            i--;
        if (i == -1)
            return dp[i + 1][j] = false;
        return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
    }
    else
        return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
    if (s == "")
    {
        int j = 0;
        while (j != p.length())
        {
            if (p[j++] != '*')
                return false;
        }
        return true;
    }
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    return solve(s, p, s.length() - 1, p.length() - 1, dp);
    // return true;
} // This shit doesn't work, don't go for hit and trial test cases method, use your brain and figure out a broader spectrum that covers all possibilities.

// APPROACH: We traverse str and pattern from the end, if (s[i]==p[i]||p[i]=='?') , we simply move ahead, if p[i]=='*', then we can either consider this '*' as an empty subsequence or consider as the current character s[i] and take OR of both the answers, and if s[i]!=p[i] we return false.
// RECURSIVE
bool solve(string &s, string &p, int i, int j)
{
    if (i < 0 && j < 0)
        return true;
    if (i >= 0 && j < 0)
        return false;
    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
                return false;
        }
        return true;
    }
    if (s[i] == p[j] || p[j] == '?')
        return solve(s, p, i - 1, j - 1);
    else if (p[j] == '*')
        return (solve(s, p, i, j - 1) || solve(s, p, i - 1, j));
    else
        return false;
}
bool isMatch(string s, string p)
{
    return solve(s, p, s.length() - 1, p.length() - 1);
}

// RECURSION + MEMOIZATION
bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i >= 0 && j < 0)
        return false;
    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
                return false;
        }
        return true;
    }
    if (dp[i + 1][j + 1] != -1)
        return dp[i + 1][j + 1];
    if (s[i] == p[j] || p[j] == '?')
        return dp[i + 1][j + 1] = solve(s, p, i - 1, j - 1, dp);
    else if (p[j] == '*')
        return dp[i + 1][j + 1] = (solve(s, p, i, j - 1, dp) || solve(s, p, i - 1, j, dp));
    else
        return dp[i + 1][j + 1] = false;
}
bool isMatch(string s, string p)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    return solve(s, p, s.length() - 1, p.length() - 1, dp);
}
// TABULATION
bool solveTab(string &s, string &p)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));
    dp[0][0] = 1;
    for (int j = 1; j <= p.length(); j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
            else
                dp[i][j] = false;
        }
    }
    return dp[s.length()][p.length()];
}
bool isMatch(string s, string p)
{
    return solveTab(s, p);
}
// SPACE OPTIMIZATION
bool solveTab(string &s, string &p)
{
    vector<int> prev(p.length() + 1, 0), curr(p.length() + 1, 0);
    prev[0] = 1;
    for (int j = 1; j <= p.length(); j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                curr[j] = prev[j - 1];
            else if (p[j - 1] == '*')
                curr[j] = (curr[j - 1] || prev[j]);
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[p.length()];
}
bool isMatch(string s, string p)
{
    return solveTab(s, p);
}
int main()
{

    return 0;
}