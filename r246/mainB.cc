#include <iostream>

using namespace std;

#define N 100000

int main() {
    int n, home[N], away[N], colors[N+1], i;

    cin >> n;

    for(i=1; i<=N; i++)
        colors[i] = 0;

    for(i=0; i<n; i++) {
        cin >> home[i] >> away[i];
        colors[home[i]]++;
    }

    for(i=0; i<n; i++)
        cout << (n-1 + colors[away[i]]) << " "
            << (n-1 - colors[away[i]]) << endl;

    return 0;
}
