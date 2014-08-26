#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

bool inc(int *b, int k, int d) {
    if(!d) return false;
    if(*b == k) {
        *b = 1;
        return inc(b+1, k, d-1);
    } else b[0]++;
    return true;
}

int main() {
    int n, k, d, bus[1000];
    vector< vector<int> > plan;

    cin >> n >> k >> d;

    plan.resize(n);

    FOR(i,0,d) bus[i] = 1;

    FOR(j,0,n) {
        FOR(i,0,d) plan[j].push_back(bus[i]);
        //FOR(i,0,d) cout << bus[i] << " ";
        //cout << endl;
        if(!inc(bus, k, d) && j < n-1) {
            cout << -1;
            return 0;
        }
    }

    FOR(i,0,d) {
        FOR(j,0,n) cout << plan[j][i] << " ";
        cout << endl;
    }

    return 0;
}
