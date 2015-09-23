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

#define NEXT(h, x, y) (((x)*(h) + (y)) % m)

LL getFirst(LL h, LL a, LL x, LL y) {
    //cout << "From " << h << " to " << a << " with " << x << ", " << y << endl;

    FORE(i,1,1000009) {
        h = NEXT(h, x, y);
        //cout << h << endl;
        if(h == a) return i;
    }

    return -1;
}

// Extended Euclid's algorithm
void egcd(LL *arr, LL a, LL b) {
    LL s = 0, t = 1, r = b, olds = 1, oldt = 0, oldr = a, tt;

    while(r != 0) {
        LL q = oldr / r;
        
        tt = r;
        r = oldr - q * r;
        oldr = tt;
        
        tt = s;
        s = olds - q * s;
        olds = tt;
        
        tt = t;
        t = oldt - q * t;
        oldt = tt;
    }

    arr[0] = olds;
    arr[1] = oldt;
    arr[2] = oldr;
    arr[3] = t;
    arr[4] = s;
}

int main() {
    LL x1, x2, y1, y2, a1, a2, h1, h2;
    LL t1, t1a, t2, t2a;
    LL data[5];

    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;

    t1 = getFirst(h1, a1, x1, y1);
    t1a = getFirst(a1, a1, x1, y1);
    t2 = getFirst(h2, a2, x2, y2);
    t2a = getFirst(a2, a2, x2, y2);
    //cout << t1 << " and every " << t1a << endl;
    //cout << t2 << " and every " << t2a << endl;

    if(t1 == -1 || t2 == -1) {
        cout << -1 << endl;
    //} else if(t1 == t2) {
        //cout << t1 << endl;
    } else {
        int i, c = t1 - t2, r;

        //cin >> t1a >> t2a >> c;
        egcd(data, t1a, -t2a);
        //cout << "B?zout coefficients:" << data[0] << ", " << data[1] << endl;
        //cout << "greatest common divisor:" << data[2] << endl;
        //cout << "quotients by the gcd:" << data[3] << ", " << data[4] << endl;

        if(c % data[2]) { // gcd does not divide target
            cout << -1 << endl;
        } else { // there is a solution
            int h = c/data[2]; // c = d*h

            x1 = data[0]*h;
            x2 = data[1]*h;

            //cout << t1a << "*" << x1 << " + " << t2a << "*" << x2 << " = " << c;

            int step = t2a / data[2]; // x = x1 + k*step
            x1 %= step;
            if(x1 < 0) x1 += step;

            cout << (t1+t1a*x1) << endl;
        }
    }

    return 0;
}
