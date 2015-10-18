#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
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
    int n;

    S(n);

    vector<int> a(n), b(n), c(n);

    // Cumulative sum right
    a[0] = 0;
    FOR(i,1,n) S(a[i]), a[i] += a[i-1];

    // Cumulative sum left
    c[n-1] = 0;
    FOR(i,0,n-1) S(c[i]);
    for(int i=n-2; i>=0; i--) c[i] += c[i+1];

    FOR(i,0,n) {
        S(b[i]);
        b[i] += a[i] + c[i];
    }

    sort(b.begin(), b.end());
    //FOR(i,0,n) cout << b[i] << " "; cout << endl;
    cout << b[0] + b[1] << endl;

    return 0;
}
