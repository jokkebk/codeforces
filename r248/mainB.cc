#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    int n, m, t, l, r;
    LL val, sum = 0;
    vector<LL> v, vs, us;

    cin >> n;

    v.reserve(n);
    vs.reserve(n);
    us.reserve(n);

    FOR(i,0,n) {
        cin >> val;
        sum += val;
        v.push_back(val);
        vs.push_back(sum);
        //cout << i << ": " << val << " and " << sum << endl;
    }

    sort(v.begin(), v.end());

    sum = 0;
    for(auto it = v.begin(); it != v.end(); it++) {
        val = *it;
        sum += val;
        us.push_back(sum);
        //cout << val << " and " << sum << endl;
    }

    cin >> m;

    FOR(i, 0, m) {
        cin >> t >> l >> r;
        if(t == 1) {
            sum = vs[--r];
            if(--l) sum -= vs[l-1];
        } else {
            sum = us[--r];
            if(--l) sum -= us[l-1];
        }
        cout << sum << endl;
    }

    return 0;
}
