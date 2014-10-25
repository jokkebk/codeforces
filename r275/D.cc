#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

int main() {
    vector<int> ors[32], lastZero[32], a, l, r, q;

    int n, m;

    cin >> n >> m;

    a.resize(n+1); // use 1..n indexing

    FOR(i,0,32)
        ors[i].resize(n+2), lastZero[i].resize(n+1);

    l.resize(m), r.resize(m), q.resize(m); // 0..31

    FOR(p,0,m) { // read constraints
        cin >> l[p] >> r[p] >> q[p];
        FOR(i,0,32)
            if((q[p]>>i) & 1) // mark ors on relevant lines
                ors[i][l[p]]++, ors[i][r[p]+1]--;
    }

    FOR(i,0,32) { // mark last zeros
        int cur = 0, zero = 0;
        FORE(p,1,n) {
            cur += ors[i][p];

            if(cur == 0)
                zero = p;
            else
                a[p] |= 1 << i; // potential interesting array

            lastZero[i][p] = zero;
            //cout << zero << " ";
        }
        //cout << endl;
    }

    FOR(p,0,m) { // verify constraints
        FOR(i,0,32) {
            if((q[p]>>i) & 1) continue; // no check needed

            if(lastZero[i][r[p]] < l[p]) { // ANDing returns 1
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    FORE(p,1,n) cout << a[p] << " ";

    return 0;
}
