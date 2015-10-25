#include <cstdio>
#include <iostream>
#include <iomanip>
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
#define ABS(a) (((a)<0) ? -(a) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int main() {
    int n, m;
    char x, y, at[256], c[256];
    string s;

    FORE(i,'a','z') at[i] = c[i] = i;

    cin >> n >> m >> s;

    REP(m) {
        cin >> x >> y;
        if(x != y) SWAP(at[x], at[y]);
    }

    FORE(i,'a','z') c[at[i]] = i;

    FOR(i,0,s.size()) cout << c[s[i]]; cout << endl;

    return 0;
}
