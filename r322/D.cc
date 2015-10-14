#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

int main() {
    int x1, x2, x3, y1, y2, y3;
    char l1='A', l2='B', l3='C';

    S(x1); S(y1);
    S(x2); S(y2);
    S(x3); S(y3);

    // Make x largest
    if(x1 < y1) SWAP(x1, y1);
    if(x2 < y2) SWAP(x2, y2);
    if(x3 < y3) SWAP(x3, y3);

    // Bubble sort 1 > 2 > 3
    if(x2 < x3) { SWAP(x2, x3); SWAP(y2, y3); SWAP(l2, l3); }
    if(x1 < x2) { SWAP(x1, x2); SWAP(y1, y2); SWAP(l1, l2); }
    if(x2 < x3) { SWAP(x2, x3); SWAP(y2, y3); SWAP(l2, l3); }

    if(x1 == x2 && x2 == x3) {
        if(y1+y2+y3 != x1) {
            cout << -1 << endl;
        } else {
            cout << x1 << endl;
            REP(y1) { REP(x1) cout << l1; cout << endl; }
            REP(y2) { REP(x1) cout << l2; cout << endl; }
            REP(y3) { REP(x1) cout << l3; cout << endl; }
        }
    } else { // Company 1 will be on top, square size x1
        int sh = x1-y1;

        if(x2 != sh) SWAP(x2, y2);
        if(x3 != sh) SWAP(x3, y3);

        if(y2+y3 != x1) {
            cout << -1 << endl;
        } else {
            cout << x1 << endl;
            REP(y1) { REP(x1) cout << l1; cout << endl; }
            REP(sh) {
                REP(y2) cout << l2;
                REP(y3) cout << l3;
                cout << endl;
            }
        }
    }

    return 0;
}
