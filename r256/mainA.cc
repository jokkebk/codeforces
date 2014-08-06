#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    int n, cups = 0, medals = 0;

    REP(3) {
        cin >> n;
        cups += n;
    }

    REP(3) {
        cin >> n;
        medals += n;
    }

    cin >> n; // shelves

    n -= (cups % 5 == 0) ? cups/5 : cups/5 + 1;
    n -= (medals % 10 == 0) ? medals/10 : medals/10 + 1;

    if(n >= 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
