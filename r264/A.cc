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
    int n, s, x, y, best = -1;

    cin >> n >> s;

	REP(n) {
		cin >> x >> y;
		if(s * 100 < x * 100 + y) continue;
		best = max(best, (100-y) % 100);
	}

    cout << best;

    return 0;
}
