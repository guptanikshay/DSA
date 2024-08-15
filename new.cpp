#include <bits/stdc++.h>
using namespace std;

int main()
{
	static int value = 3;
	if (--value)
	{
		main();
		printf("%d ", value);
	}
	return 0;
}