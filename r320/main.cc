#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;
typedef unsigned long long ULL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ULL n, k, x, mul=1, one=0, two=0, max=0;

    cin >> n >> k >> x;

    REP(k) mul *= x;

    vector<LL> a(n);

    FOR(i,0,n) {
        cin >> a[i];
        two |= one & a[i];
        one |= a[i];
    }

    FOR(i,0,n) max = MAX(max, a[i]*mul | (one & ~a[i]) | two);

    cout << max << endl;

    return 0;
}
