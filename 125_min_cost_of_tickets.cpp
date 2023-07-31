#include <bits/stdc++.h>
using namespace std;

/* You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel. */
// RECURSION
int solve(vector<int> &days, vector<int> &costs, int i)
{
    if (i >= days.size())
        return 0;
    int op1 = costs[0] + solve(days, costs, i + 1);
    int index;
    for (index = i; index < days.size() && days[index] < days[i] + 7; index++)
        ;
    int op2 = costs[1] + solve(days, costs, index);
    for (index = i; index < days.size() && days[index] < days[i] + 30; index++)
        ;
    int op3 = costs[2] + solve(days, costs, index);
    return min(op1, min(op2, op3));
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int i = 0;
    return solve(days, costs, i);
}

// RECURSION WITH MEMOIZATION
int solve(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
{
    if (i >= days.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int op1 = costs[0] + solve(days, costs, i + 1, dp);
    int index;
    for (index = i; index < days.size() && days[index] < days[i] + 7; index++)
        ;
    int op2 = costs[1] + solve(days, costs, index, dp);
    for (index = i; index < days.size() && days[index] < days[i] + 30; index++)
        ;
    int op3 = costs[2] + solve(days, costs, index, dp);
    dp[i] = min(op1, min(op2, op3));
    return dp[i];
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int i = 0;
    vector<int> dp(days.size() + 1, -1);
    return solve(days, costs, i, dp);
}

// TABULATION METHOD (BOTTOM UP APPROACH)
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int op1 = costs[0] + dp[i + 1];
        int index;
        for (index = i; index < days.size() && days[index] < days[i] + 7; index++)
            ;
        int op2 = costs[1] + dp[index];
        for (index = i; index < days.size() && days[index] < days[i] + 30; index++)
            ;
        int op3 = costs[2] + dp[index];
        dp[i] = min(op1, min(op2, op3));
    }
    return dp[0];
}

// SPACE OPTIMIZATION
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int ans = 0;
    queue<pair<int, int>> week;
    queue<pair<int, int>> month;
    for (int day : days)
    {
        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();
        week.push(make_pair(day, ans + costs[1]));
        month.push(make_pair(day, ans + costs[2]));
        ans = min(ans + costs[0], min(week.front().second, month.front().second));
    }
    return ans;
}
int main()
{

    return 0;
}