/* SIEVE OF ERATOSTHENES
PS:- You are supposed to print all the prime numbers less than a given number 'n'.
Soln:- In this approach, we create an auxiliary array of n+1 size and mark all the values as true in it and as 0 and 1 are non prime, we mark them as false in next step. Then we start from 2 and check whether its value is true (isPrime) or not and if it is true then we mark all its multiples as false in the array and if it is false then we move to next element of the array.
In the last step we print all the elements of the array which hold the value true.
*/
#include <iostream>
#include <vector>
using namespace std;
void printPrimes(int n){
    vector <bool> primes(n+1, true);
    primes[0]=primes[1]=false;
    for(int i=2; i<n; i++){
        if(primes[i]){
            cout<<i<<" ";
            for(int j=i*i; j<n; j+=i)
            primes[j]=false;
        }
    }
    cout<<"\n";
}
int main(){
    printPrimes(100);
    return 0;
}