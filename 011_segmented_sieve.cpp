/* SEGMENTED SIEVE
Normal sieve works fine for significantly large inputs, but for even larger inputs of the order of 10^9, it is not the best method to print prime numbers less than a given number, as creating an array of size (10^9 + 1) is not feasible. So we use the logic of segmented sieve.
In this approach, we search for prime numbers in a segment instead of searching in the entire range. The algorithm can be broken into following steps
1. We create an array 'prime'. This will store all the prime numbers we encounter.
2. Our first segment is from 1 to floor(sqrt(n)), next is from sqrt(n) to 2*sqrt(n) and so on. We search for prime numbers in the first segment using simple sieve and then we mark the multiples of these prime numbers as not prime in the second segment.
3. The numbers that remain marked as true in 2nd segment are added to the array prime, then the numbers that are multiples of numbers present in prime are marked as false in the third segment and the remaining numbers of 3rd segment are added to prime and the process continues till the last segment.
NOTE:- To mark the numbers in a segment, we are supposed to create an array of size [high-low+1], where high is the upper limit of the segment and low is lower limit.
4. At last, we print the array prime.
*/
#include <bits/stdc++.h>
using namespace std;
void simpleSieve(long long n, vector<int> &prime)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
}
void segmentedSieve(int n)
{
    long long l = sqrt(n);
    vector<int> prime;
    simpleSieve(l, prime);
    int low = l, high = 2 * l;

    while (low < n)
    {
        if (high > n)
            high = n;
        vector<bool> isPrime(high - low + 1, true);
        for (int i = 0; i < prime.size(); i++)
        {
            int sm = (low / prime[i]) * prime[i];
            if (sm < low)
                sm += prime[i];
            for (int j = sm; j <= high; j += prime[i])
                isPrime[j-low] = false;
        }
        for (int i = 0; i < isPrime.size(); i++)
        {
            if (isPrime[i])
                prime.push_back(i + low);
        }
        low = high+1;
        high += l;
    }
    for (int i = 0; i < prime.size(); i++)
        cout << prime[i] << " ";
    cout << "\n";
}
int main()
{
    segmentedSieve(100);
    return 0;
}