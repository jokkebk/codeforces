#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, ring;
int n, m, w;

bool possible(int target) {
    int days = m, level = 0, need;

    for(int i=0; i<n && days >= 0; ++i) {
        if(i >= w) level -= ring[i%w];
        need = max(0, target - (a[i] + level));
        level += need, days -= need;
        ring[i%w] = need;
    }

    return (days >= 0);
}

int main() {
    cin >> n >> m >> w;
    a.resize(n), ring.resize(w);
    for(int i=0; i<n; ++i) cin >> a[i];

    int level = *min_element(a.begin(), a.end());

    for(int add = 1 << 16; add; add >>= 1)
        if(possible(level+add)) level += add;

    cout << level; // low always possible

    return 0;
}
