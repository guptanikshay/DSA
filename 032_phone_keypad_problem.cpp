/* Given a stirng of numbers [2, 9], return all the possible letter combinations that the number can represent.
The numbers and letters are mapped as follows
2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz
*/
#include <bits/stdc++.h>
using namespace std;

void soln(vector<string> &ans, string nums, string add, int i, vector<string> numpad)
{
    if(nums=="")
    return;
    if (i >= nums.size())
    {
        ans.push_back(add);
        return;
    }
    int n = nums[i] - '0';
    string val = numpad[n];
    for (int j = 0; j < val.length(); j++)
    {
        add.push_back(val[j]);
        soln(ans, nums, add, i + 1, numpad);
        add.pop_back();
    }
}
int main()
{
    // string numpad[10];
    // numpad[0]="";
    // numpad[1]="";
    // numpad[2]="abc";
    // numpad[3]="def";
    // numpad[4]="ghi";
    // numpad[5]="jkl";
    // numpad[6]="mno";
    // numpad[7]="pqrs";
    // numpad[8]="tuv";
    // numpad[9]="wxyz";
    vector<string> numpad{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    int i = 0;
    string add = "";
    string nums = "29";
    soln(ans, nums, add, i, numpad);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << "\n";
    // cout<<numpad[2];
    return 0;
}