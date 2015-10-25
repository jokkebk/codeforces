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
    int n, k, l, nb, nc;

    cin >> n >> k;
    l = n/k;
    nc = n%k;
    nb = k - nc;

    vector<LL> a(n), b(n-l+1), c(n-l), d(n-1);

    FOR(i,0,n) cin >> a[i];

    sort(a.begin(), a.end());

    FOR(i,0,n-1) d[i] = a[i+1]-a[i]; // difference

    FOR(i,0,l-1) b[0] += d[i]; // cumulative sum of short
    FOR(i,1,n-l+1) b[i] = b[i-1] - d[i-1] + d[i+l-2];

    FOR(i,0,n-l) c[i] = b[i] + d[i+l-1]; // cumsum of long

    vector<vector<int>> dp(nb+1, vector<int>(nc+1)); // dp[0][0] = 0;

    FOR(i,0,nb) dp[i+1][0] = dp[i][0] + b[i*l];
    
    FOR(i,0,nc) dp[0][i+1] = dp[0][i] + c[i*(l+1)];

    FOR(i,0,nb)
        FOR(j,0,nc)
            dp[i+1][j+1] = MIN(dp[i][j+1] + b[i*l + (j+1)*(l+1)],
                    dp[i+1][j] + c[(i+1)*l + j*(l+1)]);
    
    cout << dp[nb][nc] << endl;

    return 0;
}
