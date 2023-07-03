#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<int>> ans;
        sort(a, a + n);
        int box = 0;
        map<int, int> xOr;
        xOr[box] = a[n - 1];
        ans[box].push_back(a[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            bool added = false;
            for (int j = 0; j < box; j++)
            {
                if (xOr[j] >= a[i])
                {
                    ans[box].push_back(a[i]);
                    xOr[j] = xOr[j] ^ a[i];
                    added = true;
                    break;
                }
            }
            if (!added)
            {
                box++;
                ans[box].push_back(a[i]);
                xOr[box] = a[i];
            }
        }
        cout << box << "\n";
    }
    return 0;
}