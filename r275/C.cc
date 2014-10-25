#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

int main() {
    int n, k;

    cin >> n >> k;

    bool add = true;
    for(int a = k, val = 1; a >= 0; --a, add = !add) {
        cout << val << " ";
        val += add ? a : -a;
    }

    FORE(i,k+2,n) cout << i << " ";

    return 0;
}
