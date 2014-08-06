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
    int n, m, k;
    int need[100], left;

    cin >> n >> m;

    FOR(i,0,n)
        cin >> need[i];

    left = n;

    for(k=0; left; k = (k+1) % n) {
        //cout << "need[" << k << "] = " << need[k] << endl;
        //cout << left << " left" << endl;
        if(need[k] > 0) {
            need[k] -= m;
            if(need[k] <= 0)
                left--;
            if(!left) break; // cheat
        }
    }

    cout << k + 1;

    return 0;
}
