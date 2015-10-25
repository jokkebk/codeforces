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

pair<double,double> scale(pair<double,double> a, double s) {
    return make_pair(a.first*s, a.second*s);
}

pair<double,double> sub(pair<double,double> a, pair<double,double> b) {
    return make_pair(a.first-b.first, a.second-b.second);
}

double len(pair<double,double> a) {
    return sqrt(a.first*a.first + a.second*a.second);
}

double x1, y1, x2, y2, vmax, t1, t2, vx, vy, wx, wy;
pair<double,double> p, w, v;

double dist(double t) {
    if(t <= t1) return len(sub(p, scale(v, t)));
    pair<double,double> s = sub(p, scale(v, t1));
    return len(sub(s, scale(w, t-t1)));
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> vmax >> t1;
    cin >> vx >> vy;
    cin >> wx >> wy;

    p=make_pair(x2-x1,y2-y1);
    w=make_pair(wx,wy);
    v=make_pair(vx,vy);

    double tmin=0, tmax=1e10, diff=1, t;
    REP(80) {
        t = (tmin+tmax)/2;
        if(dist(t) > vmax*t) tmin = t;
        else tmax = t;
    }

    cout << setprecision(15) << t << endl;

    return 0;
}
