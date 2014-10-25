#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef long long LL;

int main() {
    LL n, a, b, best = 2e18, bestA = 0, bestB = 0;

    cin >> n >> a >> b;

    if(n*6 <= a*b) {
        cout << a*b << endl;
        cout << a << " " << b;
        return 0;
    }

    FOR(i,0,6) { // one of these will be 6m
        LL b2 = n*6 / (a+i);
        if(n*6 > (a+i)*b2) b2++; // need increment
        LL area = (a+i)*b2;
        if(area < best)
            best = area, bestA = a+i, bestB = b2;
    }

    cout << bestA*bestB << endl;
    cout << bestA << " " << bestB;

    return 0;
}
