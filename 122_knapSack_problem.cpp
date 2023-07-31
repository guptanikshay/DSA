#include <bits/stdc++.h>
using namespace std;

// PS:- A theif is robbing a store and can carry a maximum weight of W in his knapsack. There are N items and the i'th item weighs Wi and is of value Vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a theif can generate by stealing items.

// RECURSIVE SOLUTION
// Brute Force:- We find all the subsets of weights array and the subset in which the weight is less than or equal to knapsack limit and the sum of values of items is maximum is our answer. This can be done using inclusion and exclusion method of recursion.
int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    int exclude = solve(weight, value, index - 1, capacity);
    int ans = max(include, exclude);
    return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n - 1, maxWeight);
}

// RECURSIVE + MEMOIZATION SOLUTION (TOP DOWN DP)
int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }
    if (dp[index][capacity] != -1)
        return dp[index][capacity];
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index], dp);
    int exclude = solve(weight, value, index - 1, capacity, dp);
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(weight, value, n - 1, maxWeight, dp);
}

// TABULATION METHOD
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    int capacity = maxWeight;
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] + dp[i - 1][j - weight[i]];
            int exclude = dp[i - 1][j];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

// TABULATION WITH SPACE OPTIMIZATION: As the answer only depends on the last row, space can be optimized using two arrays.
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1);
    vector<int> curr(maxWeight + 1);
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] + prev[j - weight[i]];
            int exclude = prev[j];
            curr[j] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

// EVEN MORE SPACE OPTIMIZED SOLUTION
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> curr(maxWeight + 1);
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = maxWeight; j >= 0; j--)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] + curr[j - weight[i]];
            int exclude = curr[j];
            curr[j] = max(include, exclude);
        }
    }
    return curr[maxWeight];
}
int main()
{

    return 0;
}