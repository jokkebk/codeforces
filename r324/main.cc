#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

bool prime(int n) {
    if(n<2) return false;
    for(int i=2; i*i<=n; i++) if(n%i == 0) return false;
    return true;
}

// All numbers below 3325581707333960528 can be represented as sum of
// two primes, smaller of which is below 10 000
// Largest range of non-primes below 10^9 is 281 numbers
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    for(i=n; !prime(i); i--) {}

    if(i==n) {
        cout << 1 << endl << n << endl;
    } else if(prime(n-i)) {
        cout << 2 << endl << i << " " << n-i << endl;
    } else {
        FOR(j,2,150) {
            if(prime(j) && prime(n-i-j)) {
                cout << 3 << endl;
                cout << i << " " << j << " " << n-i-j  << endl;
                break;
            }
        }
    }

    return 0;
}
