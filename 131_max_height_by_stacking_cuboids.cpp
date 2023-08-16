#include <bits/stdc++.h>
using namespace std;

// PS: We are a given a 2D array consisting of width, height and length of cuboid and we are supposed to place them on one another subject to the condition that the cuboid on top should have height, width and length smaller than the one below it, and this way we need to return the max height of the tower formed. Rotation of cuboid is allowed.

// Approach: 3 Steps:- 1. Sort the dimension array of each cuboid such the longest dimension of each cuboid is its height    2. Sort all the cuboids on the basis of their widths   3. Use the Longest increasing subsequence logic and find LIS of heights, which is the answer
bool check(vector<int> &a, vector<int> &b)
{
    if (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
        return true;
    else
        return false;
}
int lengthOfLIS(vector<vector<int>> &cuboids)
{
    int n = cuboids.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int last = index - 1; last >= -1; last--)
        {
            int incl = 0;
            if (last == -1 || check(cuboids[index], cuboids[last]))
                incl = cuboids[index][2] + next[index + 1];
            int excl = next[last + 1];
            curr[last + 1] = max(incl, excl);
        }
        next = curr;
    }
    return next[0];
}
int maxHeight(vector<vector<int>> &cuboids)
{
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }
    sort(cuboids.begin(), cuboids.end());
    return lengthOfLIS(cuboids);
}

// PIZZA WITH 3N SLICES: There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows: You will pick any pizza slice. Your friend Alice will pick the next slice in the anti - clockwise direction of your pick. Your friend Bob will pick the next slice in the clockwise direction of your pick. Repeat until there are no more slices of pizzas. Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick

// RECURSION
int solve(int i, int n, int endIndex, vector<int> slices) // Here n is the count of the number of slices remaining to be eaten
{
    if (n == 0 || i >= endIndex)
        return 0;
    int incl = slices[i] + solve(i + 2, n - 1, endIndex, slices);
    int excl = solve(i + 1, n, endIndex, slices);
    return max(incl, excl);
}
int maxSizeSlices(vector<int> &slices)
{
    int n = slices.size();
    int c1 = solve(0, n / 3, n - 2, slices);
    int c2 = solve(1, n / 3, n - 1, slices);
    return max(c1, c2);
}

// TOP DOWN APPROACH
int solve(int i, int remSlices, int endIndex, vector<int> &slices, vector<vector<int>> &dp)
{
    if (remSlices == 0 || i > endIndex)
        return 0;
    if (dp[i][remSlices] != -1)
        return dp[i][remSlices];
    int incl = slices[i] + solve(i + 2, remSlices - 1, endIndex, slices, dp);
    int excl = solve(i + 1, remSlices, endIndex, slices, dp);
    return dp[i][remSlices] = max(incl, excl);
}
int maxSizeSlices(vector<int> &slices)
{
    int n = slices.size();
    vector<vector<int>> dp1(n + 1, vector<int>(n / 3 + 1, -1));
    int c1 = solve(0, n / 3, n - 2, slices, dp1);
    vector<vector<int>> dp2(n + 1, vector<int>(n / 3 + 1, -1));
    int c2 = solve(1, n / 3, n - 1, slices, dp2);
    return max(c1, c2);
}

// BOTTOM UP APPROACH
int maxSizeSlices(vector<int> &slices)
{
    int n = slices.size();
    vector<vector<int>> dp1(n + 2, vector<int>(n / 3 + 1, 0));
    vector<vector<int>> dp2(n + 2, vector<int>(n / 3 + 1, 0));
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= n / 3; j++)
        {
            int incl = slices[i] + dp1[i + 2][j - 1];
            int excl = dp1[i + 1][j];
            dp1[i][j] = max(incl, excl);
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n / 3; j++)
        {
            int incl = slices[i] + dp2[i + 2][j - 1];
            int excl = dp2[i + 1][j];
            dp2[i][j] = max(incl, excl);
        }
    }
    return max(dp1[0][n / 3], dp2[1][n / 3]);
}

// SPACE OPTIMIZATION
int maxSizeSlices(vector<int> &slices)
{
    int n = slices.size();
    vector<int> prev1(n / 3 + 1, 0), curr1(n / 3 + 1, 0), next1(n / 3 + 1, 0);
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= n / 3; j++)
        {
            int incl = slices[i] + next1[j - 1];
            int excl = curr1[j];
            prev1[j] = max(incl, excl);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    vector<int> prev2(n / 3 + 1, 0), curr2(n / 3 + 1, 0), next2(n / 3 + 1, 0);
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n / 3; j++)
        {
            int incl = slices[i] + next2[j - 1];
            int excl = curr2[j];
            prev2[j] = max(incl, excl);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    return max(prev1[n / 3], prev2[n / 3]);
}
int main()
{

    return 0;
}