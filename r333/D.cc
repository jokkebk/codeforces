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

#define TRI(a,b) ((b-a-1)*(b-a)/2)
#define D(i) ABS(h[i] - h[i-1])

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> h(n), L(n), R(n);
    FOR(i,0,n) cin >> h[i];

    set<pair<int,int>> pq;
    FOR(i,1,n) pq.insert(make_pair(-D(i),i));

    set<int> edge = {0, n};
    for(auto p : pq) {
        auto lb = edge.lower_bound(p.se);
        R[p.se] = *lb--;
        L[p.se] = *lb;
        edge.insert(p.se);
    }

    REP(q) {
        LL sum = 0, l, r;
        cin >> l >> r;
        FOR(i, l, r) {
            LL l1 = MAX(l-1, L[i]), r1 = MIN(r, R[i]);
            sum += D(i) * (TRI(l1,r1) - TRI(l1,i) - TRI(i,r1));
        }
        cout << sum << endl;
    }

    return 0;
}
