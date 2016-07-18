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
    int n, min=0, max=0;
    cin >> n;

    switch(n%7) {
        case 1: max = 1; break;
        case 2: case 3: case 4: case 5: max = 2; break;
        case 6: min = 1; max = 2; break;
        default: break;
    }

    cout << n/7*2+min << " " << n/7*2+max << endl;

    return 0;
}
