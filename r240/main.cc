#include <iostream>
#include <vector>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int n, k, prime[1000], primes, f[12], p[12];

void recurseFactors(int i, int prod, int from) {
	// print current
	cout << "1";
	FOR(j,0,i) cout << " * " << f[j] << "^" << p[j];
	cout << " = " << prod << endl;

	FOR(j,from,primes) {
		f[i] = prime[j], p[i] = 1;
		for(int pr = prod * f[i]; pr <= n; pr *= f[i], ++p[i])
			recurseFactors(i+1, pr, j+1);
	}
}

int main() {
    cin >> n >> k;

	FOR(i,2,n) {
		bool isPrime = true;
		for(int j=2; j*j <= i; ++j) if(i%j == 0) isPrime = false;
		if(isPrime) prime[primes++] = i;
	}

	FOR(i,0,primes) cout << prime[i] << endl;

	recurseFactors(0, 1, 0);

	return 0;
}
