#include <cstdio>
#include <cstdlib>
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

int a[2][2000001], ans=0;

//  4 2 1 3  = +2  0 +1 -3
//  4 2 3 1  = +2  0 -2  0
//  3 2 4 1  +  0  0  0  0
int main() {
    int n, t, sum=0;

    S(n);

    vector<int> pos(n), target(n);

    FOR(i,0,n) {
        S(t);
        pos[t-1] = i;
    }

    FOR(i,0,n) {
        S(t);
        int p = pos[t-1];
        target[p] = i;
    }

    bool done;
    do {
        int last_f;

        done = true;

        FOR(i,0,n) {
            if(target[i] > i) last_f = i; // going right
            else if(target[i] < i) { // going left
                a[0][ans] = i+1;
                a[1][ans++] = last_f+1;
                sum += i-last_f;
                done = false;
                SWAP(target[i], target[last_f]);
                if(target[i] == i) break;
                else last_f = i; // continue moving this right
            }
        }
    } while(!done);

    printf("%d\n%d\n", sum, ans);
    FOR(i,0,ans) printf("%d %d\n", a[0][i], a[1][i]);

    return 0;
}
