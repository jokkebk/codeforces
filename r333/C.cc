#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define ABS(a) (((a)<0) ? -(a) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, u, v;

    cin >> n >> m;

    set<pair<int,int>> rr;

    REP(m) {
        cin >> u >> v; u--, v--;
        rr.insert(make_pair(MIN(u,v), MAX(u,v)));
    }

    int skip=rr.count(make_pair(0,n-1));

    //if(skip) cout << "Roads" << endl;
    //else cout << "Railroads" << endl;

    vector<vector<int>> to(n);
    FOR(i,0,n) {
        FOR(j,i+1,n) {
            if(rr.count(make_pair(i,j))==skip) continue;
            //cout << "From " << i << " to " << j << endl;
            to[i].push_back(j);
            to[j].push_back(i);
        }
    }

    deque<pair<int,int>> q;
    set<int> seen;
    q.push_back(make_pair(0,0));

    while(q.size()) {
        int i = q.front().fi, len = q.front().se; q.pop_front();
        if(seen.count(i)) continue; // were here earlier
        seen.insert(i); // remember
        //cout << "Now at " << i << ", len " << len << endl;
        if(i == n-1) {
            cout << len << endl;
            return 0;
        }
        for(int t : to[i]) {
            //cout << "Go to " << t << endl;
            q.push_back(make_pair(t, len+1));
        }
    }

    cout << -1 << endl;
    return 0;
}
