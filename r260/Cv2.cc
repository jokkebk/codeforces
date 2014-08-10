#include <iostream>
#include <vector>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    vector<int> c(100001);
    LL n, a, with = 0, without = 0;

	cin >> n;
    REP(n) {
        cin >> a;
        c[a]++;
    }

    FORE(i,1,100000) {
        LL w = without + (LL)i * c[i], wo = max(with, without);
        with = w, without = wo;
    }

    cout << max(with, without) << endl;

    return 0;
}
