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

int main() {
    LL n, k, p = 1e9+7;

    do {
        cin >> n >> k;
        cout << Cmod(n, k, p) << endl;
    } while(n);

    return 0;
}
