#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    LL n, sum = 0;

    cin >> n;

    vector<LL> x(n), p = {1};

    for(int i=0; i<n; i++) {
        cin >> x[i];
        p.push_back(p.back() * 2 % M);
    }

    sort(x.begin(), x.end());

    for(int i=0; i<n-1; i++)
        sum = (sum + (x[n-i-1] - x[i]) * (p[n-i-1] - 1)) % M;

    cout << sum + (sum<0?M:0);
}
