#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))

int main() {
    int n, p[1001];
    vector<int> q;

    S(n);

    FORE(i,1,n) p[i] = 1;
    FORE(i,2,n) { // Prime sieve
        if(!p[i]) continue;
        for(int j=i+i; j<=n; j+=i) p[j] = 0;
    }

    FORE(i,2,n)
        if(p[i])
            for(int m=i; m<=n; m*=i) q.push_back(m);

    cout << q.size() << endl;
    for(int v : q) cout << v << " ";
    return 0;
}
