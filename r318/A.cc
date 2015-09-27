#include <cstdio>
#include <iostream>
#include <algorithm>
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
    int n, v, b=0, c=0;

    S(n);
    S(v); // Votes for Limak

    vector<int> a(n-1);

    FOR(i, 0, n-1) S(a[i]);
    sort(a.rbegin(), a.rend());

    while(1) {
        while(c+1 < a.size() && a[c+1] == a[c]) c++; // consolidate
        if(v+b+c+1 >= a[c]) break; // within striking distance
        b += c+1; // bribe candidate voters
        a[c]--; // tally the opponent votes
    }

    // We now have c+1 bears with a[c] votes, and v votes ourself
    if(v > a[c])
        cout << 0; // trivial
    else if(a[c]-(v+b) < c+1) // less votes needed than candidates
        cout << (a[c]-v+1);
    else // all candidates need a vote taken, a[c]-v == c+1
        cout << (b+c+1); // equals b+a[c]-v

    return 0;
}
