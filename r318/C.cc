#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define SWAP(a,b) {a^=b; b^=a; a^=b;}

int main() {
    int n, p=-1, a;

    S(n);

    REP(n) {
        S(a);
        while(!(a&1)) a/=2;
        while(!(a%3)) a/=3;
        if(p!=-1 && p!=a) {
            cout << "NO";
            return 0;
        }
        p=a;
    }

    cout << "YES";

    return 0;
}
