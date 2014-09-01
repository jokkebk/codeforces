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
    int n, h, hi = 0;

    cin >> n;

	REP(n) {
		cin >> h;
		hi = max(hi, h);
	}

    cout << hi;

    return 0;
}
