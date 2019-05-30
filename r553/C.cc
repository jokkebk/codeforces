#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<LL> x(n);
    for(int i=0; i<n; i++) cin >> x[i];

    vector<LL> P(m);
    for(int i=0; i<m; i++) cin >> P[i];
    set<LL> ps(P.begin(), P.end());

    for(int i=1; i<n; i++) {
        LL d = x[i] - x[i-1];
        for(auto it = ps.begin(); it != ps.end(); ) {
            if(d % *it) it = ps.erase(it);
            else it++;
        }
    }

    //for(int v : ps) cout << v << " "; cout << endl;

    if(ps.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl << x[0] << " ";
        cout << distance(P.begin(), find(P.begin(), P.end(), *ps.begin())) + 1 << endl;
        //if(x[0] == 222) cout << *ps.begin() << endl;
    }
}
