#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int d(int a, int b, int x, int y) {
    return ((a == x) ? 0 : 1) + ((b == y) ? 0 : 1);
}

int main() {
    int n;

    cin >> n;

    vector<int> a(n), b(n);
    set<int> v;
    int s = n, e = 0;

    for(int i=0; i<n; i++) {
        v.insert(i+1);
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
        if(a[i] != b[i]) s = min(s, i), e = max(e, i);
        else v.erase(a[i]);
    }
    
    vector<int> p(v.begin(), v.end());

    if(p.size() == 1) {
        a[s] = p[0];
    } else {
        if(d(a[s], a[e], p[0], p[1]) == 1 && d(b[s], b[e], p[0], p[1]) == 1)
            a[s] = p[0], a[e] = p[1];
        else
            a[s] = p[1], a[e] = p[0];
    }

    for(int i : a) cout << i << " "; cout << endl;
}
