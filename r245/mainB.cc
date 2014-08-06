#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

vector<int> c(100);
int n;

// recursively destroy sets of 3 or more, ignoring [a,b] and return length
int destroy(int a, int b) {
    int l = a-1, r = b+1;

    if(l < 0 || r >= n || c[l] != c[r])
        return b - a + 1;

    for(; l && c[l-1] == c[l]; --l) {} // expand left
    for(; r+1 < n && c[r+1] == c[r]; ++r) {} // expand right

    if((r-l) - (b-a) < 3)
        return b - a + 1;

    return destroy(l, r);
}

int main() {
    int k, x, best = 0;

    cin >> n >> k >> x;
    FOR(i,0,n)
        cin >> c[i];

    FOR(i,0,n-1) {
        if(x != c[i] || c[i] != c[i+1]) continue; // not a candidate
        best = max(best, destroy(i, i+1));
    }

    cout << best;

    return 0;
}
