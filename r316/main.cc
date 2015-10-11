#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

vector<int> p, height, ccnt, start;
vector<map<int,int>> mask;

inline bool pali(int v, int h, map<int,int> & m) {
    int from=start[v], to=from+ccnt[v];
    int res = m.lower_bound(from)->second ^ m.upper_bound(to)->second;
    return !(res && (res&(res-1)));
}

// Faster way to solve would be DFS to number the node, and we can
// push depth-specific node numbers into sorted arrays along the way,
// eliminating the need to use a map or sort for mask[h]
int main() {
    int n, m, v, h, hmax=0;

    S(n); S(m);

    p.resize(n);
    height.resize(n);
    ccnt.resize(n);
    start.resize(n);

    FOR(i,1,n) {
        S(p[i]); p[i]--;
        height[i] = height[p[i]] + 1;
        hmax = MAX(hmax, height[i]);
    }

    REP(2) fgets(s, sizeof(s)-2, stdin);

    mask.resize(hmax+1); // simplify indexing

    // Count children
    for(int i=n-1; i; i--) ccnt[p[i]] += ccnt[i] + 1;

    // Renumber nodes so subtree starts from start[v] plus ccnt[v] children
    start[0] = ccnt[0]; // Enough for all children
    FOR(i,1,n) {
        start[i] = start[p[i]]; // Begin range from here
        mask[height[i]][start[i]] = 1 << (s[i]-'a'); // stays within range
        start[p[i]] -= ccnt[i] + 1; // Reserve numbers for this and children
    }

    FORE(i,1,hmax) {
        int last = 0;
        for(auto it = mask[i].rbegin(); it != mask[i].rend(); it++) {
            it->second ^= last;
            last = it->second;
        }
        mask[i][999999] = 0;
    }

    FOR(i,0,m) {
        S(v); v--;
        S(h); h--;

        if(h <= height[v] || h > hmax)
            cout << "Yes" << endl;
        else
            cout << (pali(v, h, mask[h]) ? "Yes":"No") << endl;
    }

    return 0;
}
