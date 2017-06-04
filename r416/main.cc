#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    int n, m, l, r, x;

    cin >> n >> m;

    vector<int> p(n+1);

    for(int i=1; i<=n; i++) cin >> p[i];

    while(m--) {
        cin >> l >> r >> x;
        for(int j=l; j<=r; j++) if(p[j] < p[x]) l++;
        cout << ((l == x) ? "Yes" : "No") << endl;
    }
}
