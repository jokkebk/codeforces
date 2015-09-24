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

int n, m, a, x, y, N=0;
map<int,vector<int>> t;
vector<bool> cats;

void recurse(int prev, int v, int c) {
    c = cats[v] ? c+1 : 0;
    if(c > m) return; // too many cats
    if(v && t[v].size() == 1) N++; // OK leaf
    for(int v2 : t[v])
        if(v2 != prev)
            recurse(v, v2, c);
}

int main() {

    S(n);
    S(m);

    REP(n) {
        S(a);
        cats.push_back(a);
    }

    REP(n-1) {
        S(x); S(y);
        t[x-1].push_back(y-1);
        t[y-1].push_back(x-1);
    }

    recurse(-1, 0, 0);
    cout << N;

    return 0;
}
