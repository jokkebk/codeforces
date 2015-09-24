#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))

int main() {
    int n, v, prev=1000000009;
    int best=0, nd=0;

    S(n);

    FOR(i,0,n) {
        S(v);
        if(v >= prev) {
            nd++;
        } else {
            best = MAX(best, nd);
            nd = 1;
        }
        prev = v;
    }

    cout << MAX(best, nd);

    return 0;
}
