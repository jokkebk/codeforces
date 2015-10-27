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

int rev(int n) {
    int r=0;
    while(n) {
        r = r*10 + n%10;
        n /= 10;
    }
    return r;
}

int main() {
    int p, q, N=2000000;
    vector<int> pali(N), prime(N, 1);

    // Mark primes
    for(int i=2; i*i<N; i++)
        if(prime[i]) for(int j=i+i; j<N; j+=i) prime[j] = 0;
    prime[0] = prime[1] = 0;

    // Mark palindromes
    FOR(i,1,10) pali[i] = pali[i*11] = 1;
    FOR(i,10,100) pali[i*100+rev(i)] = pali[i*10+i/10] = 1;
    FOR(i,100,1000) pali[i*1000+rev(i)] = pali[i*100+rev(i)%100] = 1;
    FOR(i,1000,2000) pali[i*1000+rev(i)%1000] = 1;

    // Cumulative sum
    FOR(i,1,N) prime[i] += prime[i-1];
    FOR(i,1,N) pali[i] += pali[i-1];

    //cout << prime[N-1] << " primes, " << pali[N-1] << " palindromes" << endl;
    cin >> p >> q;
    for(int i=N-1; i; i--)
        if(q*prime[i] <= p*pali[i]) {
            cout << i << endl;
            return 0;
        }

    cout << "Palindromic tree is better than splay tree" << endl;

    return 0;
}
