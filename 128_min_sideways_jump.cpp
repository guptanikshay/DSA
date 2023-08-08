#include <bits/stdc++.h>
using namespace std;
// PS: There are 3 lanes numbered 1, 2, 3, a road of length n with n+1 spots and there is a crazy frog who needs to cross this road by jumping through these n+1 spots. Initially he is standing at spot 0. The problem is that are there are some obstacles in the road given in the question as an array obstacles[] where obstacles[i] == x (0<=x<=3) represents that there is an obstacle at position i in lane x. If x==0 then there is no obstacle at position x. While crossing the road, if our crazy friend encounters an obstacle then he may jump sideways in any of two lanes (spot won't change in sideways jump). You need to return the minimum number of sideways jump required to cross the road.

// TC=O(N)  SC=O(1)
// RECURSION
int solve(vector<int> &obstacles, int lane, int i, int n)
{
    if (obstacles[i] == lane)
        return INT_MAX;
    if (i == n)
        return 0;
    if (obstacles[i + 1] != lane)
        return solve(obstacles, lane, i + 1, n);
    if (lane == 1)
        return (1 + min(solve(obstacles, 2, i, n), solve(obstacles, 3, i, n)));
    if (lane == 2)
        return (1 + min(solve(obstacles, 1, i, n), solve(obstacles, 3, i, n)));
    return (1 + min(solve(obstacles, 1, i, n), solve(obstacles, 2, i, n)));
}
int minSideJumps(vector<int> &obstacles)
{
    int minJ = 0, lane = 2, i = 0, n = obstacles.size() - 1;
    minJ = solve(obstacles, lane, i, n);
    return minJ;
}

// RECURSION WITH MEMOIZATION
int solve(vector<int> &obstacles, int lane, int i, int n, vector<vector<int>> &dp)
{
    if (obstacles[i] == lane)
        return INT_MAX;
    if (i == n)
        return 0;
    if (dp[lane][i] != -1)
        return dp[lane][i];
    int ans;
    if (obstacles[i + 1] != lane)
        ans = solve(obstacles, lane, i + 1, n, dp);
    else if (lane == 1)
        ans = (1 + min(solve(obstacles, 2, i, n, dp), solve(obstacles, 3, i, n, dp)));
    else if (lane == 2)
        ans = (1 + min(solve(obstacles, 1, i, n, dp), solve(obstacles, 3, i, n, dp)));
    else if (lane == 3)
        ans = (1 + min(solve(obstacles, 1, i, n, dp), solve(obstacles, 2, i, n, dp)));
    dp[lane][i] = ans;
    return dp[lane][i];
}
int minSideJumps(vector<int> &obstacles)
{
    int minJ, lane = 2, i = 0, n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(n + 1, -1));
    minJ = solve(obstacles, lane, i, n, dp);
    return minJ;
}

// TABUALATION
int minSideJumps(vector<int> &obstacles)
{
    int lane = 2, n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));
    for (int i = 0; i < 4; i++)
        dp[i][n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int lane = 1; lane <= 3; lane++)
        {
            if (obstacles[i + 1] != lane)
                dp[lane][i] = dp[lane][i + 1];
            else
            {
                int ans = 1e9;
                for (int j = 1; j <= 3; j++)
                {
                    if (lane != j && obstacles[i] != j)
                        ans = min(ans, 1 + dp[j][i + 1]);
                }
                dp[lane][i] = ans;
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

// SPACE OPTIMIZATION
int minSideJumps(vector<int> &obstacles)
{
    int lane = 2, n = obstacles.size() - 1;
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);
    next[0] = 0, next[1] = 0, next[2] = 0, next[3] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int lane = 1; lane <= 3; lane++)
        {
            if (obstacles[i + 1] != lane)
                curr[lane] = next[lane];
            else
            {
                int ans = 1e9;
                for (int j = 1; j <= 3; j++)
                {
                    if (lane != j && obstacles[i] != j)
                        ans = min(ans, 1 + next[j]);
                }
                curr[lane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}
int main()
{

    return 0;
}