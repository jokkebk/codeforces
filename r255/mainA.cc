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
    bool used[301], collision = false;
    int n, p, v;

    cin >> p >> n;

    FOR(i,0,p)
        used[i] = false;

    FORE(i,1,n) {
        cin >> v;
        if(used[v % p]) {
            if(!collision) cout << i;
            collision = true;
        }
        used[v % p] = true;
    }

    if(!collision)
        cout << -1;

    return 0;
}
