#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)

int main() {
    vector< tuple<int,int,int> > groups;
    vector< pair<int,int> > ans;
    map< int,vector<int> > tables;
    int n, c, p, k, r, m = 0, s = 0;

    cin >> n;
    FOR(i,0,n) {
        cin >> c >> p;
        groups.push_back(make_tuple(p,c,i));
    }
    sort(groups.rbegin(), groups.rend());

    cin >> k;
    FOR(i,0,k) {
        cin >> r;
        tables[r].push_back(i);
    }

    for(auto t : groups) {
        auto table = tables.upper_bound(get<1>(t)-1);

        if(table == tables.end()) continue; // no room

        int tabnum = table->second.back(); table->second.pop_back();

        if(table->second.empty()) tables.erase(table);

        ans.push_back(make_pair(get<2>(t)+1, tabnum+1));

        s += get<0>(t), m++;
    }

    cout << m << " " << s << endl;
    for(auto pa : ans) cout << pa.first << " " << pa.second << endl;

    return 0;
}
