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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    string a, b;

    cin >> n >> t;
    REP(2) getline(cin, a);
    getline(cin, b);

    int same=0;

    FOR(i,0,n) if(a[i] == b[i]) same++;

    int nsame = n-t, ndiff = 0;

    if(nsame > same) {
        ndiff = (nsame - same) * 2;
        nsame = same;
    }

    if(ndiff + nsame > n) {
        cout << -1 << endl;
        return 0;
    }
    
    FOR(i,0,n) {
        if(a[i] == b[i]) {
            if(nsame) {
                cout << a[i];
                nsame--;
            } else cout << (a[i] == 'a' ? 'b' : 'a');
        } else {
            if(!ndiff) { // no need to match a or b
                FOR(c,'a','d') if(a[i] != c && b[i] != c) {
                    cout << c;
                    break;
                }
            } else {
                cout << ((ndiff-- & 1) ? a[i] : b[i]);
            }
        }
    }

    cout << endl;

    return 0;
}
