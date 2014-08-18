#include <iostream>
#include <vector>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

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

LL modinv(LL a, LL p) { return modpow(a, p-2, p); }

LL modP(LL n, LL k, LL p) { // ways to choose k from p
    LL res = 1;
    for(LL i = n; i > n-k; --i) res = (res * i) % p;
    return res;
}

// The combination calculation is adapted, simplified, and precalculated from:
// http://stackoverflow.com/questions/10118137/fast-n-choose-k-mod-p-for-large-n
LL modC(LL n, LL k, LL p) {
    if(k > n) return 0;
    if(k == n || k == 0) return 1;
    return (modP(n, k, p) * modinv(modP(k, k, p), p)) % p;
}

#define P 1000000007

int n, k, ways = 0, prime[1000], primes, f[12], p[12];

void recurseFactors(int i, int prod, int from) {
    LL wadd = 1;
    FOR(j,0,i) wadd = (modC(k-1 + p[j], k-1, P) * wadd) % P;
    ways = (ways + wadd) % P;

	FOR(j,from,primes) {
		f[i] = prime[j], p[i] = 1;
		for(int pr = prod * f[i]; pr <= n; pr *= f[i], ++p[i])
			recurseFactors(i+1, pr, j+1);
	}
}

int main() {
    cin >> n >> k;

	FORE(i,2,n) {
		bool isPrime = true;
		for(int j=2; j*j <= i; ++j) if(i%j == 0) isPrime = false;
		if(isPrime) prime[primes++] = i;
	}

	recurseFactors(0, 1, 0);

    cout << ways << endl;

	return 0;
}
