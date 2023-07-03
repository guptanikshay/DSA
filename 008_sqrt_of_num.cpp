#include <iostream>
using namespace std;

int sqrtInt(int x)
{
    long long int s = 0, e = x, mid;
    float ans;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

double morePrec(int n, double temp, int fact)
{
    double ans = temp, div = 1;
    while (fact--)
    {
        div /= 10;
        for (double j = ans; j * j < n; j += div)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    cout << "Enter the number whose square is to be calculated: ";
    int n;
    cin >> n;
    int temp = sqrtInt(n);
    cout << "Square root of " << n << " is " << temp << "\n";
    cout << "Answer with more precision is " << morePrec(n, temp, 3);
    return 0;
}