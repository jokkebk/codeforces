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
    int n, m;

    cin >> n >> m;

    vector<int> a(5, n/5), b(5, m/5);

    FOR(i,0,n%5) a[(i+1)%5]++;
    FOR(i,0,m%5) b[(i+1)%5]++;

    LL ways = 0;

    FOR(i,0,5) ways += (LL)a[i] * b[(5-i)%5];

    cout << ways << endl;

    return 0;
}
