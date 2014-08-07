#include <iostream>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)

int main() {
    int n, num, low = -2e9, high = 2e9;
    char s[4], ans;
    enum { LT, LE, GT, GE } type;

    cin >> n;

    REP(n) {
        cin >> s >> num >> ans;

        if(s[1] == '=')
            type = (s[0] == '<' ? LE : GE);
        else
            type = (s[0] == '<' ? LT : GT);

        if(ans == 'N') switch(type) { // reverse condition
            case LE: type = GT; break;
            case LT: type = GE; break;
            case GE: type = LT; break;
            case GT: type = LE; break;
        }

        if(type == LT) num--, type = LE;
        if(type == GT) num++, type = GE;

        if(type == LE)
            high = min(num, high);
        else
            low = max(num, low);
    }

    if(low > high)
        cout << "Impossible";
    else
        cout << low;

    return 0;
}
