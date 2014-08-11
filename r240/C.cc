#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
	int n, k, p;

    cin >> n >> k;
	p = n/2;

	if(k < p || (!p && k)) {
		cout << -1;
		return 0;
	} else if(!p && !k) {
		cout << 1;
		return 0;
	}

	k -= --p; // p-1 pairs with gcd(a,b) = 1
	cout << 2*k << " " << 3*k << " ";

	for(int i=1; p; i+=2) {
		if(i == 3*k || i+1 == 3*k || i+1 == 2*k) continue;
		cout << i << " " << i+1 << " ";
		--p;
	}

	if(n%2) cout << 1000003;

    return 0;
}
