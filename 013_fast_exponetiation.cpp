/* FAST EXPONENTIATION 
 * You are supposed to calculate high powers of numbers (e.g 5^25) and doing it in the ordinary way will make you exceed the time limit. The time complexity of ordinary method is O(n) and that of fast exponentiation is O(log(n)), where n is the exponent.
 * In this method, firstly we create an ans variable and store 1 in it. Then we run a while loop until the exponent becomes 0 and in there we check if the exponent is odd, and if it is, we multiply the ans by x (base). Then we square the base and divide the exponent by 2 and then continue in the loop.
 * It works on the algorithm that a^b can be calculated as ((a^2)^b/2), if n is even or   a*((a^2)^b/2), if n is odd.
*/
#include <iostream>
using namespace std;

int modularExpo(int x, int n, int m)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        { // odd
            res = (1LL * (res) * (x) % m) % m;
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1;
    }
    return res;
}
int Expo(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        { // odd
            res = 1LL * (res) * (x);
        }
        x = (1LL * (x) * (x));
        n = n >> 1;
    }
    return res;
}
int main()
{
    cout<<modularExpo(2, 5, 8);
    cout<<"\n"<<Expo(2, 5);
    return 0;
}