#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, x, i, v;
    vector<long long> c;
    long long total = 0;

    cin >> n >> x;

    for(i=0; i<n; i++) {
        cin >> v;
        c.push_back(v);
    }

    sort(c.begin(), c.end());

    for(auto it = c.begin(); it != c.end(); it++) {
        total += *it * x;
        if(x > 1)
            x--;
    }

    cout << total;

    return 0;
}
