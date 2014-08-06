#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    cout << "100000 300000 100000" << endl;

    FOR(i,0,300000) {
        int from = i % 100000 + 1;
        int to = (i+1) % 100000 + 1;
        cout << from << " " << to << " 1000000000" << endl;
    }

    FOR(i,0,100000) {
        int to = i % 100000 + 1;
        cout << to << " 1000000000" << endl;
    }

    return 0;
}
