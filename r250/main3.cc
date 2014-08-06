#include <iostream>

using namespace std;

int main() {
    int pieces, conns, piece[1000], a, b, res = 0;

    cin >> pieces >> conns;

    for(int i=0; i<pieces; i++)
        cin >> piece[i];

    for(int i=0; i<conns; i++) {
        cin >> a >> b;
        res += min(piece[--a], piece[--b]);
    }

    cout << res << endl;

    return 0;
}
