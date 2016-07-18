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
#define FOR(i,v,b) for(__typeof(b) i=v; i<b; ++i)
#define FORE(i,v,b) for(__typeof(b) i=v; i<=b; ++i)
#define S(x) scanf("%d", &(x))
#define fi first
#define se second

typedef long long LL;

#define Inf 1000000007

int main() {
    int n, m, v;
    map<int,int> l;

    cin >> n;

    FOR(i,0,n) cin >> v, l[v]++;

    cin >> m;

    vector<pair<int,int>> bc(m);

    FOR(i,0,m) cin >> v, bc[i].fi = l[v];
    FOR(i,0,m) cin >> v, bc[i].se = l[v];

    cout << max_element(bc.begin(), bc.end()) - bc.begin() + 1 << endl;

    return 0;
}
