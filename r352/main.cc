#include <cstdio>
#include <cmath>
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

#define Inf 1000000007

#define fi first
#define se second

LL givetake(int k, vector<int> & vs, int dir) {
    LL n = vs.size(), amt = vs.back(), c;
    for(LL i=0, k2=k; i<n-1; i++) {
        c = (i+1) * abs(vs[i] - vs[i+1]);

        if(k2 <= c) {
            amt = vs[i] + dir * k2 / (i+1);
            break;
        } else
            k2 -= c;
    }
    return amt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL n, k, c, s = 0;

    cin >> n >> k;

    vector<int> vs(n);
    FOR(i,0,n) cin >> vs[i], s += vs[i];

    sort(vs.begin(), vs.end());
    LL poor = givetake(k, vs, 1);

    reverse(vs.begin(), vs.end());
    LL rich = givetake(k, vs, -1);

    cout << max(rich-poor, s%n ? 1LL : 0LL) << endl;

    return 0;
}
