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

    vector<int> a(n);

    FOR(i,0,n) S(a[i]);

    FOR(i,1,n-1)
        if(a[i-1]==1 && a[i+1]==1)
            a[i] = 2;

    int s = 0;
    FOR(i,0,n) if(a[i]) s++;
    cout << s << endl;

    return 0;
}
