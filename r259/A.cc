#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
	int n, m;
    long double p[100001], E = 0;

	cin >> m >> n;

    FORE(i,1,m) {
        p[i] = pow((long double)i/m, n);
        //cout << "P(X <= " << i << ") = " << p[i] << endl;
    }

    for(int i=m; i>0; --i) {
        p[i] -= p[i-1];
        //cout << "P(X < " << i << ") = " << p[i] << endl;
        E += p[i] * i;
    }
    cout.precision(15);
    cout << E << endl;

    return 0;
}
