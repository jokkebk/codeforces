#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    int n, v, police = 0, crimes = 0;

    cin >> n;

    REP(n) {
        cin >> v;
        if(v >= 0)
            police += v;
        else if(police)
            police -= 1;
        else
            crimes += 1;
    }

    cout << crimes;

    return 0;
}
