#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))

char s[500005];

vector<int> p, h, ccnt, start;
vector<map<int,int>> mask;

int main() {
    int n, m, hmax=0;

    S(n); S(m);
    p.resize(n);
    h.resize(n);
    ccnt.resize(n);
    start.resize(n);

    FOR(i,1,n) {
        S(p[i]); p[i]--;
        h[i] = h[p[i]] + 1;
        hmax = MAX(hmax, h[i]);
    }

    REP(2) fgets(s, sizeof(s)-2, stdin);

    mask.resize(hmax+1); // simplify indexing

    // Count children
    for(int i=n-1; i; i--) ccnt[p[i]] += ccnt[i] + 1;

    // Renumber nodes so subtree starts from start[v] plus ccnt[v] children
    start[0] = ccnt[0]; // Enough for all children
    FOR(i,1,n) {
        start[i] = start[p[i]]; // Begin range from here
        mask[h[i]][start[i]] = 1 << (s[i]-'a'); // stays within range
        start[p[i]] -= ccnt[i] + 1; // Reserve numbers for this and children
    }

    FOR(i,0,n) {
        cout << "Node " << i+1 << ": " << start[i] << " .. " << start[i]+ccnt[i] << endl;
    }

    FORE(i,1,hmax) {
        int last = 0;
        cout << "Height " << i << endl;
        for(auto it : mask[i]) {
            it.second ^= last;
            cout << "  " << it.first << " = " << it.second << endl;
            last = it.second;
        }
    }

    return 0;

    REP(m) {
        int v1, h1;
        S(v1); v1--;
        S(h1); h1--;
    }

    return 0;
}
