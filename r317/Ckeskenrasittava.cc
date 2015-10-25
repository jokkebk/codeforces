#include <cstdio>
#include <iostream>
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
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

LL ways(LL from, LL to) {
    return ((to+1)*(to+2) - from*(from+1)) / 2;
}

int main() {
    int a, b, c, l;

    cin >> a >> b >> c >> l;

    LL w=0;

    FOR(i,0,l) {
        int a2=a+i;
        int from = MAX(a2+1 - (b+c), (i?0:1)), to = l-i;
        if(from > to) continue;
        cout << "Increasing a by " << i << " to " << a2 << ", " << from << " to " << to << " for b+c = " << b+c << endl;
        cout << ways(from, to) << endl;
        w += ways(from, to);
    }

    cout << w << endl;

    return 0;
}
