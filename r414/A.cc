#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    int a, b, c, n, x, s = 0;

    cin >> a >> b >> c >> n;

    for(int i=0; i<n; i++) {
        cin >> x;
        if(x > b && x < c) s++;
    }

    cout << s << endl;
}
