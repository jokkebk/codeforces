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
    int n, t=0;

    S(n);

    vector<LL> v(n), d(n), p(n), a;

    FOR(i,0,n) {
        S(v[i]);
        S(d[i]);
        S(p[i]);
    }

    FOR(i,0,n) { // treat the children
        if(p[i] < 0) continue; // already gone
        t++;
        LL vol = v[i], add = 0;
        //cout << "Child " << i+1 << " treated, cries at volume " << vol << endl;
        a.push_back(i);
        FOR(j,i+1,n) {
            if(p[j] < 0) continue; // gone already
            p[j] -= vol + add;
            //cout << "  at " << j+1 << " volume is " << vol << "+" << add << " and confidence " << p[j] << endl;
            if(p[j] < 0) { // just broke
                add += d[j];
                //cout << "  HE BROKE!" << endl;
            }
            if(vol) vol--;
        }
    }

    cout << a.size() << endl;
    for(int i : a) cout << i+1 << " "; cout << endl;

    return 0;
}
