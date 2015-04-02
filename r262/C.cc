#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

int n, m, w;
vector<int> a;

bool possible(int target) {
    vector<int> ring(w);
    int days = m, level = 0, need;

    for(int i=0; i<n && days >= 0; ++i) {
        level -= ring[i%w];
        need = max(0, target - (a[i] + level));
        level += need, days -= need;
        ring[i%w] = need;
    }

    return (days >= 0);
}

int main() {
    cin >> n >> m >> w;
    a.resize(n);
    FOR(i,0,n) cin >> a[i];

    int lo = *min_element(a.begin(), a.end()), hi = lo+m, level = hi;

    do {
        if(possible(level)) lo = level; else hi = level;
        level = (hi+lo) / 2; // next iteration
    } while(level > lo);

    cout << lo; // low always possible

    return 0;
}
