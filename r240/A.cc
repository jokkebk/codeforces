#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    vector<int> l;
    int n, m, b;

    cin >> n >> m;
	l.resize(n+1);
	REP(m) {
		cin >> b;
		FORE(i,b,n) if(!l[i]) l[i] = b;
	}

	FORE(i,1,n) cout << l[i] << " ";

    return 0;
}
