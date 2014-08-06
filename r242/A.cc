#include <iostream>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    char s[205], from, to;
    int n, up = 0;

    cin >> n >> s;

    FOR(i,0,n) if(s[i] == 'X') up++;

    if(up < n/2)
        from = 'x', to = 'X', up = n/2 - up;
    else
        from = 'X', to = 'x', up = up - n/2;

    cout << up << endl;

    for(int i=0; i<n && up; ++i) {
        if(s[i] != from) continue;
        s[i] = to;
        up--;
    }

    cout << s << endl;

    return 0;
}
