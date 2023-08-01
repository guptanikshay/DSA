#include <bits/stdc++.h>
using namespace std;

// PS:- Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area

// BRUTE FORCE RECURSION
int solve(vector<vector<char>> &matrix, int i, int j, int &maxi)
{
    if (i >= matrix.size() || j >= matrix[0].size())
        return 0;
    int right = solve(matrix, i, j + 1, maxi);
    int diag = solve(matrix, i + 1, j + 1, maxi);
    int down = solve(matrix, i + 1, j, maxi);

    if (matrix[i][j] == '1')
    {
        int ans = 1 + min(right, min(diag, down));
        maxi = max(ans, maxi);
        return ans;
    }
    else
        return 0;
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int maxi = 0;
    solve(matrix, 0, 0, maxi);
    return maxi * maxi;
}

// RECURSION WITH MEMOIZATION
int solve(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= matrix.size() || j >= matrix[0].size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int right = solve(matrix, i, j + 1, maxi, dp);
    int diag = solve(matrix, i + 1, j + 1, maxi, dp);
    int down = solve(matrix, i + 1, j, maxi, dp);

    if (matrix[i][j] == '1')
    {
        dp[i][j] = 1 + min(right, min(diag, down));
        maxi = max(dp[i][j], maxi);
        return dp[i][j];
    }
    dp[i][j] = 0;
    return dp[i][j];
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int maxi = 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    solve(matrix, 0, 0, maxi, dp);
    return maxi * maxi;
}

// TABULATION METHOD
int maximalSquare(vector<vector<char>> &matrix)
{
    int maxi = 0;
    vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
    for (int i = matrix.size() - 1; i >= 0; i--)
    {
        for (int j = matrix[0].size() - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1], diag = dp[i + 1][j + 1], down = dp[i + 1][j];
            if (matrix[i][j] == '1')
            {
                dp[i][j] = 1 + min(right, min(diag, down));
                maxi = max(dp[i][j], maxi);
            }
            else
                dp[i][j] = 0;
        }
    }
    return maxi * maxi;
}

// TABULATION METHOD WITH SPACE OPTIMIZATION
int maximalSquare(vector<vector<char>> &matrix)
{
    int maxi = 0;
    vector<int> curr(matrix[0].size() + 1, 0);
    vector<int> next(matrix[0].size() + 1, 0);
    for (int i = matrix.size() - 1; i >= 0; i--)
    {
        for (int j = matrix[0].size() - 1; j >= 0; j--)
        {
            int right = curr[j + 1], diag = next[j + 1], down = next[j];
            if (matrix[i][j] == '1')
            {
                curr[j] = 1 + min(right, min(diag, down));
                maxi = max(curr[j], maxi);
            }
            else
                curr[j] = 0;
        }
        next = curr;
    }
    return maxi * maxi;
}
int main()
{

    return 0;
}