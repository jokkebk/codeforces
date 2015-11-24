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

#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n);

    FOR(i,0,n) cin >> a[i];

    int cur=a[0], eqlen=1, len=1, prev=-1, best=0;
    //cout << cur << " now, previous " << prev << ", lengths " << eqlen << " and " << len << endl;

    FOR(i,1,n) {
        if(a[i] == cur) {
            eqlen++; len++;
        } else {
            if(prev==a[i]) {
                eqlen = 1;
                len++;
            } else {
                best = MAX(best, len);
                len = eqlen + 1;
                eqlen = 1;
            }
            prev = cur;
            cur = a[i];
        }
        //cout << "a[" << i << "] = " << a[i] << ": " << cur << " now, previous " << prev << ", lengths " << eqlen << " and " << len << endl;
    }

    cout << MAX(best, len) << endl;

    return 0;
}
