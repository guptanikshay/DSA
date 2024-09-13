#include <iostream>
using namespace std;

bool raising(int n)
{
	int digit = n % 10;
	n /= 10;
	while (n)
	{
		if (digit >= (n % 10))
		{
			digit = n % 10;
			n /= 10;
		}
		else
			return false;
	}
	return true;
}

bool dropping(int n)
{
	int digit = n % 10;
	n /= 10;
	while (n)
	{
		if (digit <= (n % 10))
		{
			digit = n % 10;
			n /= 10;
		}
		else
			return false;
	}
	return true;
}
void print(int n, int m)
{
	int raise = 0, drop = 0, jumpy = 0;
	for (int i = n; i < m; i++)
	{
		if (raising(i))
			raise++;
		else if (dropping(i))
			drop++;
		else
			jumpy++;
	}
	cout << raise << " " << drop << " " << jumpy;
}
int main()
{

	return 0;
}