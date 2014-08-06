#include <iostream>

#define P 1000000007
#define PRIMES 65
#define NUM 100000

int primes[PRIMES] = { // Primes that may divide 100 000
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
    157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233,
    239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313
};

int factors[NUM], above[NUM], below[NUM]; // factorization & factorial precalcs

long long degree(long long a, long long k, long long p) { // a^k % p
    long long ret = 1;

    while(k) {
        if(k % 2) ret = (ret * a) % p;
        k /= 2;
        a = (a * a) % p;
    }

    return ret;
}

// The combination calculation is adapted, simplified, and precalculated from:
// http://stackoverflow.com/questions/10118137/fast-n-choose-k-mod-p-for-large-n
long long C(int n, int k) {
    if(k > n)
        return 0;

    if(k == n || k == 0)
        return 1;

    long long ret = ((long long)above[n-1] * (long long)below[k-1]) % P;

    return (ret * (long long)below[n-k-1]) % P;
}

int calculate(int n, int f, int *fr, int frs) {
    int i, j, k, n1, neg;
    long long total = 0;

    for(i = 0; i < (1 << frs); i++) {
        for(n1 = n, j = 1, k = neg = 0; j < (1 << frs); j <<= 1, k++) {
            if(i & j) {
                n1 /= fr[k];
                neg = !neg;
            }
        }

        total = (total + (neg ? -C(n1-1, f-1) : C(n1-1, f-1))) % P;
    }

    return (total < 0) ? total + P : total; // ensure positive mod P
}

int main() {
    int q, f, n, n1, i, j, k, fr[10], frs;
    long long res = 1, inv = 1;

    // Initialize factor precalc, factor for 1000 in factors[999]
    for(i = 0; i < NUM; i += 2) {
        factors[i] = 0;
        factors[i+1] = 2;
    }

    for(i = 1; i < PRIMES; i++)
        for(j = primes[i] - 1; j < NUM; j += primes[i])
            factors[j] = primes[i];

    // Initialize n! and (n!)^-1 mod P precalc
    for(i = 1; i <= NUM; i++) {
        above[i-1] = res = (res * (long long)i) % P;
        below[i-1] = inv = (inv * degree(i, P-2, P)) % P;
    }

    std::cin >> q;

    for(i=0; i<q; i++) {
        std::cin >> n >> f;

        // Find prime factors for n
        for(frs = 0, n1 = n; (k = factors[n1-1]); ) {
            fr[frs++] = k; // add prime factor
            for(n1 /= k; n1 % k == 0; n1 /= k) {} // consume this prime
        }

        if(n1 > 1) // one last prime bigger than 313 still left
            fr[frs++] = n1;

        std::cout << calculate(n, f, fr, frs) << std::endl;
    }

    return 0;
}
