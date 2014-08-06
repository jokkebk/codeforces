#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define REP(n) for(LL _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(LL i=a; i<b; ++i)
#define FORE(i,a,b) for(LL i=a; i<=b; ++i)

typedef long long LL;

int main() {
    LL n, m, k, p, v, r, c, best = -1e18;
    vector<LL> rs, cs, rp, cp; // row and column sums & pleasure values
    priority_queue<LL> rq, cq; // "current" row and column sums queue

    cin >> n >> m >> k >> p;

    rs.resize(n);
    cs.resize(m);

    rp.resize(k+1);
    cp.resize(k+1);

    FOR(i,0,n) FOR(j,0,m) {
        cin >> v;
        rs[i] += v;
        cs[j] += v;
    }

    FOR(i,0,n) rq.push(rs[i]);
    FOR(j,0,m) cq.push(cs[j]);

    FORE(i, 1, k) {
        r = rq.top(); rq.pop(); rq.push(r - p * m);
        c = cq.top(); cq.pop(); cq.push(c - p * n);
        rp[i] = rp[i-1] + r;
        cp[i] = cp[i-1] + c;
    }

    for(LL i = 0; i <= k; ++i)
        best = max(best, cp[i] + rp[k-i] - i * (k-i) * p);

    cout << best << endl;

    return 0;
}
