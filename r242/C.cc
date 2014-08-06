#include <iostream>
#include <iomanip>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int x[1000001];

int main() {
    int n, p, Q = 0;

    cin >> n;

    x[0] = 0;
    FORE(i,1,n) {
        x[i] = i ^ x[i-1];
        cin >> p;
        Q ^= p;
    }

    FORE(i,2,n) { // calculate columns
        if(n/i & 1) Q ^= x[i-1];
        Q ^= x[n%i];
    }

    cout << Q;

    return 0;
}
