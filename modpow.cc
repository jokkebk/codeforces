#include <iostream>

using namespace std;

typedef long long LL;

LL modpow(LL a, LL k, LL p) { // a^k % p
    LL ret = 1;
    while(k) {
        if(k % 2) ret = (ret * a) % p;
        k /= 2;
        a = (a * a) % p;
    }
    return ret;
}

LL modinv(LL a, LL p) {
    return modpow(a, p-2, p);
}

LL Pmod(LL n, LL k, LL p) { // ways to choose k from p
    LL res = 1;
    for(LL i = n; i > n-k; --i) res = (res * i) % p;
    return res;
}
// The combination calculation is adapted, simplified, and precalculated from:
// http://stackoverflow.com/questions/10118137/fast-n-choose-k-mod-p-for-large-n
LL Cmod(LL n, LL k, LL p) {
    if(k > n) return 0;
    if(k == n || k == 0) return 1;
    return (Pmod(n, k, p) * modinv(Pmod(k, k, p), p)) % p;
}

/* 
 * calculates (a * b) % c taking into account that a * b might overflow 
 */
LL mulmod(LL a, LL b, LL mod) {
    LL x = 0,y = a % mod;
    while (b > 0) {
        if (b % 2 == 1)
            x = (x + y) % mod;
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(LL p) {
    static int bases[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };

    if (p < 2) return false;
    else if (p > 2 && p%2 == 0) return false;

    LL s = p - 1;

    while(s % 2 == 0) s /= 2;

    for(int i = 0; i < 7; i++) {
        LL a = bases[i]; // rand() % (p - 1) + 1;
        LL temp = s, mod = modpow(a, temp, p);

        while (temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }

        if (mod != p - 1 && temp % 2 == 0)
            return false;
    }

    return true;
}

int main() {
    LL n, k, p = 1e9+7;

    do {
        cin >> n >> k;
        cout << Cmod(n, k, p) << endl;
        cout << Miller(n) << endl;
    } while(n);

    return 0;
}
