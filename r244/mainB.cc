#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    int n, t, c, v, ways = 0, seq = 0;

    cin >> n >> t >> c;

    REP(n) {
        cin >> v;
        if(v > t) {
            if(seq >= c) ways += (seq - c) + 1;
            seq = 0;
        } else seq++;
    }

    if(seq >= c) ways += (seq - c) + 1;

    cout << ways;

    return 0;
}
