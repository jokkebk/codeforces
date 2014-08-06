#include <iostream>

using namespace std;

int main() {
    int n, k, v, m = 0;

    cin >> n >> k;

    while(n--) {
        cin >> v;
        if(v+k <= 5) m++;
    }

    cout << m/3 << endl;

    return 0;
}
