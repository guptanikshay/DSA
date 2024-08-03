// CP TEMPLATE
#include <iostream>
using namespace std;
#define int long long
#define M 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

// FAST EXPONENTIATION
// int fastExpo(int base, int power)
// {
//     int ans = 1;
//     while (power > 0)
//     {
//         if (power & 1)
//             ans = (1LL * ans * (base % M)) % M;
//         base = (1LL * (base % M) * (base % M)) % M;
//         power = power >> 1;
//     }
//     return ans % M;
// }
// int Expo(int x, int n)
// {
//     int res = 1;
//     while (n > 0)
//     {
//         if (n & 1)
//         { // odd
//             res = 1LL * (res) * (x);
//         }
//         x = (1LL * (x) * (x));
//         n = n >> 1;
//     }
//     return res;
// }

// FAST INPUT/OUTPUT
// ios_base::syn_with_stdio(false); // It toggles on or off the synchronization of all the C++ standard streams with their corresponding standard C streams
// cin.tie(NULL); // tie() is a method that simply guarantees the flushing of std::cout before std::cin accepts an input. This is useful for interactive console programs which require the console to be updated constantly but also slows down the program for large I/O. The NULL part just returns a NULL pointer.

// CONGRUENT NUMBERS
// Two numbers are congruent (in modulo M) if they return the same remainder when divided by M. For instance, 10 ≡ 3 (mod 7), as 10 and 3 both return the remainder 3 when divided by 7.

// MODULAR INVERSE
// Modular inverse is used for division in modular arithmetics, as we can't perform direct division there because it might lead to non-integer results. As we are interested in the value after modulo operation and not in the actual division output, so we first multiply the dividend by the divisor's modular inverse and then take the mod to get our final answer.
// Modular inverse can be calculated using Fermat's Little theorem, which states that if M is a prime nubmer, then for any integer 'a', not divisible by M, we have
// a^(M-1) ≡ 1 (mod M), which implies to
// a^(M-2) ≡ a^-1 (mod M)
// Hence, (a^(M-2) mod M) is the modular inverse of a in modulo M.
// Now, this inv (modular inverse) can be used in division as shown below
// We need to calculate (10/2)%7, so first we multiply 10 by modular inverse of 2, that is 2^(7-2)%7, which is 4, and then we take the mod that value
// (10/2)%7 => (10*4)%7 = 5
// This way modular inverse helps us to calculate the output without performing division.
