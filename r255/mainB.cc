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
    char s[1001];
    int w[256], best = 0;
    int k, i, val = 0;

    cin >> s >> k;

    FORE(c, 'a', 'z') {
        cin >> w[c];
        best = max(best, w[c]);
    }

    for(i=0; s[i]; ++i)
        val += (i+1) * w[s[i]];

    for(int j=i; j<i+k; j++)
        val += (j+1) * best;

    cout << val;

    return 0;
}
