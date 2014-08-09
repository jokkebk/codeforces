#include <iostream>
#include <vector>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    vector<LL> c(100001), bestWith(100001), bestWithout(100001);
    int n, a;

	cin >> n;
    REP(n) {
        cin >> a;
        c[a]++;
    }

    FORE(i,1,100000) {
        bestWith[i] = bestWithout[i-1] + i * c[i];
        bestWithout[i] = max(bestWith[i-1], bestWithout[i-1]);
    }

    cout << max(bestWith[100000], bestWithout[100000]) << endl;

    return 0;
}
