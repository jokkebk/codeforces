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
    int n, a[100];

    cin >> n;

	FOR(i,0,n) cin >> a[i];

    sort(a,a+n);

    FOR(i,0,n) cout << a[i] << " ";
    cout << endl;

    return 0;
}
