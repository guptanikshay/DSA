#include <bits/stdc++.h>
using namespace std;

// LONGEST ARITHMETIC PROGRESSION WITH GIVEN COMMON DIFFERENCE
// APPROACH: We simply create a map to store at every index, the maximum length of AP with the given difference behind that index (including itself). Then at a index, we check if the arr[index]-diff exists in the map, and if it does we add its value to our length count, and update the dp map and max length.
int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();
    unordered_map<int, int> dp;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        if (dp.find(arr[i] - difference) != dp.end())
            cnt += dp[arr[i] - difference];
        dp[arr[i]] = cnt;
        ans = max(ans, cnt);
    }
    return ans;
}

int main()
{

    return 0;
}