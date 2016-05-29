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
    LL n, k, s=0;

    cin >> n >> k;

    vector<LL> a(n);
    vector<vector<LL>> c(3, vector<LL>(n));

    FOR(i,0,n) cin >> a[i], c[0][i] = 1;

    FOR(j,1,3) {
        map<LL,LL> cnt;
        for(int i=n-1; i>=0; i--) {
            c[j][i] = cnt[k*a[i]];
            cnt[a[i]] += c[j-1][i];
        }
    }

    FOR(i,0,n) s += c[2][i];
    cout << s << endl;

    return 0;
}
