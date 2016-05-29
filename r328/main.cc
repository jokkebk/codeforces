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

vector<vector<int>> to(123456+1);
vector<bool> a(123456+1);
vector<int> from(123456+1); // serves as visited[n] as well

struct state {
    int v, prev, child;
    state(int v, int prev) : v(v), prev(prev), child(0) {}
};

int DFS(int start) {
    vector<state> s = {state(start,0)};
    int bestd = 0, bestv = 0;
    while(s.size()) {
        state & st = s.back();
        if(a[st.v] && s.size() > bestd) bestd = s.size(), bestv = st.v;
        if(st.child >= to[st.v].size()) { s.pop_back(); continue; }
        int w = to[st.v][st.child++];
        if(w == st.prev) continue;
        from[w] = st.v; // store where we came from
        s.push_back(state(w, st.v)); // get down, corrupt st
    }
    return bestv;
}

int main() {
    int n, m, u, v;

    cin >> n >> m;

    REP(n-1) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    REP(m) {
        cin >> u;
        a[u] = true;
    }

    if(m == 1) {
        cout << 0 << endl << 1 << endl;
        return 0;
    }

    int first = DFS(1), last = DFS(first);

    //FORE(i,1,n) cout << "We got to " << i << " from " << from[i] << endl;

    // Position longest path to last in children
    int next = last, len=1;
    do {
        int cur = from[next];
        int pos = find(to[cur].begin(), to[cur].end(), next) - to[cur].begin();
        if(pos+1 < to[cur].size())
            SWAP(to[cur][to[cur].size()-1], to[cur][pos]);
        next = cur;
        len++;
    } while(next != first);

    if(n > 100000) cout << first << " to " << last << " there were " << len << " items" << endl;
    vector<state> s = {state(last,0)};
    int printed = 0;
    vector<int> ans;

    while(s.size()) {
        state & st = s.back();

        //for(state s2 : s) cout << s2.v << ":" << s2.child << "/" << to[s2.v].size() << " "; cout << endl;

        if(a[st.v]) {
            while(s.size() > printed)
                ans.push_back(s[printed++].v);
        }

        if(st.child >= to[st.v].size()) { // end of this node
            s.pop_back();
            if(s.size() < printed)
                ans.push_back(s[--printed-1].v);
            continue;
        }

        int w = to[st.v][st.child++];

        if(w == st.prev) continue;

        s.push_back(state(w, st.v)); // get down

        if(w == first) break;
    }

    while(s.size() > printed)
        ans.push_back(s[printed++].v);

    cout << MIN(first, last) << endl;
    cout << ans.size() - 1 << endl;

    return 0;
}
