#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

int main() {
    int n, h, a[2002], ls = 0, rs = 0;
    LL ways = 1;
    bool isL[2001], isR[2001];

    cin >> n >> h;

    a[0] = a[n+1] = h; // easier

    FORE(i,1,n) cin >> a[i];

    FORE(i,0,n) if(abs(a[i] - a[i+1]) > 1) {
        cout << 0;
        return 0;
    }

    FORE(i,1,n) {
        isL[i] = a[i] < a[i-1];
        isR[i] = a[i] < a[i+1];
        cout << isL[i] << "/" << isR[i] << " ";
    }
    cout << endl;

    FORE(i,1,n) {
        if(isL[i]) ls++;
        if(isR[i]) {
            ways = (ways * ls) % 1000000007;
            ls--;
        }
    }

    cout << ways;

    return 0;
}
