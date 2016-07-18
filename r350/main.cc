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
    int n, k, c=0, v;

    cin >> n >> k;

    vector<tuple<int,int,int>> ing(n);

    FOR(i,0,n) cin >> ing[i].fi;
    FOR(i,0,n) {
        cin >> v; // amount of ingredient
        ing[i].se = v % ing[i].fi; // residual
        ing[i].fi = v / ing[i].fi; // amount of cookies
    }

    sort(ing.begin(), ing.end());

    int cum=0;

    FOR(i,1,n) {

    }

        cout << i.fi << " cookies and " << i.se << endl;
    return 0;
}
