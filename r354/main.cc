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
#define fi first
#define se second

typedef long long LL;

#define Inf 1000000007

#define UP 1
#define RIGHT 2
#define DOWN 4
#define LEFT 8
#define ROT(a) ((((a)<<1)&15) + ((a)>>3))
#define C(l, x, y) ((l)*n*m + (x)*m + y)

map<char,int> tile = {
    {'+', 15},
    {'-', LEFT+RIGHT},
    {'|', UP+DOWN},
    {'^', UP},
    {'v', DOWN},
    {'>', RIGHT},
    {'<', LEFT},
    {'L', 15-LEFT},
    {'R', 15-RIGHT},
    {'U', 15-UP},
    {'D', 15-DOWN},
    {'*', 0},
};

int n, m, xt, yt, xm, ym;

vector<string> laby;

bool ok(char t, int d, int l, int x, int y) {
    if(x<0 || x>=n) return false;
    if(y<0 || y>=m) return false;
    int t1 = tile[t], t2 = ROT(ROT(tile[laby[x][y]])); // turn "facing"
    REP(l) t1 = ROT(t1), t2 = ROT(t2);
    return t1 & t2 & d;
}

int main() {
    cin >> n >> m;

    laby.resize(n);

    FOR(i,0,n) cin >> laby[i];

    cin >> xt >> yt >> xm >> ym;
    xt--, yt--, xm--, ym--;

    vector<bool> seen(n*m*4);
    deque<pair<int,int>> q = { {0, C(0, xt, yt)} };

    while(q.size()) {
        pair<int,int> p = q.front(); q.pop_front();
        int t = p.fi, pos = p.se;

        if(seen[pos]) continue; // again here
        seen[pos] = true; // mark seen

        int l = pos/n/m, y = pos%m, x = pos/m % n;

        if(x==xm && y==ym) {
            cout << t << endl;
            return 0;
        }

        q.push_back({t+1, C(l+1 & 3, x, y)}); // push button
        if(ok(laby[x][y], UP, l, x-1, y)) q.push_back({t+1, C(l, x-1, y)});
        if(ok(laby[x][y], DOWN, l, x+1, y)) q.push_back({t+1, C(l, x+1, y)});
        if(ok(laby[x][y], LEFT, l, x, y-1)) q.push_back({t+1, C(l, x, y-1)});
        if(ok(laby[x][y], RIGHT, l, x, y+1)) q.push_back({t+1, C(l, x, y+1)});
    }

    cout << -1 << endl;
    return 0;
}
