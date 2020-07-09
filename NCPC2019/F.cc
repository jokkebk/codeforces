#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;

int main() {
    int n, a;

    cin >> n;

    vector<int> p(n);
    vector<LL> fmin(n), fmax(n);

    for(int i=1; i<n; i++) cin >> p[i]; p[i]--; // zero-based indexing

    for(int i=0; i<n; i++) {
        cin >> a;
        fmin[i] = a ? a : 1; // minimum flow
    }

}
