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
    int n, turn=0;

    S(n);

    vector<int> a(n);

    FOR(i,0,n) S(a[i]);

    for(int info=0; info < n; turn++) {
        FOR(i,0,n) {
            int p = (turn&1) ? n-1-i : i;
            if(info >= a[p]) {
                info++;
                a[p] = 9999; // don't double-process
            }
        }
    }

    cout << turn-1 << endl;

    return 0;
}
