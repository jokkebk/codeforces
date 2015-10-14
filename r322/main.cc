#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

// Basic idea is that from position of gas station, this type
// of gas will last for s miles. Higher quality gas segments
// will override lower quality ones, for example if at x=0
// there is a premium station and s=100, and at x=10 a regular
// one, at 0-100 we have a premium segment and 100-110 a regular
// one. When we begin driving, we skip s km forward and calculate
// lengths of different segments until destination.
int main() {
    int f, e, s, n, m, t, x, l;
    vector<pair<int,int>> g;

    S(e); S(s); S(n); S(m);

    REP(n) {
        S(t); S(x);
        g.push_back({x,t});
    }

    sort(g.begin(), g.end());
    g.push_back({Inf,0});

    // Gas of three types and unobtanium at bottom
    int gas[4] = {2*Inf,0,0,0};
    vector<tuple<int,int,int>> xlt; // pos, len, type

    x = -Inf;
    for(auto p : g) {
        int xn = p.first; t = p.second;

        for(int t1=3, dx=0; t1>=0; t1--) { // Emit all segments before x
            l = MIN(gas[t1], xn-x);
            gas[t1] -= l;
            if(l > dx) {
                xlt.push_back(make_tuple(x+dx, l-dx, t1));
                dx = l;
            }
        }

        x = xn;
        gas[t] = s;
    }
    xlt.push_back(make_tuple(Inf, 0, 0));

    vector<vector<int>> need(4, vector<int>(1));

    for(auto t : xlt)
        FOR(i,0,4) need[i].push_back(need[i].back() + (get<2>(t)==i ? get<1>(t) : 0));

    int end = lower_bound(xlt.begin(), xlt.end(), make_tuple(e, 0, 0)) - xlt.begin();
    int endtype = get<2>(xlt[end-1]);

    // f < e and we handle e-f <= s separately so begin != end
    need[endtype][end] -= get<0>(xlt[end]) - e;
    
    REP(m) {
        S(f);
        if(e-f <= s) { // Enough fuel
            cout << "0 0" << endl;
            continue;
        }
        int start = lower_bound(xlt.begin(), xlt.end(), make_tuple(f+s+1, 0, 0)) - xlt.begin() - 1;
        int starttype = get<2>(xlt[start]);

        if(starttype == 0 || endtype == 0 || need[0][end] != need[0][start]) {
            cout << "-1 -1" << endl; // unobtanium needed
            continue;
        }

        int need1 = need[1][end] - need[1][start];
        int need2 = need[2][end] - need[2][start];

        if(starttype == 1) need1 -= f+s - get<0>(xlt[start]);
        if(starttype == 2) need2 -= f+s - get<0>(xlt[start]);

        cout << need1 << " " << need2 << endl;
    }

    return 0;
}
