#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)
#define FORIT(it,a) for(auto it=a.begin(); it!=a.end(); ++it)

typedef long long LL;

int main() {
    int n, val, len, start, lastLen, lastStart = 0, best = 0;
    vector<int> a(100001);

    cin >> n;

    if(n <= 0) { // this is not according to spec, but check it
        cout << 0;
        return 0;
    }

    FORE(i,1,n)
        cin >> a[i];

    len = start = 1;

    FORE(i,2,n) {
        if(a[i-1] < a[i]) { // increasing
            //cout << i << " increasing" << endl;
            len++;
            //cout << "Len now " << len << endl;
            continue;
        }

        // sequence ended
        best = max(best, len);
        if(len < n)
            best = max(best, len+1); // possible to change a number before or after

        if(len > 1 && lastStart && a[start + 1] - 1 > a[lastStart + lastLen - 1])
            best = max(best, len + lastLen); // combine

        if(len > 1 && lastStart && lastLen > 1 &&
                a[start] - 1 > a[lastStart + lastLen - 2])
            best = max(best, len + lastLen); // combine

        // store last longest sequence
        lastStart = start;
        lastLen = len;

        // restart normal sequence
        start = i;
        len = 1;
    }

    // sequence ended
    best = max(best, len);
    if(len < n)
        best = max(best, len+1); // possible to change a number before

    if(len > 1 && lastStart && a[start + 1] - 1 > a[lastStart + lastLen - 1])
        best = max(best, len + lastLen); // combine

    if(len > 1 && lastStart && lastLen > 1 &&
            a[start] - 1 > a[lastStart + lastLen - 2])
            best = max(best, len + lastLen); // combine

    cout << best;

    return 0;
}
