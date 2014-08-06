#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    int n, first, last, val, start = 0;

    cin >> n >> last;

    first = last;
    FOR(i,1,n) {
        cin >> val;
        if(val < last) start = start ? -1 : n-i;
        last = val;
    }

    if(start > 0 && first < last)
        cout << -1;
    else
        cout << start;

    return 0;
}
