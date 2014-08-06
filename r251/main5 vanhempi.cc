#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define PRIMES 65
#define FACTORS 100000
#define BITS 6

// Primes that may divide 100 000 (other than the number itself)
int primes[PRIMES] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
    157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233,
    239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313
};

int factors[FACTORS]; // largest factor from above primes

int bits[1 << BITS]; // amount of bits in a number

void precalc() {
    int i, j;

    // Initialize factor precalc
    for(i = 0; i < FACTORS; i += 2) {
        factors[i] = 2;
        factors[i+1] = 0;
    }

    for(i = 1; i < PRIMES; i++)
        for(j = primes[i]; j < FACTORS; j += primes[i])
            factors[j] = primes[i];

    // Initialize bits precalc
    for(i = 0; i < (1 << BITS); i += 2) {
        bits[i] = 0;
        bits[i+1] = 1;
    }

    for(i = 2; i <= (1 << BITS); i <<= 1)
        for(j = 2; j <= (1 << BITS); j++)
            if(j & i)
                bits[j]++;
}

int primeFactors(int n, int *fr) {
    int frs = 0, i, fact;

    while(1) {
        fact = factors[n];

        if(!fact)
            return frs; // rest is prime
        else
            fr[frs++] = fact;

        for(n /= fact; n % fact == 0; n /= fact) {} // consume
    }
}

// Combination modulo 10^5+7
int C(long long n, long long k) {
    long long r = 1, d;

    if (k > n)
        return 0;

    for(d = 1; d <= k; d++) {
        r *= n--;
        r /= d;

        if(r > 1000000007)
            r %= 1000000007;
    }

    return r;
}

int ways(int candies, int friends) {
    return C(candies - 1, friends - 1);
}

int polynomWays(int n, int f, int *fr, int frs) {
    int i, j, k, candies;
    long long total = 0;

    for(i = 0; i < (1 << frs); i++) {
        candies = n;

        for(j = 1, k = 0; j < (1 << frs); j <<= 1, k++)
            if(i & j)
                candies /= fr[k];

        if(bits[i] & 1)
            total = (total - (long long)ways(candies, f)) % 1000000007;
        else
            total = (total + (long long)ways(candies, f)) % 1000000007;
    }

    return total < 0 ? total + 1000000007 : total;
}

int main() {
    int q, f, n, i, fr[10], frs;
    //int w[QUERIES];

    precalc();

    cin >> q;

    for(i=0; i<q; i++) {
        cin >> n >> f;

        frs = primeFactors(n, fr);

        if(frs) { // non-prime
            //cout << "frs of " << n << ":";
            //for(i=0; i<frs; i++)
            //    cout << " " << fr[i];
            //cout << endl;
            cout << polynomWays(n, f, fr, frs) << endl;
        } else { // prime
            cout << ways(n, f) << endl;
        }
    }

    return 0;
}
