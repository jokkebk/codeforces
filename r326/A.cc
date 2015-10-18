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
    int n;

    S(n);

    vector<int> a(n), p(n);
    vector<pair<int,int>> q;

    FOR(i,0,n) {
        S(a[i]); S(p[i]);
        q.push_back(make_pair(p[i], i));
    }

    sort(q.begin(), q.end());

    int end = n;

    for(auto t : q) {
        //cout << "Filling from " << t.second << " to " << end << " with " << t.first << endl;
        FOR(i, t.second+1, end) p[i] = t.first;
        end = MIN(end, t.second);
    }

    int s = 0;
    FOR(i,0,n) s += a[i] * p[i];
    cout << s << endl;

    return 0;
}
