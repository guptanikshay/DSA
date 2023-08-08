#include <bits/stdc++.h>
using namespace std;

// In a greedy algorithm, we choose the most optimal solution at that particular moment, it may or may not be the most optimal solution for the entire problem

// N MEETINGS IN ONE ROOM
static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> meets;
    for (int i = 0; i < n; i++)
        meets.push_back(make_pair(start[i], end[i]));
    sort(meets.begin(), meets.end(), cmp);
    int count = 1, ansEnd = meets[0].second;
    for (int i = 1; i < n; i++)
    {
        if (meets[i].first > ansEnd)
        {
            count++;
            ansEnd = meets[i].second;
        }
    }
    return count;
}

// MAXIMUM MEETINGS IN ONE ROOM
static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    vector<pair<int, int>> meets;
    map<pair<int, int>, int> index;
    for (int i = 0; i < N; i++)
    {
        meets.push_back(make_pair(S[i], F[i]));
        if (index[{S[i], F[i]}] == 0)
            index[{S[i], F[i]}] = i;
    }
    sort(meets.begin(), meets.end(), cmp);
    vector<int> ans;
    ans.push_back(index[{meets[0].first, meets[0].second}] + 1);
    int ansEnd = meets[0].second;
    for (int i = 1; i < N; i++)
    {
        if (meets[i].first > ansEnd)
        {
            ansEnd = meets[i].second;
            ans.push_back(index[{meets[i].first, meets[i].second}] + 1);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}