#include <bits/stdc++.h>
using namespace std;

// PS: You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order). You will triangulate the polygon into n - 2 triangles.For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation. Return the smallest possible total score that you can achieve with some triangulation of the polygon.

// Approach: Consider the edges joining the first and the last vertex in array as the base edge and make triangle using the remaining vertices, which will result in n-2 triangles in every triangulation.

// RECURSION
int solve(int i, int j, vector<int> &v)
{
    if (i + 1 == j)
        return 0;
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, v[i] * v[j] * v[k] + solve(i, k, v) + solve(k, j, v));
    }
    return ans;
}
int minScoreTriangulation(vector<int> &values)
{
    return solve(0, values.size() - 1, values);
}

// RECURSION WITH MEMOIZATION
int solve(int i, int j, vector<int> &v, vector<vector<int>> &dp)
{
    if (i + 1 == j)
        return 0;
    int ans = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, v[i] * v[j] * v[k] + solve(i, k, v, dp) + solve(k, j, v, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, n - 1, values, dp);
}

// TABULATION
int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}
int main()
{

    return 0;
}