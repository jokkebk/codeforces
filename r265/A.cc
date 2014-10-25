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
    char s[103];

    cin >> n >> s;

    FOR(i,0,n) {
        if(s[i] == '0') {
            cout << i+1;
            return 0;
        }
    }

    cout << n;

    return 0;
}
