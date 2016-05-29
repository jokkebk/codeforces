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

#define SH(l,a) (((l)+1)/((a)+1))

int main() {
    int n, k, a, m, x, l, r, sh;
    set<int> shot = {0}; // left edge

    cin >> n >> k >> a >> m;
    shot.insert(n+1); // right edge

    sh = SH(n,a);

    FORE(i,1,m) {
        cin >> x;
        auto next = shot.upper_bound(x);
        r = *next--; l = *next;
        if(l == x) continue; // no change
        sh -= SH(r-l-1,a) - SH(x-l-1,a) - SH(r-x-1,a);
        if(sh < k) {
            cout << i << endl;
            return 0;
        }
        shot.insert(x);
    }

    cout << -1 << endl;

    return 0;
}
