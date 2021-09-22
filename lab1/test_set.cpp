#include <iostream>
#include "TSet.h"

using namespace std;

int main() {
    cout << "Set testing program   " << endl;
    cout << "======================" << endl;
    cout << "Algorithm:            " << endl;
    cout << "Sieve of Eratosthenes " << endl;
    cout << "Finds all prime numbers in range [1, n]" << endl;
    cout << "======================" << endl;
    cout << "Enter n (0 < n < 2^31):"<< endl;
    size_t n;
    cin >> n;
    cout << "======================" << endl;

    TSet primes = {n + 1};
    primes = ~primes;

    // 0 and 1 are not prime
    primes.remove(0);
    primes.remove(1);
    // For every number from 2 to sqrt(n)
    for (size_t i = 2; i*i <= n; ++i) {
        // If it's not prime, skip
        if (!primes.contains(i))
            continue;
        // For every number j that that can be divided by i
        for (size_t j = 2*i; j <= n; j += i) {
            // If i divides j, then j is not prime
            primes.remove(j);
        }
    }

    cout << "All primes in range [1, " << n << "]:" << endl;
    cout << primes << endl;

    cout << "======================" << endl;
    cout << "Finished testing       " << endl;

    return 0;
}
