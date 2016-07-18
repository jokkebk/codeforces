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
#define fi first
#define se second

typedef long long LL;

#define Inf 1000000007

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> id(n);

    FOR(i,0,n) cin >> id[i];

    FOR(i,1,n+1) {
        if(k <= i) {
            cout << id[k-1] << endl;
            break;
        }
        k -= i;
    }

    return 0;
}
