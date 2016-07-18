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

int main() {
    int n, mex = 1;

    cin >> n;

    vector<int> a(n);

    FOR(i,0,n) cin >> a[i];

    sort(a.begin(), a.end());

    for(int v : a) if(v >= mex) mex++;

    cout << mex << endl;

    return 0;
}
