#include <iostream>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, flag = 0;
		cin >> n;
		long long arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		long long minDiff = INT_MAX;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				flag = 1;
				break;
			}
			if (arr[i + 1] - arr[i] < minDiff)
				minDiff = arr[i + 1] - arr[i];
		}
		if (flag)
			cout << 0 << "\n";
		else if (minDiff % 2 == 0)
			cout << (minDiff + 2) / 2 << "\n";
		else
			cout << (minDiff + 1) / 2 << "\n";
	}
	return 0;
}