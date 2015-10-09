#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))

char s[300005];

int main() {
    int n, m, p, f=0;
    char ch;

    S(n); S(m);
    REP(2) fgets(s+1, 300003, stdin); // first consumes previous newline
    s[0] = s[n+1] = 'x'; // make everything easier

    FORE(i,2,n) if(s[i] == '.' && s[i-1] == '.') f++;

    REP(m) {
        scanf("%d %c", &p, &ch);
        
        if(ch == '.') {
            if(s[p] == '.') {
                // no change
            } else if(s[p-1] != '.' && s[p+1] != '.') {
                // no change
            } else if(s[p-1] == '.' && s[p+1] == '.') {
                f += 2;
            } else f++;
        } else {
            if(s[p] != '.') {
                // no change
            } else if(s[p-1] != '.' && s[p+1] != '.') {
                // no change
            } else if(s[p-1] == '.' && s[p+1] == '.') {
                f -= 2;
            } else f--;
        }
        s[p] = ch;
        cout << f << endl;
    }

    return 0;
}
