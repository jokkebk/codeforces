#include <iostream>
#include <vector>

using namespace std;

#define N 200000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ok(N+2);
    int n, k, q, l, r;

    cin >> n >> k >> q;

    while(n--) {
        cin >> l >> r;
        ok[l]++; ok[r+1]--;
    }

    for(int i=1; i<=N; i++) ok[i] += ok[i-1]; // Cumulative ranges
    for(int i=1; i<=N; i++) ok[i] = ok[i]>=k; // Mark OKs with one
    for(int i=1; i<=N; i++) ok[i] += ok[i-1]; // Cumulative OKs

    while(q--) {
        cin >> l >> r;
        cout << ok[r]-ok[l-1] << endl;
    }
}
