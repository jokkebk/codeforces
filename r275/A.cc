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
    LL l, r;

    cin >> l >> r;

    if(r - l < 2 || (r - l == 2 && (l & 1))) {
        cout << -1; // too small or just 3 and left is odd
    } else {
        if(l & 1) l++;
        cout << l << " " << l+1 << " " << l+2;
    }

    return 0;
}
