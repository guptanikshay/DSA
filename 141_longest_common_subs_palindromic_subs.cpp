#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// LONGEST COMMON SUBSEQUENCE: Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// APPROACH: We simply iterate both the strings using two pointers i and j, and if(a[i]==a[j]) we return 1+solve(a, b, i, j), else if(a[i]!=b[i]) we return max(solve(a, b, i+1, j), solve(a, b, i, j+1))
// RECURSION
int solve(string &text1, string &text2, int i, int j)
{
    if (i >= text1.size() || j >= text2.size())
        return 0;
    if (text1[i] == text2[j])
        return 1 + solve(text1, text2, i + 1, j + 1);
    else
        return max(solve(text1, text2, i + 1, j), solve(text1, text2, i, j + 1));
}
int longestCommonSubsequence(string text1, string text2)
{
    return solve(text1, text2, 0, 0);
}
// RECURSION + MEMOIZATION
int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= text1.size() || j >= text2.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (text1[i] == text2[j])
        return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
    else
        return dp[i][j] = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
    return solve(text1, text2, 0, 0, dp);
}
// TABULATION
int solveTab(string &text1, string &text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}
int longestCommonSubsequence(string text1, string text2)
{
    return solveTab(text1, text2);
}
// SPACE OPTIMIZATION
int solveTab(string &text1, string &text2)
{
    vector<int> next(text2.size() + 1, 0), curr(text2.size() + 1, 0);
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                curr[j] = 1 + next[j + 1];
            else
                curr[j] = max(next[j], curr[j + 1]);
        }
        next = curr;
    }
    return curr[0];
}
int longestCommonSubsequence(string text1, string text2)
{
    return solveTab(text1, text2);
}

// LONGEST PALINDROMIC SUBSEQUENCE: Given a string s, find the longest palindromic subsequence's length in s.
// APPROACH: This problem can be solved by finding the Longest Common Subsequence in the given string and reverse(given string). This works because a palindrome is same when reversed.
int solve(string &text1, string &text2)
{
    vector<int> next(text2.size() + 1, 0), curr(text2.size() + 1, 0);
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                curr[j] = 1 + next[j + 1];
            else
                curr[j] = max(next[j], curr[j + 1]);
        }
        next = curr;
    }
    return curr[0];
}
int longestPalindromeSubseq(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return solve(s, rev);
}
int main()
{

    return 0;
}