#include <iostream>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)

int m, n, t[50000][5], r[50000];

int main() {
    cin >> m >> n;

    FOR(i,0,m) {
        r[i] = 0;
        FOR(j,0,n) cin >> t[i][j];
    }

    FOR(j,0,n) FOR(i,0,m) r[i] = max(i ? r[i-1] : 0, r[i]) + t[i][j];

    FOR(i,0,m) cout << r[i] << " ";

    return 0;
}
