#include <cstdio>
#include <cstdlib>
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

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define ABS(a) (((a)<0) ? -(a) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int main() {
    LL n, k, N=1, m=1;

    cin >> n >> k;

    FOR(i,1,k) m *= 10;

    vector<LL> a(n/k), b(n/k);

    FOR(i,0,n/k) cin >> a[i];
    FOR(i,0,n/k) cin >> b[i];

    FOR(i,0,n/k) {
        LL M = (m*10-1)/a[i]+1;
        LL low = b[i]*m, high = (b[i]+1)*m-1;
        high -= high%a[i]; // last number divisible by a[i]
        if(high >= low) {
            low -= low%a[i];
            if(low < b[i]*m) low += a[i];
            M -= (high - low)/a[i] + 1;
        }
        N = (N * M) % Inf;
    }

    cout << N << endl;

    return 0;
}
