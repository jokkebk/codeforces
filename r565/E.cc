#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> e(n);
        while(m--) {
            int u, v;
            cin >> u >> v;
            e[u-1].push_back(v-1);
            e[v-1].push_back(u-1);
        }

        vector<bool> seen(n);
        vector<int> s[2];
        vector<pair<int,int>> q(1, {0,0});
        while(q.size()) {
            int v, j;
            tie(v, j) = q.back();
            q.pop_back();
            if(seen[v]) continue; // been here
            seen[v] = true;
            s[j].push_back(v);
            for(int i : e[v]) q.push_back({i, j^1});
        }

        vector<int> & ans = (s[0].size() < s[1].size() ? s[0] : s[1]);
        cout << ans.size() << endl;
        for(int v : ans) cout << v+1 << " "; cout << endl;
    }
}
