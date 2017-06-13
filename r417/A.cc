#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    int c[4] = {0, 0, 0, 0}, p[4], l, s, r;

    for(int i=0; i<4; i++) {
        cin >> l >> s >> r >> p[i];
        c[(i+0)%4] |= l | s | r;
        c[(i+1)%4] |= r;
        c[(i+2)%4] |= s;
        c[(i+3)%4] |= l;
    }

    for(int i=0; i<4; i++) {
        if(c[i] && p[i]) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
