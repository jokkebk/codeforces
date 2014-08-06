#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

void draw(int w, int n) {
    FOR(i,0,(n-w)/2) cout << "*";
    FOR(i,0,w) cout << "D";
    FOR(i,0,(n-w)/2) cout << "*";
    cout << endl;
}

int main() {
    int n;

    cin >> n;

    FOR(i,0,n/2) draw(i*2+1,n);
    FORE(i,0,n/2) draw(n-i*2,n);

    return 0;
}
