#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef unsigned long long ULL;

// Binary search for highest bit position (1 << hibit(n)) <= n
int hibit(ULL n) {
    int pos = 0;
    ULL nn;

    for(int s=32; s && n; s>>=1) {
        nn = n >> s;
        if(!nn) continue;
        pos += s;
        n = nn;
    }

    return pos;
}

// n choose k from Knuth
ULL C(ULL n, ULL k) {
    if(k > n) return 0;

    ULL r = 1;
    for(ULL d=1; d<=k; d++) {
        r *= n--;
        r /= d;
    }

    return r;
}

// amount of numbers <= n that have exactly k bits set
ULL nums(ULL n, int k) {
    if(n < (ULL)k) return 0; // impossible
    if(!k) return 1; // regardless of n

    ULL hi = hibit(n);

    return C(hi, k) + nums(n ^ ((ULL)1<<hi), k-1);
}

ULL search(ULL m, int k) {
    ULL n, hi, mid, lo;

    if(!m) return 1;

    for(hi = m; 1; hi = min(2*hi, (ULL)1e18)) {
        n = nums(2*hi, k) - nums(hi, k);
        if(n >= m) break; // time to go
    }

    if(n == m) return hi;

    lo = hi / 2;

    do {
        mid = (hi + lo) / 2;
        n = nums(2*mid, k) - nums(mid, k);
        if(n < m) lo = mid; else hi = mid;
    } while(n != m && hi - lo > 1);

    return mid;
}

int main() {
    ULL m;
    int k;

    cin >> m >> k;
    cout << search(m, k) << endl;

    return 0;
}
