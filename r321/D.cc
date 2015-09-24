#include <cstdio>
#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))

#define DP(bm, i) (((i)<<18)+(bm))

int bits(int i) {
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

LL dp[18][1<<18]; // adding bit i to bits in mask j

int main() {
    int n, m, k, x, y, c;
    map<pair<int,int>,int> sat;
    map<int,vector<int>> masks;

    S(n); S(m); S(k);

    FOR(i,0,1<<n) // Inefficient but so what
        masks[bits(i)].push_back(i);

    FOR(i,0,n) S(dp[i][0]);

    REP(k) {
        S(x); S(y); S(c);
        sat[make_pair(x-1, y-1)] = c;
    }

    FOR(bits,1,m) {
        for(int ma : masks[bits]) {
            for(int j=0; j<n; j++) {
                if(ma & (1<<j)) continue; // not a new bit
                for(int b=0; b<n; b++) {
                    if(!(ma & (1<<b))) continue; // not part of mask
                    dp[j][ma] = MAX(dp[j][ma], dp[b][ma-(1<<b)] +
                            dp[j][0] + sat[make_pair(b, j)]);
                }
            }
        }
    }

    LL best = 0;
    for(int ma : masks[m]) {
        for(int j=0; j<n; j++) {
            if(!(ma & (1<<j))) continue;
            best = MAX(best, dp[j][ma-(1<<j)]);
        }
    }
    cout << best << endl;

    return 0;
}
