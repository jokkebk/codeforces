#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a^=b; b^=a; a^=b;}

int main() {
    int n, v;
    vector<int> h;

    S(n);
    REP(n) S(v), h.push_back(v);

    h[0] = h.back() = 1;
    for(int i=1; i<h.size(); i++) h[i] = MIN(h[i-1]+1, h[i]);
    for(int i=h.size()-2; i>=0; i--) h[i] = MIN(h[i+1]+1, h[i]);

    cout << *max_element(h.begin(), h.end()) << endl;

    return 0;
}
