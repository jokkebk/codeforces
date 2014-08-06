#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)

typedef long long LL;

struct Node {
    int index = 0, lowlink = 0; // for Tarjan
    int cost;
    vector<int> n;
};

vector<Node> j;
vector<int> S;
vector<bool> inS;
LL minCost = 0;
int ways = 1, index = 1;

void strongconnect(int v) { // Tarjan's strongly connected components
    j[v].index = index;
    j[v].lowlink = index++;
    S.push_back(v);
    inS[v] = true;

    for(int w : j[v].n) {
        if(!j[w].index) {
            strongconnect(w);
            j[v].lowlink = min(j[v].lowlink, j[w].lowlink);
        } else if(inS[w])
            j[v].lowlink = min(j[v].lowlink, j[w].index);
    }

    if(j[v].lowlink != j[v].index) return; // not a root of connected set

    LL best = 1e10, n = 0, i;

    do {
        i = S.back(); S.pop_back(); inS[i] = false;

        if(j[i].cost < best)
            n = 1, best = j[i].cost;
        else if(j[i].cost == best)
            n++;
    } while(i != v);

    minCost += best;
    ways = (int)(((LL)ways * (LL)n) % (LL)(1e9+7));
}

int main() {
    int n, m, u, v;

    cin >> n;

    j.resize(n);
    inS.resize(n);

    FOR(i,0,n) cin >> j[i].cost;

    cin >> m;

    REP(m) {
        cin >> u >> v;
        j[u-1].n.push_back(v-1);
    }

    FOR(i,0,n)
        if(!j[i].index)
            strongconnect(i);

    cout << minCost << " " << ways << endl;

    return 0;
}
