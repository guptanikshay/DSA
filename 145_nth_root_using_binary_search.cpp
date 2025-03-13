#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6; // precision value

double multiply(double mid, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
        ans *= mid;
    return ans;
}

double nroot(double x, int n)
{
    double low = 1, high = x;
    while (high - low > eps)
    {
        double mid = (low + high) / 2;
        if (multiply(mid, n) < x)
            low = mid;
        else
            high = mid;
    }
    return low;
}
int main()
{
    double n, x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Enter the value of n for nth root: ";
    cin >> n;
    cout << "Ans is " << setprecision(6) << nroot(x, n) << "\n";
    return 0;
}