#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string n;
		cin >> n;
		int size = n.size(), i = n.size() - 1;
		map<int, bool> flag;
		while (i >= 0)
		{
			if ((n[i] - 48) < 5)
				i--;
			else
			{
				if (i != 0)
				{
					for (int j = i; j < size; j++)
					{
						if (n[j] == 48)
							break;
						else
							n[j] = 48;
					}
					n[i - 1]++;
				}
				else
				{
					for (int j = i; j < size; j++)
					{
						if (n[j] == 48)
							break;
						else
							n[j] = 48;
					}
					n[i] = 49;
					n.push_back(48);
				}
			}
		}
		// int zeroI = -1;
		// for (int i = 0; i < size; i++)
		// {
		// 	if (n[i] + 48 < 5)
		// 		continue;
		// 	else
		// 	{
		// 		zeroI = i;
		// 		if (i != 0)
		// 		{
		// 		}
		// 	}
		// }
		cout << n << "\n";
	}
	return 0;
}