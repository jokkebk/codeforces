#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int gcd[32][32];

int main() {
	int n, a[100], b[100], best[100][32], prev[100][32];

    FOR(i,1,31) {
        FOR(j,1,31) {
            gcd[i][j] = 0;
            FOR(k,2,31)
                if(i%k == 0 && j%k == 0)
                    gcd[i][j] = 1;
        }
    }

	cin >> n;

    FOR(i,0,n) {
        cin >> a[i];
    }

    FOR(i,1,31) {
        best[0][i] = abs(a[0] - i);
    }

    cout << 0 << endl;

    int top, topI;

    FOR(i,1,n) {
        cout << i << endl;
        FOR(j,1,31) { // try different j
            top = 9999;
            topI = -1;

            FOR(k,1,31) { // try from different previous k
                if(gcd[j][k]) continue; // not possible

                int diff = best[i-1][k] + abs(a[i] - j);
                if(diff < top) top = diff, topI = k;
            }

            best[i][j] = top;
            prev[i][j] = topI;
        }
    }
    
    cout << 99 << endl;

    top = 9999;
    topI = -1;

    FOR(i,1,31)
        if(best[n-1][i] < top)
            top = best[n-1][i], topI = i;

    cout << 100 << endl;
    for(int i=n-1; i>=0; i--) {
        b[i] = topI;
        topI = prev[i][topI];
    }

    cout << 101 << endl;
    FOR(i,0,n) cout << b[i] << " ";
    cout << endl;

    return 0;
}
