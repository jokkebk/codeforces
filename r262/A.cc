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
    int n, m, i;

    cin >> n >> m;

    for(i = 1; n > 0; ++i, --n) {
        if(i % m == 0)
            n++;
    }

    cout << i-1;

    return 0;
}
