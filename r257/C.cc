#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

// minimum width of piece with k cuts along the edge
LL minW(LL n, LL k) {
    LL w = n / (k+1);
    return w;
}

int main() {
    LL n, m, k, minN, minM;

    cin >> n >> m >> k;

    if(n-1 + m-1 < k) {
        cout << -1;
        return 0;
    }

    // calculate smallest when most cuts along n
    if(n > k)
        minN = minW(n, k) * m;
    else
        minN = minW(m, k - (n-1));

    // calculate smallest when most cuts along m
    if(m > k)
        minM = minW(m, k) * n;
    else
        minM = minW(n, k - (m-1));

    //cout << minN << " vs. " << minM << endl;
    cout << max(minN, minM);

    return 0;
}
