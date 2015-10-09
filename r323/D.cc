#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))

int main() {
    int n, T;
    LL longest = 0;

    S(n); S(T);

    vector<int> a(n*MIN(T,n)), t(n*MIN(T,n));

    FOR(i,0,n) S(a[i]);
    FOR(i,n,n*MIN(T,n)) a[i] = a[i-n];

    // In a non-decreasing sequence, there are at most n-1 increases, so
    // you can only "jump back" and increase current number in n*n array,
    // rest will be repeating a single digit (and that we'll seek later)
    FOR(i,0,n*MIN(T,n)) {
        FOR(j,0,i) {
            if(a[j] <= a[i] && t[j] >= t[i]) {
                t[i] = t[j]+1;
                if(longest < t[i]) longest = t[i];
            }
        }
    }

    // Optimal increases have been found, choose most frequent num for rest
    if(T > n) {
        map<int,int> cnt;

        FOR(i,0,n) cnt[a[i]]++;

        int best=0, besti=0;
        for(auto v : cnt) {
            if(v.second > best) {
                best = v.second;
                besti = v.first;
            }
        }
        //cout << best << " x " << besti << endl;
        longest += (LL)(T-n) * best;
    }

    cout << longest+1 << endl;

    return 0;
}
