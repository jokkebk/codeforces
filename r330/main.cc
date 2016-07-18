#include <cstdio>
#include <cstdlib>
#include <cmath>
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

const double PI = 3.141592653589793238463;
double r, v, s, f, l, T, A, B;

// How much ground covered with t
#define F(t) (v*t + A*sin(B*t))
#define dF(t) (v + A*B*cos(B*t))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;

    cin >> n >> r >> v;
    l = 2*PI*r; // length of single turn
    T = l/v; // time taken in single turn

    // Prepare constants to speed up Newton
    A = 2*r;
    B = PI/T;

    // The sensor is moving at speed v+v*cos(a+va) where va = v/(2*pi*r)
    // i.e. between 0 and 2v, fastest at top, the question is how large
    // time window around top is needed for last fractional lap
    REP(n) {
        cin >> s >> f;
        double full = floor((f-s)/l), last = fmod(f-s, l), t = T/2;
        REP(9) t -= (F(t)-last)/dF(t); // Newton's method
        cout << setprecision(10) << full*T+t << endl;
    }

    return 0;
}
