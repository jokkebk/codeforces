#include <iostream>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    int n, k, d;
    vector<long long> d0(101), d1(101);

    cin >> n >> k >> d;

    d0[0] = 1;

    FOR(i, 0, n) {
        FOR(j, 1, min(d, n-i+1)) {
            d0[i+j] = (d0[i+j] + d0[i]) % 1000000007;
            d1[i+j] = (d1[i+j] + d1[i]) % 1000000007;
        }

        FORE(j, d, min(k, n-i))
            d1[i+j] = (d1[i+j] + d0[i] + d1[i]) % 1000000007;
    }

    cout << d1[n] << endl;

    return 0;
}
