#include <cstdio>
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
    int n, m;

    S(n); S(m);

    if(n==1) {
        cout << 1 << endl;
    } else if(m-1 >= n-m) {
        cout << m-1 << endl;
    } else {
        cout << m+1 << endl;
    }

    return 0;
}
