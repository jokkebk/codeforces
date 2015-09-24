#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))

int main() {
    int n, d, m, s;
    map<int,LL> f;

    S(n);
    S(d);

    REP(n) {
        S(m);
        S(s);
        f[m] += s;
    }

    LL fact=0, best=0;

    cout << endl;
    for(auto it = f.begin(), end = f.begin(); it != f.end(); it++) {
        int poor = (*it).first;

        for(; end != f.end() && (*end).first < poor+d ; end++)
            fact += (*end).second;

        best = MAX(best, fact);
        fact -= (*it).second;
    }

    cout << best;

    return 0;
}
