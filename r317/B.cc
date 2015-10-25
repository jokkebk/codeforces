#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int main() {
    int n, s;

    cin >> n >> s;

    map<int,int> buy, sell;

    REP(n) {
        char d;
        int p, q;
        cin >> d >> p >> q;
        if(d=='B')
            buy[-p] += q;
        else
            sell[p] += q;
    }

    vector<pair<int,int>> sev;
    int i=0;
    for(auto pq : sell) {
        sev.push_back(pq);
    }

    for(int i = MIN(sev.size(), s)-1; i>=0; i--)
        cout << "S " << sev[i].first << " " << sev[i].second << endl;

    i=0;
    for(auto pq : buy) {
        cout << "B " << -pq.first << " " << pq.second << endl;
        if(++i >= s) break;
    }

    return 0;
}
