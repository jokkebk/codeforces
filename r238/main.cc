#include <cstdio>

#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define S(x) scanf("%d", &x)
#define P(x) printf("%d", x)

int main() {
    int n, d[1000], q, t, sum = 0;

    S(n);

    FOR(i,0,n) {
        S(d[i]);
        sum ^= d[i];
        if(i+1 < n) FOR(j,0,n) S(t);
    }

    S(q);

    FOR(i,0,q) {
        S(t);
        if(t == 3) P(sum);
        else S(t), sum ^= 1;
    }
}
