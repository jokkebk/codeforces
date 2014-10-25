#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

LL c1, c2, x, y, v, m;

bool ok(LL n) {
    LL nok1 = n / x, nok2 = n / y, nok12 = n / (x*y);
    LL okboth = n - nok1 - nok2 + nok12;

    //cout << "Trying " << n << ": " << okboth << " OK for both" << endl;

    // Reserve numbers for friend 1
    okboth -= max(0LL, c1 - (nok2 - nok12));

    // Reserve numbers for friend 2
    okboth -= max(0LL, c2 - (nok1 - nok12));

    //cout << okboth << " numbers left over" << endl;

    return okboth >= 0;
}

int main() {
    cin >> c1 >> c2 >> x >> y;

    for(v=(1LL<<32) - 1, m=(1LL<<31); v && m; m/=2)
        if(ok(v-m))
            v -= m;

    cout << v;

    return 0;
}
