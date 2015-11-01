#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define ABS(a) (((a)<0) ? -(a) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

#define MODMUL(a,b) ((((LL)(a)%Inf)*((LL)(b)%Inf))%Inf)
#define MODADD(a,b) (((LL)(a)+(LL)(b))%Inf)

LL modpow(LL a, LL k, LL p) { // a^k % p
    LL ret = 1;
    while(k) {
        if(k % 2) ret = (ret * a) % p;
        k /= 2;
        a = (a * a) % p;
    }
    return ret;
}

LL modinv(LL a, LL p) {
    return modpow(a, p-2, p);
}

LL Pmod(LL n, LL k, LL p) { // ways to choose k from p
    LL res = 1;
    for(LL i = n; i > n-k; --i) res = (res * i) % p;
    return res;
}
// The combination calculation is adapted, simplified, and precalculated from:
// http://stackoverflow.com/questions/10118137/fast-n-choose-k-mod-p-for-large-n
LL Cmod(LL n, LL k, LL p) {
    if(k > n) return 0;
    if(k == n || k == 0) return 1;
    return (Pmod(n, k, p) * modinv(Pmod(k, k, p), p)) % p;
}

int main() {
    int n;

    cin >> n;

    vector<vector<int>> S2(n, vector<int>(n));

    // Calculate 2-associated Stirling numbers of second kind
    FOR(i,2,n) {
        int s = 1;
        S2[i][1] = 1;
        FORE(k,2,i/2) {
            S2[i][k] = MODADD(MODMUL(k, S2[i-1][k]),
               MODMUL((i-1), S2[i-2][k-1]));
            s = MODADD(s, S2[i][k]);
        }
        S2[i][0] = s; // store cumulative sum
    }

    int ways = modpow(2,n,Inf)-1; // ways to have partial a=a for n eq classes
    FORE(i,1,n) ways = MODADD(ways,
            MODMUL(Cmod(n,i,Inf), MODMUL(modpow(2,i,Inf)-1, S2[n-i][0])));
    cout << ways << endl;

    return 0;
}
