#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

struct XorTree {
    int diff; // between current value and goal
    set<int> nodes; // initially also contains root
};

vector<XorTree> v;

void doXor(int k, int parent, int xorThis, int xorNext, vector<int> & ops) {
    if(v[k].diff ^ xorThis) {
        ops.push_back(k);
        xorThis ^= 1;
    }

    for(int i : v[k].nodes)
        if(i != parent)
            doXor(i, k, xorNext, xorThis, ops);
}

int main() {
    vector<int> ops;
    int n, i, j, goal;

    cin >> n;

    v.resize(n);
    ops.reserve(n);

    REP(n-1) {
        cin >> i >> j;
        v[i-1].nodes.insert(j-1);
        v[j-1].nodes.insert(i-1);
    }

    FOR(k,0,n)
        cin >> v[k].diff;

    FOR(k,0,n) {
        cin >> goal;
        v[k].diff ^= goal;
    }

    doXor(0, 0, 0, 0, ops);

    cout << ops.size() << endl;
    for(int k : ops)
        cout << k+1 << endl;

    return 0;
}
