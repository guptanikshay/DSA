// **SUBMIT THIS QUESTION ON LEETCODE**
// You are given a string str consisting of lowercase english letters. Task is to return all permutations of given string in lexicographically increasing order.
// For instance, if the string is "bca", then the answer should be {"abc", "acb", "bac", "bca", "cab", "cba"}
#include <bits/stdc++.h>
using namespace std;
int strcmp1(string str1, string str2)
{
    int i=0;
    while(str1[i]==str2[i])
    i++;
    if(str1[i]>str2[i])
    return 1;
    return 0;
}
void soln(vector<string> &ans, string str, int i)
{
    // base case
    if (i >= str.length())
    {
        ans.push_back(str);
        return;
    }
    for (int j = i; j < str.length(); j++)
    {
        swap(str[i], str[j]);
        soln(ans, str, i + 1);
        // backtracking
        swap(str[i], str[j]);
    }
}
void ascen(vector<string> &ans)
{
    for (int i = 1; i < ans.size(); i++)
        for (int j = i - 1; j >= 0; j--)
            if (strcmp1(ans[j], ans[j + 1]))
                swap(ans[j + 1], ans[j]);
            else
                break;
}
int main()
{
    string str = "bac";
    vector<string> ans;
    int i = 0;
    soln(ans, str, i);
    ascen(ans);
    for (auto ele : ans)
        cout << ele << " ";
    cout << "\n";
    return 0;
}