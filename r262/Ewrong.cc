#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

pair<int,int> getP(double x, double y, int var) {
    int i = (var & 1) ? (int)floor(x) : (int)ceil(x),
        j = (var & 2) ? (int)floor(y) : (int)ceil(y);

    //cout << i << ", " << j << endl;

    return make_pair(i, j);
}

pair<int,int> p[8], bestP[8], origo = make_pair(0,0);
int n, r, bestD = -1;

int dist2(pair<int,int> & a, pair<int,int> & b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int getD() {
    int d = 0;
    FOR(i,0,n) {
        if(dist2(p[i], origo) > r*r) return -1;
        FOR(j,i+1,n) d += dist2(p[i], p[j]);
    }
    return d;
}

double pi = 4 * std::atan(1);

void recurse(int cur, int div) {
    if(cur == n) {
        int d = getD();
        if(d > bestD) {
            FOR(i,0,n) bestP[i] = p[i];
            bestD = d;
        }
    } else {
        double x = r * cos(2*pi*(double)cur/div),
               y = r * sin(2*pi*(double)cur/div);
        p[cur] = getP(x, y, 0); recurse(cur+1, div);
        p[cur] = getP(x, y, 1); recurse(cur+1, div);
        p[cur] = getP(x, y, 2); recurse(cur+1, div);
        p[cur] = getP(x, y, 3); recurse(cur+1, div);
    }
}

int main() {
    cin >> n >> r;

    FORE(i,1,n) recurse(0,i);

    cout << bestD << endl;
    FOR(i,0,n) cout << bestP[i].first << " " << bestP[i].second << endl;

    return 0;
}
