#include <iostream>
#include <cmath>
#include <map>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    int n, pop, x, y, k;
    map<int,int> cities;
    double r = 0;

    cin >> n >> pop;

    FOR(i,0,n) {
        cin >> x >> y >> k;
        cities[x*x + y*y] += k;
    }

    if(pop < 1e6) for(auto & x : cities) {
        pop += x.second;
        r = sqrt(x.first);
        if(pop >= 1e6) break;
    }

    cout.precision(10);
    cout << (pop < 1e6 ? -1 : r);

    return 0;
}
