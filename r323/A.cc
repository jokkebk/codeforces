#include <cstdio>
#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))

int main() {
    int n, a, b;
    bool h[51], v[51];

    S(n);

    FORE(i,1,n) h[i] = v[i] = false;

    FORE(i, 1, n*n) {
        S(a); S(b);
        if(h[a] || v[b]) continue;
        cout << i << " ";
        h[a] = v[b] = true;
    }

    return 0;
}
