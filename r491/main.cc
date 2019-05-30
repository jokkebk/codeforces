#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int eat(LL n, LL k) {
    int i = 0;
    LL petya = 0;

    while(n > 0) {
        petya += min(n, k);
        n -= min(n, k);
        n -= n/10;
        //cout << "Round " << ++i << " " << n << " left." << endl;
    }

    return petya;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LL n;

    cin >> n;

    cout << "Petya got " << eat(n, 1) << endl; 
    cout << "Petya got " << eat(n, 2) << endl; 
    cout << "Petya got " << eat(n, 3) << endl; 
}
