#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int sz = s.length();
	int ans = 0;
	for (int i = 0; i < sz / 2; i++)
	{
		string p = s.substr(0, i), q = s.substr(i, i + sz / 2), r = s.substr(i + sz / 2, sz);
		cout << p << " " << q << " " << r << "\n";
		string pr = p.append(r);
		if (q.compare(pr) == 0)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}