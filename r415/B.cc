#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    LL n, f, sell = 0, k, l;
    vector<LL> pot;

    cin >> n >> f;

    for(int i=0; i<n; i++) {
        cin >> k >> l;
        sell += min(k, l);
        pot.push_back(min(2*k, l) - min(k, l));
    }

    sort(pot.rbegin(), pot.rend());

    for(int i=0; i<f; i++) sell += pot[i];

    cout << sell << endl;
}
