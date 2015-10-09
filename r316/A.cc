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

int main() {
    int n, m, v;
    map<int,int> cand;

    S(n); S(m);

    FOR(j,0,m) {
        priority_queue<pair<int,int>> city;
        FOR(i,0,n) {
            S(v);
            city.push(make_pair(v,-i));
        }
        pair<int,int> p = city.top();
        //cout << "In city " << j << " candidate " << -p.second << endl;
        cand[-p.second]++;
    }

    int best=0, besti=0;
    for(auto it : cand) {
        //cout << "Candidate " << it.first+1 << " got " << it.second << " votes" << endl;
        if(it.second > best) {
            best = it.second;
            besti = it.first;
        }
    }

    cout << besti+1;

    return 0;
}
