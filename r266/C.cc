#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

int main() {
    long long target = 1 * 6;
    int minn = 1000000000000000002ll;
    cout << minn; return 0;

    /*
    LL n, total, ways = 0;
    vector<LL> a, sum, js;

    cin >> n;
    a.resize(n), sum.resize(n), js.resize(n);

    FOR(i,0,n) {
        int v;
        S(v);
        a[i] = v;
        sum[i] = (i ? sum[i-1] : 0) + a[i];
        //cout << sum[i] << " ";
    }
    //cout << endl;

    total = sum[n-1]; // brevity

    if(total % 3) {
        cout << 0;
        return 0;
    }

    // count how many ways to choose j from index onwards
    for(int i = n - 2; i >= 0; --i)
        js[i] = js[i+1] + ((sum[i] == total*2/3) ? 1 : 0);

    //FOR(i,0,n) cout << js[i] << " ";
    //cout << endl;

    FOR(i,1,n-1) {
        if(sum[i-1] != total/3) continue;

        //cout << "Potential i at " << i << endl;
        ways += js[i];
    }

    cout << ways;

    return 0;
    */
}
