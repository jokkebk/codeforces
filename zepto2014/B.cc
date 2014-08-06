#include <iostream>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)

int main() {
    vector<int> seen;
    char str[2001];
    int n, m, k, pos;

    cin >> n >> m >> k;

    seen.resize(m);

    FOR(y,0,n) {
        cin >> str;
        FOR(x,0,m) {
            int pos = -1;

            switch(str[x]) {
                case 'U': if(y + 1 & 1) pos = x; break;
                case 'L': pos = x - y; break;
                case 'R': pos = x + y; break;
            }

            if(pos >= 0 && pos < m) seen[pos]++;
        }
    }

    for(int v : seen) cout << v << " ";

    return 0;
}
