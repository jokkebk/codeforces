#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef long long LL;

int main() {
    int n, m, a, b;

    cin >> n >> m >> a >> b;

    if(a*m <= b) // no use for multiride
        cout << n*a;
    else
        cout << (n/m) * b + min((n % m) * a, b);

    return 0;
}
