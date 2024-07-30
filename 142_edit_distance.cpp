#include <bits/stdc++.h>
using namespace std;

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character
/* APPROACH: Again we'll take two pointers i for word1 and j for word2, then we'll check if(word1[i]==word2[j]), and if it is we simply increment both of them, and if it isn't then we have 3 options:
 * Either we can insert a new character in word1, and this case i will stay in the same position and j will be incremented, because word2[j] is inserted before word1[i], so i stays in the same position.
 * Or we can replace word1[i] with word2[j], and in this case both i and j will be incremented
 * Or we can delete word1[i], and in this case only i will be incremented.
 All of the above will be counted as 1 operation
 NOTE: We are not actually changing the strings, we are simply assuming that we have changed them and then we increment the values of i and j based on that change.
 Here our base case will be when i or j reach the end. If i reaches the end first, then we need to insert the remaining characters in word2 to word1, therefore the number of operations required will be word2.length()-j and we return it.
 On the other hand, if j reaches the end first, then we need to insert the remaining characters of word1 into word2 and the number of operations will be word1.length()-i.
 */

// RECURSION
int solve(string &word1, string word2, int i, int j)
{
    if (word1.length() == i)
        return word2.length() - j;
    if (word2.length() == j)
        return word1.length() - i;
    if (word1[i] == word2[j])
        return solve(word1, word2, i + 1, j + 1);
    else
        return 1 + min(solve(word1, word2, i, j + 1), min(solve(word1, word2, i + 1, j + 1), solve(word1, word2, i + 1, j)));
}
int minDistance(string word1, string word2)
{
    return solve(word1, word2, 0, 0);
}

// RECURSION + MEMOIZATION
int solve(string &word1, string word2, int i, int j, vector<vector<int>> &dp)
{
    if (word1.length() == i)
        return word2.length() - j;
    if (word2.length() == j)
        return word1.length() - i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (word1[i] == word2[j])
        return dp[i][j] = solve(word1, word2, i + 1, j + 1, dp);
    else
        return dp[i][j] = 1 + min(solve(word1, word2, i, j + 1, dp), min(solve(word1, word2, i + 1, j + 1, dp), solve(word1, word2, i + 1, j, dp)));
}
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
    return solve(word1, word2, 0, 0, dp);
}
// TABULATION
int solveTab(string &word1, string &word2)
{
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j < m; j++)
        dp[n][j] = m - j;
    for (int i = 0; i < n; i++)
        dp[i][m] = n - i;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (word1[i] == word2[j])
                dp[i][j] = dp[i + 1][j + 1];
            else
                dp[i][j] = 1 + min(dp[i][j + 1], min(dp[i + 1][j + 1], dp[i + 1][j]));
        }
    }
    return dp[0][0];
}
int minDistance(string word1, string word2)
{
    return solveTab(word1, word2);
}

// SPACE OPTIMIZATION
int solveTab(string &word1, string &word2)
{
    int n = word1.length(), m = word2.length();
    vector<int> next(m + 1, 0), curr(m + 1, 0);
    for (int j = 0; j < m; j++)
        next[j] = m - j;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            curr[m] = n - i; // CATCH HERE: This was base condition for the last column of every row, and since we had only two rows, so we update this in every iteration.
            if (word1[i] == word2[j])
                curr[j] = next[j + 1];
            else
                curr[j] = min(1 + curr[j + 1], min(1 + next[j + 1], 1 + next[j]));
        }
        next = curr;
    }
    return curr[0];
}
int minDistance(string word1, string word2)
{
    if (word1 == "")
        return word2.length();
    if (word2 == "")
        return word1.length();
    return solveTab(word1, word2);
}
int main()
{

    return 0;
}