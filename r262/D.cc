#include <iostream>
#include <cmath>

using namespace std;

#define REP(n) for(__typeof(a) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef unsigned long long ULL;

ULL l, r, k, h, sol[4], best[4], bestXor = 1e12+1, bestN = 0;

#define OK(x) ((x) >= (l) && (x) <= (r))

void brute(ULL num, ULL start, ULL end, ULL Xor) {
    if(num > k) return;

    if(num > 0 && bestXor > Xor) { // new optimum
        FOR(i,0,4) best[i] = sol[i];
        bestXor = Xor, bestN = num;
    }

    FORE(i,start,end) {
        sol[num] = i;
        brute(num+1, i+1, end, Xor ^ i);
    }
}

ULL hob(ULL num) {
    if (!num) return 0;
    ULL ret = 1;
    while(num >>= 1) ret <<= 1;
    return ret;
}

void doFirst(int n) {
    brute(0, l, min(r, l+n-1), 0); // should need n items max
    cout << bestXor << endl << bestN << endl;
    FOR(i,0,bestN) cout << best[i] << " ";
}

int main() {
    cin >> l >> r >> k, h = hob(r);

    if(k == 3) { // the tricky case
        if((r^h) >= l) {
            cout << 0 << endl << 3 << endl;
            cout << (r^h) << " " << r << " " << h << endl;
        } else if(OK(h-1) && OK(h+h/2) && OK(h+h/2-1)) {
            cout << 0 << endl << 3 << endl;
            cout << (h-1) << " " << (h+h/2) << " " << (h+h/2-1) << endl;
        } else doFirst(3); // No special case, best results with just two
    } else doFirst(5);

    return 0;
}
