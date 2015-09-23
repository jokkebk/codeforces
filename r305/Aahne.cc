#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

LL m;

LL getFirst(LL h, LL a, LL x, LL y) {
    FORE(i,1,1000009) {
        h = (x*h+y) % m;
        if(h == a) return i;
    }

    return -1;
}

int main() {
    LL x1, x2, y1, y2, a1, a2, h1, h2;
    LL t1, t1a, t2, t2a;

    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;

    t1 = getFirst(h1, a1, x1, y1);
    t1a = getFirst(a1, a1, x1, y1);
    t2 = getFirst(h2, a2, x2, y2);
    t2a = getFirst(a2, a2, x2, y2);

    if(t1 == -1 || t2 == -1) {
        cout << -1 << endl;
    } else if(t1 == t2) {
        cout << t1 << endl;
    } else {
        int i;

        FOR(i, 0, 2000010) {
            if(t1 < t2) t1 += t1a;
            else t2 += t2a;

            if(t1 == t2) {
                cout << t1 << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }

    return 0;
}
