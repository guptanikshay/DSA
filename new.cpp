#include <iostream>
using namespace std;

int main()
{
	int n = 1001;
	for (int i = 1; i <= 100; i++)
	{
		cout << n * i << " ";
		if (i % 10 == 0)
			cout << "\n";
	}
	return 0;
}