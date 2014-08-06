#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

double C(int n, int k) {
    if (k > n) return 0.0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1.0;

    double result = (double)n;
    for(int i = 2; i <= k; ++i ) {
        result *= (double)(n-i+1);
        result /= (double)i;
    }
    return result;
}

double Pr(int n, int k, double p) { // binom. prob for k successes with n tries
    return C(n, k) * pow(p, k) * pow(1.0 - p, n - k);
}


char *bin2str(int n) { // fake utility function
    static char s[9] = "00001111";
    FOR(i,0,8) s[7-i] = '0' + ((n>>i) & 1);
    return s;
}

// bit fields / bitfields
typedef union {
    struct State { unsigned int low8 : 8, zeros : 8, ones : 6, rest : 10; } st;
    uint32_t i;
} Index;

char *bin2str(unsigned int n) { // fake utility function
    static char str[36] = "00001111 00001111 00001111 00001111";
    char *s = str+34;

    for(unsigned int i=0; i<32; ++i) {
        *s-- = '0' + ((n>>i) & 1);
        if((i & 7) == 7) s--; // "add" space
    }
    return str;
}

