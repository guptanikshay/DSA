#include <bits/stdc++.h>
using namespace std;

int main()
{
	// int t;
	// cin >> t;
	// while (t--)
	// {
	string n;
	cin >> n;
	int size = n.size(), i = n.size() - 1;
	while (i >= 0)
	{
		if ((n[i] - 48) < 5)
			i--;
		else
		{
			if (i != 0)
			{
				for (int j = i; j < size; j++)
					n[j] = 48;
				n[i - 1]++;
			}
			else
			{
				for (int j = i; j < size; j++)
					n[j] = 48;
				n[i] = 49;
				n.push_back(48);
			}
		}
	}
	cout << n << "\n";
	// }
	return 0;
}