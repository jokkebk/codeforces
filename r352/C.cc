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

double D(pair<double,double> a, pair<double,double> b) {
    double dx = a.fi-b.fi;
    double dy = a.se-b.se;
    return sqrt(dx*dx + dy*dy);
}

double try2(pair<double,int> a, pair<double,int> b) {
    return (a.se != b.se) ? a.fi + b.fi : 1e20;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pair<double,double> a, b, t;

    cin >> a.fi >> a.se >> b.fi >> b.se >> t.fi >> t.se;
 
    int n;
    cin >> n;

    vector<pair<double,double>> bot(n);

    FOR(i,0,n) cin >> bot[i].fi >> bot[i].se;

    if(n == 1) {
        cout << setprecision(11) << min(D(a, bot[0]), D(b, bot[0])) + D(t, bot[0]) << endl;
        return 0;
    }

    vector<pair<double,int>> da(n);
    vector<pair<double,int>> db(n);

    FOR(i,0,n) da[i] = make_pair(D(a, bot[i]) - D(t, bot[i]), i);
    FOR(i,0,n) db[i] = make_pair(D(b, bot[i]) - D(t, bot[i]), i);

    sort(da.begin(), da.end());
    sort(db.begin(), db.end());

    double dist = 0;
    for(auto v : bot) dist += 2*D(t, v);

    double best = 1e20;
    best = min(best, try2(da[0], db[0]));
    best = min(best, try2(da[0], db[1]));
    best = min(best, try2(da[1], db[0]));
    best = min(best, try2(da[1], db[1]));
    best = min(best, da[0].fi);
    best = min(best, db[0].fi);

    cout << setprecision(11) << dist + best << endl;

    return 0;
}
