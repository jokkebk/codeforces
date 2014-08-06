#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    int n, x, y, mod;

    cin >> x >> y >> n;

    switch((n-1) % 6) {
        case 0: mod = x; break;
        case 1: mod = y; break;
        case 2: mod = y-x; break;
        case 3: mod = -x; break;
        case 4: mod = -y; break;
        default: mod = -y+x; break;
    }

    mod = mod % 1000000007;
    if(mod < 0) mod += 1000000007;

    cout << mod;

    return 0;
}
