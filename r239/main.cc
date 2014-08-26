#include <iostream>
#include <cmath>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    int a, b;

    cin >> a >> b;

    //   |,
    //  b| ,
    //   |  ,
    //   |___,
    //     a
    //
    // Rotate (0, b) as much as (x1, y2):
    // b' = b*i * (x1 + y1*i) / a = -b*y1 + b*x1*i

    FOR(x1,1,a) {
        int y1 = (int)round(sqrt(a*a - x1*x1)), x2 = -y1 * b/a, y2 = x1 * b/a;

        if(x1*x1 + y1*y1 != a*a || x2*x2 + y2*y2 != b*b || x1 == x2 || y1 == y2)
            continue;

        cout << "YES" << endl << "0 0" << endl;
        cout << x1 << " " << y1 << endl;
        cout << x2 << " " << y2 << endl;
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}
