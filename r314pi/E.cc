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

void dijkstra(vector<LL> & d, vector<vector<pair<int,int>>> & tl, int s) {
    vector<bool> done(d.size());
    priority_queue<pair<LL,int>> q;

    q.push(make_pair(0,s));
    while(q.size()) {
        LL ds = -q.top().first, c = q.top().second; q.pop();
        if(done[c]) continue;
        done[c] = true, d[c] = ds;
        for(auto& p : tl[c]) q.push(make_pair(-(ds + p.second), p.first));
    }
}

int main() {
    int n, m, s, t;

    cin >> n >> m >> s >> t; s--, t--;

    vector<vector<pair<int,int>>> to(n), from(n); // city,len
    vector<tuple<int,int,int>> r; // road
    vector<LL> ds(n,-1), dt(n,-1); // distance from s, t

    FOR(i,0,m) {
        int a, b, l;
        cin >> a >> b >> l; a--, b--;
        r.push_back(make_tuple(a,b,l));
        to[a].push_back(make_pair(b, l));
        from[b].push_back(make_pair(a, l));
    }

    dijkstra(ds, to, s);
    dijkstra(dt, from, t);

    map<LL,LL> cnt;

    FOR(i,0,m) {
        LL a=get<0>(r[i]), b=get<1>(r[i]), l=get<2>(r[i]);
        if(ds[a] == -1 || dt[b] == -1) continue; // do not count duds
        if(ds[a] + l + dt[b] != ds[t]) continue; // not on critical path
        cnt[ds[a]]++;
        cnt[ds[a]+l]--;
    }

    LL cum=0;

    for(auto & p : cnt) {
        cum += p.second;
        p.second = cum;
    }

    FOR(i,0,m) {
        LL a=get<0>(r[i]), b=get<1>(r[i]), l=get<2>(r[i]);
        LL diff = ds[a] + l + dt[b] - ds[t];

        if(ds[a] == -1 || dt[b] == -1) {
            cout << "NO" << endl;
        } else if(diff) {
            if(l > diff+1) cout << "CAN " << diff+1 << endl;
            else cout << "NO" << endl;
        } else {
            if(cnt[ds[a]] == 1)
                cout << "YES" << endl;
            else if(l > 1)
                cout << "CAN 1" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
