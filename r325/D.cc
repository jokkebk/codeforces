#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

char course[3][105], garbage[105];

int main() {
    int t, n, k;

    S(t);

    FOR(X,0,t) {
        S(n); S(k);
        fgets(garbage, 104, stdin);
        FOR(i,0,3) fgets(course[i], 104, stdin), course[i][n] = '\0';

        FOR(c,0,n-1) {
            if(c%3==0) {
                FOR(i,0,3) {
                    if(course[i][c] != 's' || (course[i][c+1] != '.' && course[i][c+1] != 's')) continue;
                    course[i][c+1] = 's';
                    if(i && course[i-1][c+1] == '.') course[i-1][c+1] = 's';
                    if(i<2 && course[i+1][c+1] == '.') course[i+1][c+1] = 's';
                }
            } else {
                FOR(i,0,3) {
                    if(course[i][c] != 's' || course[i][c+1] != '.') continue;
                    course[i][c+1] = 's';
                }
            }
            //FOR(i,0,3) cout << course[i] << endl;
        }
        if(course[0][n-1] == 's' || course[1][n-1] == 's' || course[2][n-1] == 's')
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
