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
    int n, m, a, ok1[1000], ok2[1000], *ok=ok1, *lok;

    S(n); S(m);

    FOR(i,0,m) ok[i] = 0;

    REP(n) {
        S(a);
        lok = ok, ok = (ok==ok1 ? ok2 : ok1); // alternate
        FOR(i,0,m) ok[i] = lok[i]; // previous mods ok
        ok[a%m] = 1; // pure add ok
        FOR(i,0,m) if(lok[i]) ok[(i+a)%m] = 1;

        if(ok[0]) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
