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

#define Inf 1000000007

int main() {
    int n, a, mini, maxi;

    cin >> n;

    FOR(i,0,n) {
        cin >> a;
        if(a==1) mini = i;
        if(a==n) maxi = i;
    }

    if(mini > maxi) swap(mini, maxi);

    cout << max(maxi, n-1-mini);

    return 0;
}
