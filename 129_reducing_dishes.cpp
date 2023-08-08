#include <bits/stdc++.h>
using namespace std;

// PS: A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time. Like - time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i]. Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation. Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

// WITHOUT DP SOLUTION
int solve(vector<int> &sat, int i)
{
    if (i == 0)
        return sat[i];
    int ans = 0;
    for (int j = sat.size() - 1; j >= 0; j--)
    {
        ans += ((sat.size() - j) * sat[j]);
    }
    sat.pop_back();
    return max(ans, solve(sat, i - 1));
}
int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    reverse(satisfaction.begin(), satisfaction.end());
    return max(0, solve(satisfaction, satisfaction.size() - 1));
}

// RECURSION
int solve(vector<int> &sat, int index, int time)
{
    if (index == sat.size())
        return 0;
    int incl = sat[index] * (time + 1) + solve(sat, index + 1, time + 1);
    int excl = solve(sat, index + 1, time);
    return max(incl, excl);
}
int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 0);
}

// RECURSION WITH MEMOIZATION
int solve(vector<int> &sat, int index, int time, vector<vector<int>> &dp)
{
    if (index == sat.size())
        return 0;
    if (dp[index][time] != -1)
        return dp[index][time];
    int incl = sat[index] * (time + 1) + solve(sat, index + 1, time + 1, dp);
    int excl = solve(sat, index + 1, time, dp);
    return dp[index][time] = max(incl, excl);
}
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(satisfaction, 0, 0, dp);
}

// TABULATION
int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int incl = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int excl = dp[index + 1][time];
            dp[index][time] = max(incl, excl);
        }
    }
    return dp[0][0];
}

// SPACE OPTIMIZATION
int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int incl = satisfaction[index] * (time + 1) + next[time + 1];
            int excl = next[time];
            curr[time] = max(incl, excl);
        }
        next = curr;
    }
    return next[0];
}
int main()
{

    return 0;
}