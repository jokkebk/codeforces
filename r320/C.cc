#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a >> b;

    if(b>a) {
        cout << -1 << endl;
        return 0;
    }

    int r = a/b;
    if(!(r&1)) r--;

    cout << setprecision(11) << (double)(a+b)/(r+1) << endl;

    return 0;
}
