#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    LL n, a, b, x;

    cin >> n >> a >> b;

	REP(n) {
		cin >> x;
		cout << (x*a) % b / a << " ";
	}

    return 0;
}
