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
    string s;
    vector<vector<pair<int,char>>> col(8);

    FOR(r,0,8) {
        cin >> s;
        FOR(c,0,8) {
            if(s[c]=='.') continue;
            col[c].push_back(make_pair(r, s[c]));
        }
    }

    int A=9, B=9;
    FOR(c,0,8) {
        if(col[c].empty()) continue;
        if(col[c][0].se == 'W') A = MIN(A, col[c][0].fi);
        if(col[c].back().se == 'B') B = MIN(B, 7-col[c].back().fi);
    }

    cout << (A<=B ? "A" : "B") << endl;

    return 0;
}
