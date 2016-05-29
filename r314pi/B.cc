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
    int n, r, cnt=0, max=0;
    char t;
    set<int> in;

    cin >> n;

    FOR(i,0,n) {
        cin >> t >> r;
        if(t=='+') {
            cnt++;
            in.insert(r);
        } else {
            if(in.count(r)) {
                cnt--;
                in.erase(r);
            } else max++;
        }
        max = MAX(max, cnt);
    }

    cout << max << endl;

    return 0;
}
