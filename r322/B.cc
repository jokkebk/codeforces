#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))

int main() {
    int n;

    S(n);

    vector<int> h(n), m(n);

    FOR(i,0,n) S(h[i]), m[i] = h[i];

    for(int i=n-2; i>=0; i--) m[i] = MAX(m[i], m[i+1]);

    FOR(i,0,n-1) cout << MAX(0, m[i+1] - h[i] + 1) << " ";
    cout << 0 << endl;

    return 0;
}
