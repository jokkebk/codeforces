#include <cstdio>
#include <iostream>
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
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    set<tuple<int,int,int>> s;
    set<int> done;

    cin >> n;

    vector<int> ans(2*n);

    FOR(i,1,2*n) {
        FOR(j,0,i) {
            cin >> a;
            s.insert(make_tuple(-a,j,i));
        }
    }

    for(auto t : s) {
        int i = get<1>(t), j = get<2>(t);
        a = get<0>(t);
        if(done.count(i) || done.count(j)) continue;
        ans[i] = j; ans[j] = i;
        done.insert(i);
        done.insert(j);
    }

    for(int t : ans) cout << t+1 << " "; cout << endl;

    return 0;
}
