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
    int n, m, a, b;
    map<int,vector<int>> c;
    vector<set<int>> k;
    vector<int> r, s;

    S(n); S(m);
    k.resize(n+1);
    r.resize(n+1);

    REP(m) {
        S(a); S(b);
        if(a>b) SWAP(a,b);
        c[a].push_back(b);
        k[b].insert(a);
        r[a]++, r[b]++;
    }

    for(auto& it : c)
        for(int x : (it.second))
            for(int y : c[x])
                if(k[y].count(it.first))
                    s.push_back(r[it.first]+r[x]+r[y]-6);

    cout << (s.size() ? *min_element(s.begin(), s.end()) : -1);

    return 0;
}
