#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef long long LL;

int n, p;
char s[1005], s2[1005], last;

// Try either increment or create valid tolerable string
bool t(int pos, bool inc) {
    char p1 = (pos > 0 ? s[pos-1] : 0), p2 = (pos > 1 ? s[pos-2] : 0);

    if(pos >= n) return !inc; // success if no need to increment

    if(inc) { // try find minimum increment
        s2[pos] = s[pos];

        if(s2[pos] != p1 && s2[pos] != p2 && t(pos+1, inc))
            return true; // no need to increment this

        s2[pos]++; // try with next
    } else { // try create minimum tolerable string
        s2[pos] = 'a';
    }

    if(s2[pos] == p1 || s2[pos] == p2) s2[pos]++;
    if(s2[pos] == p1 || s2[pos] == p2) s2[pos]++;

    return s2[pos] <= last && t(pos+1, false); // evaluate success
}

int main() {
    cin >> n >> p >> s;
    last = 'a' + p - 1;
    s2[n] = 0;

    if(t(0, true))
        cout << s2;
    else
        cout << "NO";

    return 0;
}
