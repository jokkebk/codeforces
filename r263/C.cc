#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef long long LL;

int main() {
    int n;
    LL sum = 0, sub = 0;
    vector<int> a;

    cin >> n;
    a.resize(n);
    FOR(i,0,n) {
        cin >> a[i];
        sub += a[i];
    }

    sort(a.begin(), a.end());

    sum += sub; // initial

    FOR(i,0,n-1) {
        //cout << "add " << sub << " to " << sum << endl;
        sum += sub;
        sub -= a[i];
    }

    cout << sum;

    return 0;
}
