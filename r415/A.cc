#include <iostream>

using namespace std;

int main() {
    int n, k, a, sum=0;

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> a;
        sum += a;
    }

    int deficit = n*k - sum;

    cout << max(0, deficit*2 - n) << endl;
}
