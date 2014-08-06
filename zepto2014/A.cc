#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

vector<int> t, h, m, eaten;
int n, x;

int eat(int x, int inv) {
    FOR(i,0,n) eaten[i] = false;

    FOR(i,inv,2002) { // brute force eater
        int M = 0, J = -1;

        FOR(j,0,n)
            if(!eaten[j] && h[j] <= x && m[j] > M && ((i&1) ? t[j] : !t[j]))
                M = m[j], J = j;

        if(!M) return i - inv; // no more candy

        x += m[J];
        eaten[J] = true;
    }

    return 0;
}

int main() {

    cin >> n >> x;

    t.resize(n);
    h.resize(n);
    m.resize(n);
    eaten.resize(n);

    FOR(i,0,n) cin >> t[i] >> h[i] >> m[i];

    cout << max(eat(x, 0), eat(x, 1));

    return 0;
}
