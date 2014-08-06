#include <iostream>

using namespace std;

int main() {
    int n, m, i, a, b, c, x[501];
    double best = 0.0;

    cin >> n >> m;

    for(i=1; i<=n; i++)
        cin >> x[i];

    for(i=0; i<m; i++) {
        cin >> a >> b >> c;
        best = max(best, (double)(x[a] + x[b]) / c);
    }

    cout.precision(20);
    cout << best << endl;

    return 0;
}
