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

int main() {
    int n, a, t, p=0, l=1;
    vector<int> pos, len, typ;

    cin >> n >> t; // read first in t

    FOR(i,1,n) { 
        cin >> a; // read rest here
        if(t != a) {
            if(l>1 || p==0) {
                pos.push_back(p);
                len.push_back(l);
                typ.push_back(t);
            }
            t = a; p = i; l = 1;
        } else l++;
    }
    pos.push_back(p);
    len.push_back(l);
    typ.push_back(t);
    
    int max=0;
    FOR(i,0,pos.size()-1) max = MAX(max, pos[i+1]-pos[i]-len[i]);
    cout << (max+1)/2 << endl;

    FOR(i,0,pos.size()-1) {
        FOR(j,0,len[i]) cout << typ[i] << " ";
        l = (pos[i+1]-pos[i]-len[i]);
        if(typ[i] != typ[i+1]) {
            FOR(j,0,l/2) cout << typ[i] << " ";
            FOR(j,0,l/2) cout << typ[i+1] << " ";
        } else {
            FOR(j,0,l) cout << typ[i] << " ";
        }
    }

    FOR(j,0,len.back()) cout << typ.back() << " ";
    cout << endl;

    return 0;
}
