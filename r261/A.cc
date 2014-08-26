#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
	int x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	if(x1 == x2 && y1 != y2) {
		int x3 = x1 + (y2 - y1);
		cout << x3 << " " << y1 << " " << x3 << " " << y2;
	} else if(y1 == y2 && x1 != x2) {
		int y3 = y1 + (x2 - x1);
		cout << x1 << " " << y3 << " " << x2 << " " << y3;
	} else if(abs(x1 - x2) == abs(y1 - y2)) {
		cout << x1 << " " << y2 << " " << x2 << " " << y1;
	} else cout << -1;

	return 0;
}
