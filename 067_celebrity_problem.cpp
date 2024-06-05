// A celebrity is a person who doesn't know anyone but everyone knows him. You'll be given a N x N matrix containing 0s and 1s, which tells us whether a person knows the other person or not. If the element is 1, the respective person knows the other person. The diagonal elements of this matrix will always be zero, because it is illogical to ask whether a person knows himself. For instance, the matrix for 3 persons might be like this
//      1  2  3
// 1  { 0  1  0 }
// 2  { 0  0  0 }
// 3  { 0  1  0 }
// We check the matrix from vertical side. For instance, 1 knows 2 and 2 doesn't know 1. Here 2 is a celebrity because everyone knows him, but he doesn't know anyone.

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: There are two conditions for a person to be a celebrity, everyone should know him and he should not know anyone. That is, for a celebrity, all the row elements would be 0 and all the column elements would be 1 (except for the diagonal element). Therefore, we will check these two conditions for every element. TC: O(n^2)
int celebrity2(vector<vector<int>> &M, int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (!M[i][j])
                continue;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[j][i] || i == j)
                    continue;
                else
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            return i;
    }
    return -1;
}

// OPTIMAL APPROACH: We push all the persons (elements) in a stack, take out two persons A and B from the stack and check whether A knows B, if yes, we push B back into the stack, and if no, we push A back into the stack. We continue this until one element is left in the stack and this last element may be a celebrity. We check the two required conditions for this element and return our ans.
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (M[a][b] == 1)
            s.push(b);
        else
            s.push(a);
    }
    int ans = s.top(), isCeleb = 1;
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 1)
            isCeleb = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != ans && M[i][ans] == 0)
            isCeleb = 0;
    }
    if (isCeleb)
        return ans;
    return -1;
}
int main()
{
    vector<vector<int>> M{{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    int n = M.size();
    cout << "Celebrity is: " << celebrity(M, n);
    return 0;
}