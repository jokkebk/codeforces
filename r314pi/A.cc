#include <cstdio>
#include <cstdlib>
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
#define ABS(a) (((a)<0) ? -(a) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int main() {
    int n;

    cin >> n;

    vector<int> a(n);

    FOR(i,0,n) cin >> a[i];

    FOR(i,0,n) {
        int min = 2*Inf, max = 0;

        if(i) {
            min = a[i] - a[i-1];
            max = a[i] - a[0];
        }

        if(i+1<n) {
            min = MIN(min, a[i+1]-a[i]);
            max = MAX(max, a[n-1]-a[i]);
        }

        cout << min << " " << max << endl;
    }

    return 0;
}
