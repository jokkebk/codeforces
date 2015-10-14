#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))

int main() {
    int n, k, r=0;
    set<pair<int,int>> pq;

    S(n); S(k);

    vector<int> a(n);

    FOR(i,0,n) {
        S(a[i]);
        r += a[i]/10;
        if(a[i] < 100)
            pq.insert({10-a[i]%10, i});
    }

    while(k && r<10*n) {
        pair<int,int> p = *pq.begin(); pq.erase(pq.begin());
        int left = p.first, i = p.second;

        if(k < left) break; // leftovers won't matter

        a[i] += left;
        k -= left;
        r++;
        if(a[i] < 100)
            pq.insert({10, i});
    }

    cout << r << endl;

    return 0;
}
