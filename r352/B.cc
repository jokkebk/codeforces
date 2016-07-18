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

#define Inf 1000000007

#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    set<char> ch;

    cin >> n;

    if(n>'z'-'a'+1) {
        cout << -1 << endl;
        return 0;
    }

    cin >> s;

    for(char c : s) ch.insert(c);

    cout << n - ch.size() << endl;

    return 0;
}
