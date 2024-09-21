#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
// #define prDouble(x) cout << fixed <<  << x

int countSetBits(int n)
{
	int cnt = 0;
	while (n != 0)
	{
		n &= (n - 1);
		cnt++;
	}
	return cnt;
}

double probToMove(int prevDayMask, int fishToDie, int n, vector<vector<double>> &prob)
{
	int k = countSetBits(prevDayMask);
	double kC2 = k * (k - 1) / 2;
	double moveProb = 0;
	for (int fish = 0; fish < n; fish++)
	{
		if ((1 << fish) & prevDayMask)
			moveProb += (prob[fish][fishToDie]);
	}
	return moveProb / (1.0 * kC2);
}
double solve(int bitMask, int &n, vector<double> &dp, vector<vector<double>> &prob)
{
	int alive = countSetBits(bitMask);
	if (alive == n)
		return 1;
	if (dp[bitMask] > -0.9)
		return dp[bitMask];
	double ans = 0;
	for (int fish = 0; fish < n; fish++)
	{
		if (!(bitMask & (1 << fish)))
		{
			int prevDayMask = bitMask ^ (1 << fish);
			double prevDayProb = solve(prevDayMask, n, dp, prob);
			ans += prevDayProb * probToMove(prevDayMask, fish, n, prob);
		}
	}
	return dp[bitMask] = ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<double>> prob(n, vector<double>(n));
	vector<double> dp((1 << n), -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> prob[i][j];
	}
	for (int fish = 0; fish < n; fish++)
	{
		cout << (double)solve((1 << fish), n, dp, prob) << " ";
	}
	return 0;
}