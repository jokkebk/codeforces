#include <cstdio>
#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))

int main() {
    int n, x, N=0;

    S(n); S(x);

    for(int i = 1; i <= n && i*i <= x; i++) {
        if(x%i) continue; // i does not divide x
        if(i*i == x) N++;
        else if(x/i <= n) N += 2;
    }

    cout << N;

    return 0;
}
