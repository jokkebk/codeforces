#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 200000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector< vector<int> > g(n, vector<int>(m, 0));

    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> g[i][j];

    bool inv = n > m;
    
    if(inv) {
        vector< vector<int> > g2(m, vector<int>(n, 0));
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) g2[j][i] = g[i][j];
        swap(n,m);
        g = g2;
    }

    vector<int> csum(m), ans;

    for(int j=0; j<m; j++) for(int i=0; i<n; i++) csum[j] += g[i][j];

    int sm = *min_element(csum.begin(), csum.end());
    for(int j=0; j<m; j++) {
        while(csum[j] > sm) {
            ans.push_back(j+1);
            for(int i=0; i<n; i++) g[i][j]--;
            csum[j] -= n;
        }

        if(csum[j] < sm) {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(g[i][j] != g[i][0]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int ops = ans.size();
    for(int i=0; i<n; i++) ops += g[i][0];

    cout << ops << endl;
    for(int i : ans) cout << ((inv) ? "row " : "col ") << i << endl;
    for(int i=0; i<n; i++) while(g[i][0]--) cout << ((inv) ? "col " : "row ") << (i+1) << endl;
}
