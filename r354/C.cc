#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define Inf 1000000007

int n, k;
string s;

int best(char ok) {
    int ch = k, begin=0, end=0, best=0;

    while(end < s.length()) {
        if(s[end] == ok || ch) { // can expand
            if(s[end++] != ok) ch--;
        } else if(s[begin++] != ok) ch++;
        best = max(best, end-begin);
    }

    return max(best, end-begin);
}

int main() {
    cin >> n >> k >> s;

    cout << max(best('a'), best('b')) << endl;

    return 0;
}
