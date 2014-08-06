#include <iostream>

using namespace std;

typedef long long LL;

LL le(LL n, LL m, LL k) { // amount of numbers less or equal than k
    LL num = (k / m) * m;

    for(LL i = k/m+1; i <= n && i <= k; ++i)
        num += k / i;

    return num;
}

int main() {
    LL n, m, k, a = 1, b;

    cin >> n >> m >> k;

    for(b = n * m; k > 1 && a + 1 < b;) {
        if(le(n, m, (a+b)/2) < k)
            a = (a+b)/2;
        else
            b = (a+b)/2;
    }

    cout << ((k > 1) ? b : 1);

    return 0;
}
