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
    int n, r, ops = 0;
    bool lastRead = false;

    cin >> n;

    REP(n) {
        cin >> r;

        if(r) // need to read
            ops += lastRead ? 1 : 2;
        lastRead = r;
    }

    cout << (ops ? ops-1 : 0);

    return 0;
}
