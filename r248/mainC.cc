#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)
#define FORIT(it,a) for(auto it=a.begin(); it!=a.end(); ++it)

typedef long long LL;

LL reduction(int p, const map<int,int> & sm, const map<int,int> & lg, int d) {
    LL r = 0;

    if(d > 0) { // more smaller numbers
        for(auto it = sm.rbegin(); d > 0 && it != sm.rend(); ++it) {
            r += (LL)d * (LL)(p - it->first);
            p = it->first;
            d -= it->second * 2;
        }
    } else if(d < 0) { // more large numbers
        for(auto it = lg.begin(); d < 0 && it != lg.end(); ++it) {
            r += (LL)d * (LL)(p - it->first);
            p = it->first;
            d += it->second * 2;
        }
    }

    return r;
}

int main() {
    vector<map<int,int>> sm(100001), lg(100001);
    vector<int> diff(100001);
    int n, m, a, b, val, prev = 0;
    LL turns = 0, best = 0;

    cin >> n >> m;

    REP(m) {
        cin >> val;

        if(prev && prev != val) {
            a = min(prev, val);
            b = max(prev, val);

            sm[b][a]++;
            lg[a][b]++;
            diff[a]--;
            diff[b]++;

            turns += b - a;
        }

        prev = val;
    }

    FORE(i,1,n)
        best = max(best, reduction(i, sm[i], lg[i], diff[i]));

    cout << turns - best << endl;

    return 0;
}
