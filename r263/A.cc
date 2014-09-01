#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef long long LL;

char b[100][103];
int n;

int count(int i, int j) {
    int c = 0;

    if(i && b[i-1][j] == 'o') c++;
    if(j && b[i][j-1] == 'o') c++;
    if(i+1 < n && b[i+1][j] == 'o') c++;
    if(j+1 < n && b[i][j+1] == 'o') c++;

    return c;
}

int main() {

    cin >> n;

    FOR(i,0,n)
        cin >> b[i];

    FOR(i,0,n) {
        FOR(j,0,n) {
            //cout << i << ", " << j << ": " << count(i, j) << endl;
            if(count(i, j) & 1) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}
